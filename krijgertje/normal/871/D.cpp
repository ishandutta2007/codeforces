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

const int MAXN=10000000;

int n;
int pmn[MAXN+1];
int phi[MAXN+1];

bool isc[MAXN+1];
int csum[MAXN+1];

int o[MAXN],no;

int bit[MAXN+2];
void bmod(int idx) { ++idx; while(idx<=n+1) { bit[idx]++; idx+=idx&-idx; } }
int bget(int idx) { ++idx; int ret=0; while(idx>0) { ret+=bit[idx]; idx-=idx&-idx; } return ret; }

void run() {
	memset(pmn,-1,sizeof(pmn));
	scanf("%d",&n);
	no=0; FORE(i,2,n) if(pmn[i]==-1) for(int j=i;j<=n;j+=i) if(pmn[j]==-1) pmn[j]=i,o[no++]=j;
	isc[0]=isc[1]=0; FORE(i,2,n) isc[i]=pmn[i]==i&&2*i>n;
	csum[0]=0; FORE(i,1,n) csum[i]=csum[i-1]+(isc[i-1]?1:0);
	phi[1]=1; FORE(i,2,n) { int j=i/pmn[i]; phi[i]=phi[j]*(pmn[i]==pmn[j]?pmn[i]:pmn[i]-1); }

	//printf("o:"); REP(i,no) printf(" %d",o[i]); puts("");
	ll ret=0; int at=0; memset(bit,0,sizeof(bit));
	for(int i=no-1;i>=0;--i) {
		int x=o[i]; if(pmn[x]==x&&2*x>n) continue;
		// a = # numbers y for which 2<=y<x and gcd(x,y)!=1
		// b = # numbers y for which 2<=y<x and pmn[x]*pmn[y]>n, so all except those with pmn[y]<=n/pmn[x], the rhs of which is increasing
		// c = # numbers y for which 2<=y<x and pmn[y]==y and 2*y>n

		//75159514333647
		/*vector<int> fact; for(int z=x;z!=1;z/=pmn[z]) if(SZ(fact)==0||fact.back()!=pmn[z]) fact.PB(pmn[z]);
		int a=0;
		FOR(j,1,1<<SZ(fact)) {
			int mlt=1,cnt=0; REPSZ(k,fact) if(j&(1<<k)) mlt*=fact[k],++cnt;
			int cur=(x-1)/mlt; if(cnt%2==1) a+=cur; else a-=cur;
		}*/
		int a=x-phi[x]-1;
		while(at<no&&pmn[o[at]]<=n/pmn[x]) {
			//printf("bmod %d (%d)\n",o[at],pmn[o[at]]);
			bmod(o[at]);
			++at;
		}
		int b=x-2-bget(x-1);
		int c=csum[x];

		int n0=c,n3=b-c,n1=a,n2=x-2-n0-n1-n3;
		ret+=0*n0+1*n1+2*n2+3*n3;
		//printf("%d (%d): a=%d b=%d c=%d n0=%d n1=%d n2=%d n3=%d [%d,%d]\n",x,pmn[x],a,b,c,n0,n1,n2,n3,bget(n),bget(x));
	}
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}