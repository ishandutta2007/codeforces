#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <cstring>
#include <list>  
#include <cassert>
#include <climits>
#include <bitset>
using namespace std;  

#define PB push_back  
#define MP make_pair  
#define SZ(v) ((int)(v).size())  
#define FOR(i,a,b) for(int i=(a);i<(b);++i)  
#define REP(i,n) FOR(i,0,n)  
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)  
#define REPE(i,n) FORE(i,0,n)  
#define FORSZ(i,a,v) FOR(i,a,SZ(v))  
#define REPSZ(i,v) REP(i,SZ(v))  
typedef long long ll;  
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

//abc|ab|ab|ab|ab|ab|aaaaaaabbbbbaaaaaaaaaaa|ab|ab|cab|
//  4 44 44 33 22 11                         11 22 333
  
const int MAXN=100000;
const int MAXC=26;
  
struct OneSideSolver {
	char s[MAXN+1]; int n;
	int nxt[MAXN+1][MAXC]; // nxt[i][c] = first index of 'a'+c >= i
	int who[MAXN][MAXC]; // who[i][c] = index of cth character <= i
	pair<int,int> step[MAXN][MAXC]; // in one step go from (i,c) -> step[i][c]
	int diffsteps[MAXN][MAXC]; // diffsteps[i][c] = number of steps to get to higher c
	vector<pair<int,ll>> jump[MAXN][MAXC]; // jump[i][c][k] = after (1<<k) steps, the end position and its cost
	
	pair<int,int> normalize(int l,int r) {
		int j=-1; while(j+1<MAXC&&who[r][j+1]>=l) ++j; return MP(r,j);
	}
	void calc() {
		REP(c,MAXC) nxt[n][c]=n;
		for(int i=n-1;i>=0;--i) { REP(c,MAXC) nxt[i][c]=nxt[i+1][c]; nxt[i][s[i]-'a']=i; }
		REP(i,n) {
			REP(j,MAXC) who[i][j]=-1;
			int seen=0,seencnt=0;
			{ int c=s[i]-'a'; seen|=1<<c; who[i][seencnt++]=i; }
			if(i-1>=0) REP(j,MAXC) if(who[i-1][j]!=-1) { 
				int c=s[who[i-1][j]]-'a';
				if((seen&(1<<c))==0) { seen|=1<<c; who[i][seencnt++]=who[i-1][j]; }
			}
		}
		REP(i,n) {
			pair<int,int> to=MP(-1,-1);
			REP(j,MAXC) {
				if(who[i][j]==-1) break;
				int c=s[who[i][j]]-'a';
				to.first=min(n-1,max(to.first,nxt[i+1][c]));
				while(to.second+1<MAXC&&who[to.first][to.second+1]>=who[i][j]) ++to.second;
				step[i][j]=to;				
			}
		}
		for(int i=n-1;i>=0;--i) REP(j,MAXC) {
			if(who[i][j]==-1) break;
			pair<int,int> to=step[i][j];
			diffsteps[i][j]=to.first==i?0:1+(to.second==j?diffsteps[to.first][to.second]:0);
			jump[i][j].clear();
			if(diffsteps[i][j]!=0) {
				jump[i][j].PB(MP(to.first,to.first-i));
				for(int k=1;(1<<k)<=diffsteps[i][j];++k) {
					pair<int,ll> a=jump[i][j][k-1],b=jump[a.first][j][k-1];
					jump[i][j].PB(MP(b.first,a.second+b.second+(ll)(1<<(k-1))*(b.first-a.first)));
				}
			}
		}
	}
	pair<int,ll> go(pair<int,int> state,int steps) {
		int actual=min(steps,diffsteps[state.first][state.second]);
		pair<int,ll> ret=MP(state.first,0LL);
		int sofar=0;
		for(int k=SZ(jump[ret.first][state.second])-1;k>=0;--k) if(actual&(1<<k)) {
			pair<int,ll> cur=jump[ret.first][state.second][k];
			ret.second+=cur.second+(ll)sofar*(cur.first-ret.first);
			ret.first=cur.first;
			sofar+=1<<k;
		}
		assert(sofar==actual);
		if(actual<steps) assert(step[ret.first][state.second].first==ret.first);
		//printf("\t\tgo(%d,%d,%d)->(%d,%lld) [actual=%d]\n",state.first,state.second,steps,ret.first,ret.second,actual);
		//if(SZ(jump[state.first][state.second])>=1) printf("\t\t\t(%d,%lld)\n",jump[state.first][state.second][0].first,jump[state.first][state.second][0].second);
		return ret;
	}
};

int n;
char s[MAXN+1];

OneSideSolver fwd,rev;

ll solve() {
	//printf("%s\n",s);
	fwd.n=n; REP(i,n) fwd.s[i]=s[i]; fwd.s[n]='\0';
	rev.n=n; REP(i,n) rev.s[n-i-1]=s[i]; rev.s[n]='\0';
	fwd.calc();
	rev.calc();
	ll ret=0;
	REP(i,n) {
		pair<int,int> fwdstate=fwd.normalize(i,i);
		pair<int,int> revstate=rev.normalize(n-i-1,n-i-1);
		int prevsteps=0;
		while(fwdstate.first!=n-1||revstate.first!=n-1) {
			int fwdsteps=fwd.diffsteps[fwdstate.first][fwdstate.second],revsteps=rev.diffsteps[revstate.first][revstate.second];
			int steps=min(fwdsteps==0?INT_MAX:fwdsteps,revsteps==0?INT_MAX:revsteps);
			//printf("[%d..#%d] [#%d..%d] -> (%d,%d) -> %d\n",n-revstate.first-1,revstate.second+1,fwdstate.second+1,fwdstate.first,fwdsteps,revsteps,steps);
			assert(steps>0&&steps!=INT_MAX);
			pair<int,ll> fwdres=fwd.go(fwdstate,steps);
			pair<int,ll> revres=rev.go(revstate,steps);
			//printf("\trevres=(%d,%lld) fwdres=(%d,%lld)\n",revres.first,revres.second,fwdres.first,fwdres.second);
			ret+=fwdres.second+revres.second+(ll)prevsteps*(fwdres.first-fwdstate.first+revres.first-revstate.first);
			fwdstate=fwd.normalize(n-revres.first-1,fwdres.first);
			revstate=rev.normalize(n-fwdres.first-1,revres.first);
			prevsteps+=steps;
		}
	}
	return ret;
}

void run() {
	scanf("%s",s); n=strlen(s);
	printf("%lld\n",solve());
}

void stress() {
	int mxn=100,mxalph=26;
	REP(rep,100000) {
		n=rand()%mxn+1; int alph=rand()%mxalph+1; REP(i,n) s[i]='a'+rand()%alph; s[n]='\0';
		//printf("%s\n",s);
		ll have=solve();
		if(rep%1000==0) printf(".");
	}
}

void stresslarge() {
	int mxalph=26;
	REP(rep,100) {
		n=MAXN/1; int alph=rand()%mxalph+1; REP(i,n) s[i]='a'+rand()%alph; s[n]='\0';
		ll have=solve();
		printf(".");
	}
}

int main() {
	run();
	//stress();
	//stresslarge();
	return 0;
}