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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MAXN=200000;
const int MAXQ=200000;
const int MAXS=4*MAXN;

int n,nq;
char s[MAXN+1];
int qidx[MAXQ]; char qval[MAXQ];
int ans[MAXQ+1];

int cur[MAXN];
map<char,int> mp;
set<int> who[3];

int sval[MAXS][3];

void sinit(int x,int l,int r) {
	if(l==r) {
		REP(i,3) sval[x][i]=0; sval[x][cur[l]]=1;
	} else {
		int m=l+(r-l)/2;
		sinit(2*x+1,l,m); sinit(2*x+2,m+1,r);
		REP(i,3) sval[x][i]=sval[2*x+1][i]+sval[2*x+2][i];
	}
}

void supd(int x,int l,int r,int IDX) {
	if(l==r) {
		REP(i,3) sval[x][i]=0; sval[x][cur[l]]=1;
	} else {
		int m=l+(r-l)/2;
		if(IDX<=m) supd(2*x+1,l,m,IDX); else supd(2*x+2,m+1,r,IDX);
		REP(i,3) sval[x][i]=sval[2*x+1][i]+sval[2*x+2][i];
	}
}

int sget(int x,int l,int r,int L,int R,int KIND) {
	if(L<=l&&r<=R) {
		return sval[x][KIND];
	} else {
		int m=l+(r-l)/2,ret=0;
		if(L<=m) ret+=sget(2*x+1,l,m,L,R,KIND);
		if(m+1<=R) ret+=sget(2*x+2,m+1,r,L,R,KIND);
		return ret;
	}
}

int getnr(int l,int r,int kind) {
	//int ret=0; FOR(i,l,r) if(cur[i]==kind) ++ret; return ret;
	return sget(0,0,n-1,l,r-1,kind);
}

int calc(int kind) {
	//printf("calc(%d)\n",kind);
	int win=(kind+1)%3,lose=(kind+2)%3;
	int npref1=0,nsuff1=0,npref2=0,nsuff2=0;
	if(SZ(who[win])!=0) {
		int fst=*who[win].begin();
		int lst=*prev(who[win].end());
		npref1=lst+1;
		nsuff2=n-fst;
	}
	if(SZ(who[lose])!=0) {
		int fst=*who[lose].begin();
		int lst=*prev(who[lose].end());
		npref2=fst+1;
		nsuff1=n-lst;
	} else {
		npref2=n;
		nsuff1=n;
	}
	vector<pair<int,int>> e;
	if(npref1+nsuff1>=n) e.PB(MP(0,+1)),e.PB(MP(n,-1)); else e.PB(MP(0,+1)),e.PB(MP(npref1,-1)),e.PB(MP(n-nsuff1,+1)),e.PB(MP(n,-1));
	if(npref2+nsuff2>=n) e.PB(MP(0,+1)),e.PB(MP(n,-1)); else e.PB(MP(0,+1)),e.PB(MP(npref2,-1)),e.PB(MP(n-nsuff2,+1)),e.PB(MP(n,-1));
	sort(e.begin(),e.end());
	int cnt=0,ret=0;
	for(int l=0,r=l;l<SZ(e);l=r) {
		int at=e[l].first; if(at==n) break;
		while(r<SZ(e)&&e[r].first==at) ++r;
		int to=r<SZ(e)?e[r].first:n;
		FOR(i,l,r) cnt+=e[i].second;
		//printf("\t%d..%d = %d\n",at,to,cnt);
		if(cnt==2) {
			ret+=getnr(at,to,kind);
		}
	}
	//printf("calc(%d)=%d [%d,%d] [%d,%d]\n",kind,ret,npref1,nsuff1,npref2,nsuff2);
	return ret;
}

void mod(int idx,int val) {
	who[cur[idx]].erase(idx);
	cur[idx]=val;
	who[cur[idx]].insert(idx);
	supd(0,0,n-1,idx);
}

void solve() {
	mp.clear(); mp['P']=0; mp['R']=1; mp['S']=2;
	REP(i,3) who[i].clear();
	REP(i,n) cur[i]=mp[s[i]],who[cur[i]].insert(i);
	REPE(i,nq) ans[i]=-1;
	sinit(0,0,n-1);
	REPE(i,nq) {
		ans[i]=0; REP(j,3) ans[i]+=calc(j);
		if(i!=nq) mod(qidx[i],mp[qval[i]]);
	}
}

void run() {
	scanf("%d%d",&n,&nq);
	scanf("%s",s);
	REP(i,nq) scanf("%d %c",&qidx[i],&qval[i]),--qidx[i];
	solve();
	REPE(i,nq) printf("%d\n",ans[i]);
}

void stress() {
	n=MAXN,nq=MAXQ;
	REP(i,n) s[i]="RPS"[rand()%3]; s[n]='\0';
	REP(i,nq) qidx[i]=rand()%n,qval[i]="RPS"[rand()%3];
	solve();
}

int main() {
	run();
	//stress();
	return 0;
}