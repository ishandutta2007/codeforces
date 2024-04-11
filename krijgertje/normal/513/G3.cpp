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

int n,times;
int x[100];

double p[2][100][100];
double f1[101][100];
double g1[101][100];
double f2[100][101];
double g2[100][102];
double f3[100][101];
double g3[100][102];

int c2(int n) { return n*(n+1)/2; }

void run() {
	scanf("%d%d",&n,&times);
	REP(i,n) scanf("%d",&x[i]);
	if(times>875) times=875;
	int at=0;
	REP(i,n) FOR(j,i+1,n) p[at][i][j]=0;
	double den=.5*n*(n+1);
	REP(t,times) {
		int to=1-at;
		REP(j,n) { f1[0][j]=0; REP(i,n) f1[i+1][j]=f1[i][j]+p[at][i][j]; }
		REP(j,n) { g1[0][j]=0; REP(i,n) g1[i+1][j]=g1[i][j]+f1[i][j]; }
		REP(i,n) { f2[i][0]=0; REP(j,n) f2[i][j+1]=f2[i][j]+p[at][i][j]; }
		REP(i,n) { g2[i][0]=0; REPE(j,n) g2[i][j+1]=g2[i][j]+f2[i][j]; }
		REP(k,n) { f3[k][0]=0; REP(l,n-k) f3[k][l+1]=f3[k][l]+1-p[at][l][k+l]; }
		REP(k,n) { g3[k][0]=0; REPE(l,n-k) g3[k][l+1]=g3[k][l]+f3[k][l]; }
		REP(i,n) FOR(j,i+1,n) {
			p[to][i][j]=0;
			// a<=b<i<j		i		j		+
			// a<=i<=b<j	a+b-i	j		+
			// a<=i<j<=b	a+b-i	a+b-j	-
			// i<a<=b<j		i		j		+
			// i<a<=j<=b	i		a+b-j	+
			// i<=j<a<=b	i		j		+
			p[to][i][j]+=p[at][i][j]*c2(i);
			p[to][i][j]+=(g1[j+1][j]-g1[i+1][j])-(g1[j-i][j]-g1[0][j]);
			p[to][i][j]+=(g3[j-i][n-j+i+1]-g3[j-i][i+1])-(g3[j-i][n-j]-g3[j-i][0]);
			p[to][i][j]+=p[at][i][j]*c2(j-i-1);
			p[to][i][j]+=(g2[i][n+1]-g2[i][j+1])-(g2[i][i+n-j+1]-g2[i][i+1]);
			p[to][i][j]+=p[at][i][j]*c2(n-j-1);
			p[to][i][j]/=den;

/*			double check=0;
			REP(a,n) FOR(b,a,n) {
				int ni=i<a||i>b?i:a+b-i;
				int nj=j<a||j>b?j:a+b-j;
				if(ni<=nj) check+=p[at][ni][nj]/den;
				else check+=(1-p[at][nj][ni])/den;
			}
			double diff=abs(check-p[to][i][j]);
			if(diff>1e-9) printf("%d %d %d: have %lf, want %lf\n",t,i,j,p[to][i][j],check); */
		}
		at=to;
	}
	//REP(i,n) FOR(j,i+1,n) printf("%d %d: %lf\n",i,j,p[at][i][j]);
	double ret=0;
	REP(i,n) FOR(j,i+1,n) {
		if(x[i]>x[j]) ret+=1-p[at][i][j]; else ret+=p[at][i][j];
	}
	printf("%.9lf\n",ret);
}

int main() {
	run();
	return 0;
}