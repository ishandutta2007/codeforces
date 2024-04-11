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
#include <list>  
#include <climits>
#include <cassert>
#include <ctime>
#include <cstring>
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
int a[300000];
int b[300000];
ll s[300001];

const int mycmp(const int &p,const int &q) { if(a[p]!=a[q]) return a[p]<a[q]; return p<q; }

void run(int casenr) {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	REP(i,n) b[i]=i; sort(b,b+n,mycmp);
	s[0]=0; REP(i,n) s[i+1]=s[i]+(a[i]>=0?a[i]:0);
	ll ret=LLONG_MIN; int start=-1,end=-1;
	int at=0;
	while(at<n) {
		int to=at; while(to<n&&a[b[at]]==a[b[to]]) ++to;
		if(to-at>=2) {
			int i=b[at],j=b[to-1];
			ll cur=a[i]+a[j]+s[j]-s[i+1];
//			printf("%d = %d..%d -> %lld\n",a[i],i,j,cur);
			if(cur>ret) { ret=cur; start=i; end=j; }
		}
		at=to;
	}

	int ncut=0; REP(i,n) if(i<start||i>end||start<i&&i<end&&a[i]<0) ++ncut;
	cout<<ret<<" "<<ncut<<endl;
	bool first=true; REP(i,n) if(i<start||i>end||start<i&&i<end&&a[i]<0) { if(first) first=false; else printf(" "); printf("%d",i+1); } puts("");

}


int main() {
//	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}