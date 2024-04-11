#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
#include <climits>
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
typedef unsigned long long ull;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN=5000;
const int MAXK=12;

char s[MAXN+1]; int n,k;

//int id[MAXN+1][1<<MAXK];
//pair<int,int> opt[MAXN+1][1<<MAXK];

int id[2][MAXN+1],nid[2];
pair<int,int> opt[MAXN+1];

int act[MAXN+1][1<<MAXK];
pair<pair<int,int>,int> o[MAXN+1]; int no;

int head[26][MAXN+1],nxt[MAXN+1];


char ret[MAXN+1]; int nret;

void solve() {
	k=0; while((2<<k)<=n) ++k;
	//printf("k=%d\n",k);
	
	int at=0;
	REPE(i,n) id[at][i]=-1;
	REPE(i,n) { int mask=n-i; if(mask<(1<<k)) id[at][i]=0; }
	nid[at]=1;
	FORE(len,1,n) {
		int to=1-at;
		REPE(i,n) id[to][i]=-1;
		REP(a,26) REP(b,nid[at]) head[a][b]=-1;
		no=0;
		for(int i=n;i>=0;--i) {
			int mask=n-i-len; if(mask<0||mask>=(1<<k)) continue;
			opt[i]=MP(s[i]-'a',id[at][i+1]); act[i][mask]=-1;
			REP(j,k) if(mask&(1<<j)) if(opt[i+(1<<j)]<opt[i]) opt[i]=opt[i+(1<<j)],act[i][mask]=j;
			nxt[i]=head[opt[i].first][opt[i].second]; head[opt[i].first][opt[i].second]=i;
			//o[no++]=MP(opt[i],i);
		}
		//sort(o,o+no);
		//nid[to]=0; REP(i,no) if(i==0||o[i].first!=o[i-1].first) id[to][o[i].second]=nid[to]++; else id[to][o[i].second]=nid[to]-1;
		nid[to]=0; REP(a,26) REP(b,nid[at]) if(head[a][b]!=-1) { for(int x=head[a][b];x!=-1;x=nxt[x]) id[to][x]=nid[to]; ++nid[to]; }
		at=to;
	}
	//REPE(i,n) { printf("%d:",i); REP(mask,1<<k) printf(" %d",id[i][mask]); puts(""); }

	nret=0; int ci=0,cmask=(1<<k)-1; while(ci!=n) { if(act[ci][cmask]==-1) { ret[nret++]=s[ci]; ++ci; } else { int j=act[ci][cmask]; ci+=1<<j; cmask^=1<<j; } } ret[nret]='\0';
}

void run() {
	scanf("%s",s); n=strlen(s); 
	solve();
	printf("%s\n",ret);
}

void stress() {
	n=MAXN; REP(i,n) s[i]='a'+rand()%26; s[n]='\0';
	clock_t start=clock();
	solve();
	printf("Took: %.9lf\n",1.0*(clock()-start)/CLOCKS_PER_SEC);
}

int main() {
	run();
	//stress();
	return 0;
}