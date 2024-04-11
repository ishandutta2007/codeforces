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

const int MAXN=2000;
typedef struct L { int a,b,c; } L;

int n;
L l[MAXN];

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d%d%d",&l[i].a,&l[i].b,&l[i].c);
	int ret=0,norig=0;
	int nn=0; REP(i,n) if(l[i].c==0) ++norig; else l[nn++]=l[i]; n=nn;
	if(norig>=2) ret+=3*n;
	REP(i,n) {
		vector<long double> cur;
		REP(j,n) if(i!=j) {
			int ai=l[i].a,bi=l[i].b,ci=l[i].c;
			int aj=l[j].a,bj=l[j].b,cj=l[j].c;
			//x=(bj*ci-bi*cj)/(bj*ai-bi*aj)
			//y=(ai*cj-aj*ci)/(bj*ai-bi*aj)
			long double x=((long double)1.0)*(bj*ci-bi*cj)/(bj*ai-bi*aj);
			long double y=((long double)1.0)*(ai*cj-aj*ci)/(bj*ai-bi*aj);
			// P=(x,y),Q=(bj,-aj) (0-P)*Q/|P|/|Q|
			//if((x,y)^(x+bj,y-aj)<0) bj=-bj,aj=-aj,cj=-cj;
			if(x*aj+y*bj>0) bj=-bj,aj=-aj,cj=-cj;
			long double cosa=(x*bj-y*aj)/sqrt(x*x+y*y)/sqrt(aj*aj+bj*bj);
			//printf("%d %d -> %lf %lf -> %lf\n",i,j,x,y,cosa);
			cur.PB(cosa);
		}
		sort(cur.begin(),cur.end());
		//printf("%d:",i); REPSZ(j,cur) printf(" %.4Lf",cur[j]); puts("");
		//double mindiff=1e200,maxdiff=0;
		//FORSZ(j,1,cur) if(fabs(cur[j]-cur[j-1])<1e-12) mindiff=min(mindiff,(double)fabs(cur[j]-cur[j-1])); else maxdiff=max(maxdiff,(double)fabs(cur[j]-cur[j-1]));
		//printf("%d: %.12lf vs %.12lf\n",i,mindiff,maxdiff);

		for(int at=0,to=0;at<SZ(cur);at=to) { while(to<SZ(cur)&&fabs(cur[at]-cur[to])<1e-13) ++to; int cnt=to-at; ret+=cnt*(cnt-1)/2; }
	}
	ret/=3;
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}