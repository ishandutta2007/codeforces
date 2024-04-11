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

int n,k,d;
int a[200000];

int m;
int b[200000];

int p[200000];
int bound[200000];


int maxval[200000],maxend[200000],maxcnt;
int minval[200000],minend[200000],mincnt;

int lazy[1000000];
int mintreeval[1000000];
void discharge(int x) {
	if(lazy[x]!=0) {
		lazy[2*x+1]+=lazy[x]; mintreeval[2*x+1]+=lazy[x];
		lazy[2*x+2]+=lazy[x]; mintreeval[2*x+2]+=lazy[x];
		lazy[x]=0;
	}
}

void change(int x,int l,int r,int L,int R,int by) {
	if(R<l||L>r) return;
	if(L<=l&&r<=R) {
		lazy[x]+=by;
		mintreeval[x]+=by;
	} else {
		discharge(x);
		int m=(l+r)>>1;
		change(2*x+1,l,m,L,R,by);
		change(2*x+2,m+1,r,L,R,by);
		mintreeval[x]=min(mintreeval[2*x+1],mintreeval[2*x+2]);
	}
}

int find(int x,int l,int r,int L,int R,int lim) {
	if(R<l||L>r||mintreeval[x]>lim) return -1;
	if(l==r) {
		return l;
	} else {
		discharge(x);
		int m=(l+r)>>1;
		int ret2=find(2*x+2,m+1,r,L,R,lim); if(ret2!=-1) return ret2;
		int ret1=find(2*x+1,l,m,L,R,lim); return ret1;
	}
}

int get(int x,int l,int r,int at) {
	if(l==r) {
		return mintreeval[x];
	} else {
		discharge(x);
		int m=(l+r)>>1;
		return at<=m?get(2*x+1,l,m,at):get(2*x+2,m+1,r,at);
	}
}

void init(int x,int l,int r) {
	lazy[x]=mintreeval[x]=0;
	if(l<r) {
		int m=(l+r)>>1;
		init(2*x+1,l,m);
		init(2*x+2,m+1,r);
	}
}

void change(int L,int R,int by) {
	if(L>R) return;
	//printf("\t\tchange %d..%d by %d\n",L,R,by);
	change(0,0,m-1,L,R,by);
}

int find(int L,int R,int lim) {
	return find(0,0,m-1,L,R,lim);
}

int get(int at) {
	return get(0,0,m-1,at);
}

void init() {
	init(0,0,m-1);
}

int anss,anst;
void sol(int s,int t) {
	//printf("%d..%d\n",s,t);
	if(t-s<anst-anss||t-s==anst-anss&&s>anss) return; anss=s,anst=t; 
}

bool pcmp(int x,int y) {
	if(b[x]!=b[y]) return b[x]<b[y];
	return x<y;
}

void process(int s,int t) {
	if(d==0) { sol(s,t); return; }
	{ m=0; int l=a[s]; FOR(i,s+1,t) if(a[i]<l) l=a[i]; FORE(i,s,t) b[m++]=(a[i]-l)/d; }

	//printf("processing:"); REP(i,m) printf(" %d",b[i]); puts("");

	REP(i,m) p[i]=i;
	sort(p,p+m,pcmp);
	REP(i,m) bound[p[i]]=i+1<m&&b[p[i]]==b[p[i+1]]?p[i+1]-1:m-1;
	for(int i=m-2;i>=0;--i) if(bound[i+1]<bound[i]) bound[i]=bound[i+1];
	//printf("bound:"); REP(i,m) printf(" %d",bound[i]); puts("");

	init();
	maxcnt=mincnt=0;
	for(int L=m-1;L>=0;--L) {
		//printf("\tat %d (%d)\n",L,b[L]);
//		printf("\t\tmax:"); REP(i,maxcnt) printf(" (%d,%d)",maxval[i],maxend[i]); puts("");
//		printf("\t\tmin:"); REP(i,mincnt) printf(" (%d,%d)",minval[i],minend[i]); puts("");

		//modify F(L+1,R) to F(L,R)
		change(L+1,m-1,-1);
		int atmax=L+1; while(maxcnt>0&&b[L]>=maxval[maxcnt-1]) {
			change(atmax,maxend[maxcnt-1],b[L]-maxval[maxcnt-1]);
			atmax=maxend[maxcnt-1]+1; --maxcnt;
		}
		maxval[maxcnt]=b[L]; maxend[maxcnt]=atmax-1; ++maxcnt;
		int atmin=L+1; while(mincnt>0&&b[L]<=minval[mincnt-1]) {
			change(atmin,minend[mincnt-1],minval[mincnt-1]-b[L]);
			atmin=minend[mincnt-1]+1; --mincnt;
		}
		minval[mincnt]=b[L]; minend[mincnt]=atmin-1; ++mincnt;

		//printf("\tval:"); FOR(i,L,m) printf(" %d",get(i)); puts("");

		//find max R with F(L,R)<=k and R<=bound[L]
		int R=find(L,bound[L],k);
		//printf("\t%d..%d\n",L,R);
		sol(s+L,s+R);
	}
}

void run() {
	scanf("%d%d%d",&n,&k,&d);
	REP(i,n) scanf("%d",&a[i]);

	anss=anst=0;
	int at=0;
	while(at<n) {
		int to=at+1;
		while(to<n&&(d==0&&a[at]==a[to]||d>0&&(a[to]-a[at])%d==0)) ++to;
		process(at,to-1);
		at=to;
	}
	printf("%d %d\n",anss+1,anst+1);
}

int main() {
	run();
	return 0;
}