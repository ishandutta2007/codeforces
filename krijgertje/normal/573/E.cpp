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

const int BSZ=300;
const int MAXN=100000;
const int MAXB=(MAXN+BSZ-1)/BSZ;
const int MAXVAL=1000000;


int na;
int a[MAXN];		//aidx->val
bool used[MAXN];	//aidx->bool
ll loc[MAXN];		//aidx->val

int nb;
int bhave[MAXB];	//bidx->cnt
ll bsum[MAXB];		//bidx->val
int sstart[MAXB+1];	//bidx->sidx
int hstart[MAXB];	//bidx->hidx
int hend[MAXB];		//bidx->hidx
int hat[MAXB];		//bidx->hidx

int ns;
pair<int,int> s[MAXN];	// sidx->[val,aidx]

int hmap[MAXN];		//hidx->aidx

bool ok(int p,int q,int r) {
	assert(a[p]<a[q]&&a[q]<a[r]);
	//x=(loc[p]-loc[q])/(a[q]-a[p])
	//y=(loc[q]-loc[r])/(a[r]-a[q])
	//assert((loc[p]-loc[q])<=LLONG_MAX/(a[r]-a[q]));
	//assert((loc[q]-loc[r])<=LLONG_MAX/(a[q]-a[p]));
	return (loc[p]-loc[q])*(a[r]-a[q])<(loc[q]-loc[r])*(a[q]-a[p]);
}
void calchull(int j) {
	hat[j]=hend[j]=hstart[j];
	//printf("calchull(%d):",j); for(int k=sstart[j];k<sstart[j+1];++k) if(!used[s[k].second]) printf(" %dx+%lld (%d)",a[s[k].second],loc[s[k].second],s[k].second); puts(""); fflush(stdout);
	for(int k=sstart[j];k<sstart[j+1];++k) if(!used[s[k].second]) {
		if(hend[j]-hstart[j]>=1&&a[hmap[hend[j]-1]]==a[s[k].second]) { assert(loc[hmap[hend[j]-1]]>=loc[s[k].second]); continue; }
		while(hend[j]-hstart[j]>=2&&!ok(hmap[hend[j]-2],hmap[hend[j]-1],s[k].second)) --hend[j];
		hmap[hend[j]++]=s[k].second;
	}
	//printf("->"); FOR(k,hstart[j],hend[j]) printf(" %dx+%lld",a[hmap[k]],loc[hmap[k]]); puts("");
}

void run() {
	scanf("%d",&na);
	REP(i,na) scanf("%d",&a[i]);

	/*srand(time(NULL));
	na=MAXN;
	REP(i,na) a[i]=(rand()*RAND_MAX+rand())%(2*MAXVAL+1)-MAXVAL;
	//printf("%d\n",na); REP(i,na) printf("%d ",a[i]); puts(""); */

	REP(i,na) used[i]=false,loc[i]=a[i];

	nb=(na+BSZ-1)/BSZ;
	REP(i,nb) bhave[i]=0,bsum[i]=0;

	ns=0;
	REP(j,nb) {
		sstart[j]=ns;
		for(int k=j*BSZ;k<na&&k<(j+1)*BSZ;++k) s[ns++]=MP(a[k],k);
		sort(s+sstart[j],s+ns);
	}
	sstart[nb]=ns;

	REP(j,nb) { hstart[j]=sstart[j]; calchull(j); }

	ll ret=0,cur=0,sum=0;
	REP(i,na) {
		ll cval=LLONG_MIN; int cidx=-1,bidx=-1;
		ll have=0; ll suf=sum;
		REP(j,nb) {
			suf-=bsum[j];
			while(hat[j]+1<hend[j]&&a[hmap[hat[j]]]*have+loc[hmap[hat[j]]]+suf<a[hmap[hat[j]+1]]*have+loc[hmap[hat[j]+1]]+suf) ++hat[j];
			if(hat[j]<hend[j]&&a[hmap[hat[j]]]*have+loc[hmap[hat[j]]]+suf>cval) cval=a[hmap[hat[j]]]*have+loc[hmap[hat[j]]]+suf,cidx=hmap[hat[j]],bidx=cidx/BSZ;
			have+=bhave[j];
		}
		assert(cidx!=-1);
		//printf("== %dx+%lld == %lld (%d)\n",a[cidx],loc[cidx],cval,cidx);
		used[cidx]=true;
		cur+=cval;
		++bhave[bidx];
		bsum[bidx]+=a[cidx]; sum+=a[cidx];
		for(int k=bidx*BSZ;k<na&&k<(bidx+1)*BSZ;++k) if(k<cidx) loc[k]+=a[cidx]; else if(k>cidx) loc[k]+=a[k];
		calchull(bidx);
		if(cur>ret) ret=cur;
	}
	printf("%I64d\n",ret);
}


int main() {
	run();
	return 0;
}