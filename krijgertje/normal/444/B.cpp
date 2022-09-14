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

int n,d,x;
int getrand() { return x=((ll)x*37+10007)%1000000007; }

int a[100000],b[100000],c[100000];	//idx
int pos[100001],prv[100001],nxt[100001],lst;	//val
int one[100000],none;

void run() {
	scanf("%d%d%d",&n,&d,&x);
	REP(i,n) a[i]=i+1;
	REP(i,n) swap(a[i],a[getrand()%(i+1)]);
	REP(i,n) b[i]=i<d?1:0;
	REP(i,n) swap(b[i],b[getrand()%(i+1)]);
//	REP(i,n) printf("%d ",a[i]); puts("");
//	REP(i,n) printf("%d ",b[i]); puts("");

	REP(i,n) pos[a[i]]=i;
	prv[1]=-1; FORE(i,2,n) prv[i]=i-1;
	FORE(i,1,n-1) nxt[i]=i+1; nxt[n]=-1;
	lst=n;
	none=0; REP(i,n) if(b[i]==1) one[none++]=i;

	double phit=1.0*none/n;
	int cnt=0; double pval=1;
	for(int i=n-1;i>=0;--i) {
		// cnt + (1-none/(i+1))^cnt * none
		// cnt + (1-phit)^cnt * none
		if(cnt>i) cnt=i;
		if((n-1-i)%100==0) {
			while(cnt<i&&cnt+1+pval*(1-phit)*none<cnt+pval*none) ++cnt,pval*=1-phit;
			while(cnt>0&&cnt-1+pval/(1-phit)*none<cnt+pval*none) --cnt,pval/=1-phit;
		}

		//if(i%1000==0) printf("\t%d: %d (%lf)\n",i,cnt,cnt+pow(1-1.0*none/(i+1),cnt)*none,pval);

		c[i]=0;
		for(int j=0,val=lst;j<cnt;++j,val=prv[val]) if(b[i-pos[val]]) { c[i]=val; break; }
		if(c[i]==0) REP(j,none) if(a[i-one[j]]>c[i]) c[i]=a[i-one[j]];

		if(prv[a[i]]!=-1) nxt[prv[a[i]]]=nxt[a[i]];
		if(nxt[a[i]]!=-1) prv[nxt[a[i]]]=prv[a[i]];
		if(lst==a[i]) lst=prv[a[i]];
		while(none>0&&one[none-1]>=i) --none;
	}

	REP(i,n) printf("%d\n",c[i]);
}

int main() {
	run();
	return 0;
}