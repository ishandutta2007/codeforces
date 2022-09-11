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

const int MAXVAL=1000000;
const int MAXN=300000;


int pmn[MAXVAL+1];
int nxt[MAXVAL+1];
int len[MAXVAL+1];

int numdiv(int x) {
	if(x==1) return 1;
	int ret=1;
	while(x!=1) {
		int p=pmn[x],cnt=0;
		while(x!=1&&pmn[x]==p) x/=p,++cnt;
		ret*=cnt+1;
	}
	return ret;
}

int n,nq;
int a[MAXN];
set<int> nonfinal;

ll bit[MAXN+1];
void bmod(int idx,int by) { ++idx; while(idx<=n) { bit[idx]+=by; idx+=idx&-idx; } } 
ll bget(int idx) { ++idx; ll ret=0; while(idx>0) { ret+=bit[idx]; idx-=idx&-idx; } return ret; }

void run() {
	memset(pmn,-1,sizeof(pmn)); FORE(i,2,MAXVAL) if(pmn[i]==-1) for(int j=i;j<=MAXVAL;j+=i) if(pmn[j]==-1) pmn[j]=i;
	FORE(i,1,MAXVAL) nxt[i]=numdiv(i);
	len[1]=len[2]=1; FORE(i,3,MAXVAL) len[i]=len[nxt[i]]+1;
	//int mx=1; FORE(i,1,MAXVAL) mx=max(mx,len[i]); printf("mx=%d\n",mx);

	scanf("%d%d",&n,&nq);
	REP(i,n) scanf("%d",&a[i]);
	nonfinal.clear(); REP(i,n) if(a[i]!=1&&a[i]!=2) nonfinal.insert(i);
	memset(bit,0,sizeof(bit));
	REP(i,n) bmod(i,a[i]);
	REP(i,nq) {
		int kind; scanf("%d",&kind);
		if(kind==1) {
			int l,r; scanf("%d%d",&l,&r); --l,--r;
			auto it=nonfinal.lower_bound(l);
			while(it!=nonfinal.end()&&*it<=r) {
				int idx=*it;
				//printf("%d: %d->%d\n",idx,a[idx],nxt[a[idx]]);
				bmod(idx,nxt[a[idx]]-a[idx]);
				a[idx]=nxt[a[idx]];
				if(a[idx]==1||a[idx]==2) nonfinal.erase(it++); else ++it;
			}
		}
		if(kind==2) {
			int l,r; scanf("%d%d",&l,&r); --l,--r;
			ll ans=bget(r)-bget(l-1); printf("%lld\n",ans);
		}
	}


}

int main() {
	run();
	return 0;
}