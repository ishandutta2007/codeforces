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
#include <cassert>
#include <climits>
#include <cstring>
#include <stack>
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
typedef vector<int> VI; typedef vector<VI> VVI; typedef vector<VVI> VVVI;

double calc(int cnt,const vector<int> &can) {
	int n=SZ(can);
	vector<double> p(cnt+1); p[0]=1; FORE(i,1,cnt) p[i]=p[i-1]/n;
	vector<vector<double> > choose(cnt+1,vector<double>(cnt+1,0)); REPE(i,cnt) { choose[i][0]=choose[i][i]=1; FOR(j,1,i) choose[i][j]=choose[i-1][j-1]+choose[i-1][j]; }
	vector<double> dp[2]; dp[0]=dp[1]=vector<double>(cnt+1,0);
	int a=0; dp[a][cnt]=1;
	REP(i,n) {
		REPE(j,cnt) dp[!a][j]=0;
		REPE(j,cnt) if(dp[a][j]>0) {
			REPE(k,min(j,can[i])) {
//				printf("at room %d: from %d -> %d = %lf (%lf*%lf*%lf)\n",i,j,k,choose[j][k]*p[k]*dp[a][j],choose[j][k],p[k],dp[a][j]);
				dp[!a][j-k]+=choose[j][k]*p[k]*dp[a][j];
			}
		}
		a=!a;
	}
	return dp[a][0];
}

void run() {
	int nstudent,nroom; scanf("%d%d",&nstudent,&nroom);
	vector<int> can(nroom); REP(i,nroom) scanf("%d",&can[i]);
	double sum=0,ret=0;
	FORE(maxqueue,1,nstudent) {
		vector<int> ncan(nroom); REP(i,nroom) ncan[i]=maxqueue*can[i];
		double cur=calc(nstudent,ncan);
//		printf("%d: %lf\n",maxqueue,cur);
//		REPSZ(i,ncan) printf(" %d",ncan[i]); puts("");
		cur-=sum;
		ret+=cur*maxqueue;
		sum+=cur;
	}
	printf("%.12lf\n",ret);
}

int main() {
//	int n; scanf("%d",&n); REP(i,n)
	run();
	return 0;
}