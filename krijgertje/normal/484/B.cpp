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

int n;
int a[200000];
int maxle[2000001];


void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);

//	n=200000; REP(i,n) a[i]=5*i+1;

	sort(a,a+n);
	{ int nn=0; REP(i,n) if(nn==0||a[i]!=a[nn-1]) a[nn++]=a[i]; n=nn; }

	memset(maxle,-1,sizeof(maxle));
	REP(i,n) maxle[a[i]]=i;
	FORE(i,1,2*a[n-1]) if(maxle[i]==-1) maxle[i]=maxle[i-1];

	int ret=0;
	REP(j,n) {
		// a[i]=p*a[j]+q (q<a[j])
		for(int p=1;p*a[j]<=a[n-1];++p) {
			int i=maxle[p*a[j]+a[j]-1];
			if(i==-1||a[i]<p*a[j]) continue;
			int cur=a[i]-p*a[j];
//			printf("testing %d mod %d = %d\n",a[i],a[j],cur);
			if(cur>ret) ret=cur;
		}
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}