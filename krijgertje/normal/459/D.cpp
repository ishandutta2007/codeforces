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

const int MAXN=1000000;

typedef struct X { int val,idx; } X;
bool operator<(const X &a,const X &b) { if(a.val!=b.val) return a.val<b.val; return a.idx<b.idx; }

typedef struct Y { int val,type,idx; } Y;
bool operator<(const Y &a,const Y &b) { if(a.val!=b.val) return a.val>b.val; if(a.type!=b.type) return a.type>b.type; return a.idx<b.idx; }

int n;
int a[MAXN];
int b[MAXN];
int c[MAXN];
X x[MAXN];
Y y[2*MAXN];

int fw[1<<20];
void inc(int x) { x+=2; while(x<(1<<20)) { fw[x]++; x+=x&-x; } }
int get(int x) { x+=2; int ret=0; while(x>0) { ret+=fw[x]; x-=x&-x; } return ret; }

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]);

	REP(i,n) x[i].val=a[i],x[i].idx=i; sort(x,x+n);
	for(int i=0;i<n;) {
		int j=i+1; while(j<n&&x[j].val==x[i].val) ++j;
		FOR(k,i,j) b[x[k].idx]=k-i+1,c[x[k].idx]=j-k;
		i=j;
	}
	//REP(i,n) printf("%d ",a[i]); puts("");
	//REP(i,n) printf("%d ",b[i]); puts("");
	//REP(i,n) printf("%d ",c[i]); puts("");
	REP(i,n) {
		y[2*i+0].val=b[i],y[2*i+0].type=0,y[2*i+0].idx=i;
		y[2*i+1].val=c[i],y[2*i+1].type=1,y[2*i+1].idx=i;
	}
	sort(y,y+2*n);

	ll ret=0;
	REP(i,2*n) {
		if(y[i].type==0) {
			inc(y[i].idx);
		} else {
			int cur=get(y[i].idx-1);
			//printf("ret+= #(i<=%d | b[i]>=%d) = %d\n",y[i].idx-1,y[i].val+1,cur);
			ret+=cur;
		}
	}
	printf("%I64d\n",ret);
}

int main() {
	run();
	return 0;
}