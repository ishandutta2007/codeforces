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
#include <list>  
#include <climits>
#include <cassert>
#include <ctime>
#include <cstring>
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
ll gcd(ll u, ll v) { while ( v != 0) { ll r = u % v; u = v; v = r; } return u; }

int n,nq;
int a[100000];
int q[100000][3];

int v[200000],nv;
int getid(int x) { int l=0,h=nv; /* [l..h) */ while(l+1<h) { int m=l+(h-l)/2; if(v[m]<=x) l=m; else h=m; } return l; }

int cnt[51][200000]; // cnt[i][j] == #times the number j occurs in the first i blocks on the first row
int frq[51][100001]; // frq[i][j] == #numbers that occur at least j times in the first i blocks on the first row

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	scanf("%d",&nq);
	REP(i,nq) scanf("%d%d%d",&q[i][0],&q[i][1],&q[i][2]);

	nv=0;
	REP(i,n) v[nv++]=a[i];
	REP(i,nq) if(q[i][0]==1) v[nv++]=q[i][1];
	sort(v,v+nv); int nnv=0; REP(i,nv) if(nnv==0||v[i]!=v[nnv-1]) v[nnv++]=v[i]; nv=nnv;
	REP(i,n) a[i]=getid(a[i]);
	REP(i,nq) if(q[i][0]==1) q[i][1]=getid(q[i][1]);

	int nb=50,len=(n+nb-1)/nb;
	memset(cnt,0,sizeof(cnt));
	memset(frq,0,sizeof(frq));
	REP(b,nb) {
		REP(i,nv) cnt[b+1][i]=cnt[b][i];
		REPE(i,n) frq[b+1][i]=frq[b][i];
		FOR(i,b*len,min(n,(b+1)*len)) {
			++cnt[b+1][a[i]];
			++frq[b+1][cnt[b+1][a[i]]];
		}
	}

	REP(qi,nq) {
		if(q[qi][0]==1) {
			int x=q[qi][1],c=q[qi][2]-1,b=c/len;
			FORE(bb,b+1,nb) {
				--frq[bb][cnt[bb][a[c]]];
				--cnt[bb][a[c]];
			}
			a[c]=x;
			FORE(bb,b+1,nb) {
				++cnt[bb][a[c]];
				++frq[bb][cnt[bb][a[c]]];
			}
		} else {
			int r=q[qi][1]-1,c=q[qi][2]-1,b=c/len;
			int v0=a[c];
			int v1=cnt[b][v0];
			FORE(i,b*len,c) if(a[i]==v0) ++v1;
			int v2=frq[b][v1];
			FORE(i,b*len,c) if(++cnt[b][a[i]]==v1) ++v2;
			FORE(i,b*len,c) --cnt[b][a[i]];
			printf("%d\n",r==0?v[v0]:r%2==1?v1:v2);
		}
	}
}

int main() {
	run();
	return 0;
}