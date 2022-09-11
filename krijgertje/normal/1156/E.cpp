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

int n;
int p[MAXN];

int bsz,nb;
int val[MAXN];
vector<int> boff;
vector<vector<int>> bcnt;

int stck[MAXN],nstck;

void push(int b) {
	int l=b*bsz,r=min(n-1,l+bsz-1);
	FORE(i,l,r) --bcnt[b][val[i]-boff[b]],val[i]+=boff[b];
	boff[b]=0;
	//printf("pushed(%d..%d):",l,r); FORE(i,l,r) printf(" %d",val[i]); puts("");
}
void pull(int b) {
	int l=b*bsz,r=min(n-1,l+bsz-1);
	FORE(i,l,r) ++bcnt[b][val[i]-boff[b]];
	//printf("pulled(%d..%d):",l,r); REPE(i,n) if(bcnt[b][i]>0) printf(" %d=%d",i,bcnt[b][i]); puts("");
}

void mod(int l,int r,int by) {
	//printf("mod(%d..%d,%d)\n",l,r,by);
	if(l<=r&&l%bsz!=0) {
		int b=l/bsz; push(b);
		while(l<=r&&l%bsz!=0) val[l++]+=by;
		pull(b);
	}
	if(l<=r&&r%bsz!=bsz-1) {
		int b=r/bsz; push(b);
		while(l<=r&&r%bsz!=bsz-1) val[r--]+=by;
		pull(b);
	}
	if(l<=r) {
		int bl=l/bsz,br=r/bsz;
		//printf("blocks %d..%d\n",bl,br);
		FORE(b,bl,br) boff[b]+=by;
	}
}

int cnt(int want) {
	//printf("cnt(%d)\n",want);
	int ret=0;
	REP(b,nb) if(want>=boff[b]) ret+=bcnt[b][want-boff[b]]; 
	//printf("=%d\n",ret);
	return ret;
}

ll solve() {
	bsz=sqrt(1.0*n);
	nb=(n+bsz-1)/bsz;
	boff=vector<int>(nb,0);
	bcnt=vector<vector<int>>(nb,vector<int>(n+1,0));
	REP(i,n) val[i]=0,++bcnt[i/bsz][val[i]-boff[i/bsz]];
	nstck=0;
	ll ret=0;
	REP(i,n) {
		while(nstck>0&&p[i]>p[stck[nstck-1]]) {
			int l=nstck==1?0:stck[nstck-2]+1,r=stck[nstck-1]; --nstck;
			mod(l,r,p[i]-p[r]);
		}
		stck[nstck++]=i;
		ret+=cnt(p[i]);
	}
	return ret;
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&p[i]);
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}