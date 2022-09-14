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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

int n; ll mind;
ll h[100000];
int prv[100000];
int val[100000];

int maxidx[1<<18];

ll keys[100000]; int nkeys;

int find(int x,int l,int r,ll L,ll R) {
	if(R<keys[l]||L>keys[r]) return -1;
//	printf("finding(%d,%d,%d,%lld,%lld)\n",x,l,r,L,R); if(x<0) exit(0);
	if(L<=keys[l]&&keys[r]<=R) return maxidx[x];
	int m=l+(r-l)/2;
	if(R<=keys[m]) return find(2*x+1,l,m,L,R);
	if(keys[m+1]<=L) return find(2*x+2,m+1,r,L,R);
	int a=find(2*x+1,l,m,L,R),b=find(2*x+2,m+1,r,L,R);
	return b==-1||a!=-1&&val[a]>=val[b]?a:b;
}

void put(int x,int l,int r,ll KEY,int IDX) {
	if(l==r) {
		if(maxidx[x]==-1||val[IDX]>val[maxidx[x]]) maxidx[x]=IDX;
	} else {
		int m=l+(r-l)/2;
		if(KEY<=keys[m]) put(2*x+1,l,m,KEY,IDX); else put(2*x+2,m+1,r,KEY,IDX);
		int a=maxidx[2*x+1],b=maxidx[2*x+2];
		maxidx[x]=b==-1||a!=-1&&val[a]>=val[b]?a:b;
	}
	//printf("put(%d,%d,%d,%lld,%d) => %d/%d\n",x,l,r,KEY,IDX,maxidx[x],maxidx[x]==-1?-1:val[maxidx[x]]);
}

int ret[100000];

void run() {
	cin>>n>>mind; REP(i,n) cin>>h[i];
	REP(i,n) keys[i]=h[i]; sort(keys,keys+n); nkeys=0; REP(i,n) if(i==0||keys[i]!=keys[nkeys-1]) keys[nkeys++]=keys[i];
	//REP(i,n) printf("%lld ",h[i]); puts("");
	//REP(i,nkeys) printf("%lld ",keys[i]); puts("");
	
	memset(maxidx,-1,sizeof(maxidx));
	int last=-1;
	REP(i,n) {
		// val[i]=max(max(val[j],j<i&&h[j]<=h[i]-mind),max(val[j],j<i&&h[j]>=val[i]+mind),1)
		val[i]=1; prv[i]=-1;
		int lj=find(0,0,nkeys-1,LLONG_MIN,h[i]-mind);
		int hj=find(0,0,nkeys-1,h[i]+mind,LLONG_MAX);
		if(lj!=-1&&val[lj]+1>val[i]) { val[i]=val[lj]+1; prv[i]=lj; }
		if(hj!=-1&&val[hj]+1>val[i]) { val[i]=val[hj]+1; prv[i]=hj; }
		if(last==-1||val[i]>val[last]) last=i;
		//printf("%d: %d,%d = %d [<=%lld >= %lld]\n",i,lj,hj,val[i],h[i]-mind,h[i]+mind);
		put(0,0,nkeys-1,h[i],i);
	}
	for(int x=last;x!=-1;x=prv[x]) ret[val[x]-1]=x;
	printf("%d\n",val[last]); REP(i,val[last]) { if(i!=0) printf(" "); printf("%d",ret[i]+1); } puts("");
}

int main() {
	run();
	return 0;
}