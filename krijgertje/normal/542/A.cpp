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

const int MAXA=200000;
const int MAXB=200000;

typedef struct X { int l,r,v,idx; } X;
bool lcmp(const X &p,const X &q) { return p.l<q.l; }
bool rcmp(const X &p,const X &q) { return p.r>q.r; }

int na,nb;
X a[MAXA];
X b[MAXB];

int val[MAXA+MAXB],nval;
int findval(int key) { int l=0,r=nval-1; while(l<=r) { int m=l+(r-l)/2; if(val[m]<key) l=m+1; else if(val[m]>key) r=m-1; else return m; } assert(false); return -1; }

int sval[1<<20],sidx[1<<20];
void put(int x,int l,int r,int POS,int VAL,int IDX) {
//	printf("putting\n");
	if(l==r) { sval[x]=VAL; sidx[x]=IDX; return; }
	int m=l+(r-l)/2;
	if(POS<=m) put(2*x+1,l,m,POS,VAL,IDX); else put(2*x+2,m+1,r,POS,VAL,IDX);
	if(VAL>sval[x]) sval[x]=VAL,sidx[x]=IDX;
}
pair<int,int> get(int x,int l,int r,int POS) {
//	printf("getting\n");
	if(l>=POS) return MP(sval[x],sidx[x]);
	int m=l+(r-l)/2;
	if(POS>m) return get(2*x+2,m+1,r,POS);
	pair<int,int> ret=get(2*x+1,l,m,POS);
	if(sval[2*x+2]>ret.first) ret=MP(sval[2*x+2],sidx[2*x+2]);
	return ret;
}


void run() {
	scanf("%d%d",&na,&nb);
	REP(i,na) scanf("%d%d",&a[i].l,&a[i].r),a[i].v=0,a[i].idx=i;
	REP(i,nb) scanf("%d%d%d",&b[i].l,&b[i].r,&b[i].v),b[i].idx=i;

	ll ret=0; int reta=-1,retb=-1;

	// max ra | la<=lb
	{
		sort(a,a+na,lcmp);
		sort(b,b+nb,lcmp);
		int i=0,j=0,maxra=INT_MIN,maxraidx=-1;
		while(j<nb) {
			while(i<na&&a[i].l<=b[j].l) { if(a[i].r>maxra) maxra=a[i].r,maxraidx=a[i].idx; ++i; }
			if(maxra>b[j].l) { ll cur=(ll)b[j].v*(min(b[j].r,maxra)-b[j].l); if(cur>ret) ret=cur,reta=maxraidx,retb=b[j].idx; }
			++j;
		}
	}
	//printf("%lld %d %d\n",ret,reta,retb);

	// min la | ra>=rb
	{
		sort(a,a+na,rcmp);
		sort(b,b+nb,rcmp);
		int i=0,j=0,minla=INT_MAX,minlaidx=-1;
		while(j<nb) {
			while(i<na&&a[i].r>=b[j].r) { if(a[i].l<minla) minla=a[i].l,minlaidx=a[i].idx; ++i; }
			if(minla<b[j].r) { ll cur=(ll)b[j].v*(b[j].r-max(b[j].l,minla)); if(cur>ret) ret=cur,reta=minlaidx,retb=b[j].idx; }
			++j;
		}
	}
	//printf("%lld %d %d\n",ret,reta,retb);

	// max ra-la | lb<=la&&ra<=rb
	{
		nval=0; REP(i,na) val[nval++]=a[i].l; REP(i,nb) val[nval++]=b[i].l; sort(val,val+nval); nval=unique(val,val+nval)-val;
		reverse(a,a+na);
		reverse(b,b+nb);
		int i=0,j=0;
		while(j<nb) {
			while(i<na&&a[i].r<=b[j].r) { put(0,0,nval-1,findval(a[i].l),a[i].r-a[i].l,a[i].idx); ++i; }
			pair<int,int> res=get(0,0,nval-1,findval(b[j].l));
			ll cur=(ll)b[j].v*res.first; if(cur>ret) ret=cur,reta=res.second,retb=b[j].idx;
			++j;
		}
	}
	cout<<ret<<endl;
	if(reta!=-1&&retb!=-1) cout<<(reta+1)<<" "<<(retb+1)<<endl;
}

int main() {
	run();
	return 0;
}