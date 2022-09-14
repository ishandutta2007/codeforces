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

const int MAXN=1000;
const int MOD=1000000007;
const int DX[8]={-1,-1,0,+1,+1,+1,0,-1},DY[8]={0,+1,+1,+1,0,-1,-1,-1};

int n;
char g[MAXN][MAXN+1];

int d[8][MAXN][MAXN];
int n2[8][MAXN][MAXN];
int n3[8][MAXN][MAXN];

bool better(int a2,int a3,int b2,int b3) {
	double a=a2*log(2)+a3*log(3);
	double b=b2*log(2)+b3*log(3);
	return a>b;
}

void run() {
	scanf("%d",&n);
	REP(x,n) scanf("%s",g[x]);

	REP(k,8) for(int x=DX[k]<=0?0:n-1;0<=x&&x<n;x+=DX[k]<=0?+1:-1) for(int y=DY[k]<=0?0:n-1;0<=y&&y<n;y+=DY[k]<=0?+1:-1) {
		d[k][x][y]=g[x][y]=='0'?0:1+(0<=x+DX[k]&&x+DX[k]<n&&0<=y+DY[k]&&y+DY[k]<n?d[k][x+DX[k]][y+DY[k]]:0);
		n2[k][x][y]=(g[x][y]=='2'?1:0)+(0<=x+DX[k]&&x+DX[k]<n&&0<=y+DY[k]&&y+DY[k]<n?n2[k][x+DX[k]][y+DY[k]]:0);
		n3[k][x][y]=(g[x][y]=='3'?1:0)+(0<=x+DX[k]&&x+DX[k]<n&&0<=y+DY[k]&&y+DY[k]<n?n3[k][x+DX[k]][y+DY[k]]:0);
	}
	//REP(k,8) { printf("(%d,%d)\n",DX[k],DY[k]); REP(x,n) { REP(y,n) printf("%d",d[k][x][y]); puts(""); } }
	//REP(k,8) { printf("(%d,%d)\n",DX[k],DY[k]); REP(x,n) { REP(y,n) printf("%d",n2[k][x][y]); puts(""); } }
	//REP(k,8) { printf("(%d,%d)\n",DX[k],DY[k]); REP(x,n) { REP(y,n) printf("%d",n3[k][x][y]); puts(""); } }

	int rn2=0,rn3=0; bool any=false;
	REP(k,2) REP(x,n) REP(y,n) if(g[x][y]!='0') {
		int cd=INT_MAX; for(int kk=k;kk<8;kk+=2) if(d[kk][x][y]<cd) cd=d[kk][x][y];
		int cn2=g[x][y]=='2'?-3:0; for(int kk=k;kk<8;kk+=2) cn2+=n2[kk][x][y]-(0<=x+DX[kk]*cd&&x+DX[kk]*cd<n&&0<=y+DY[kk]*cd&&y+DY[kk]*cd<n?n2[kk][x+DX[kk]*cd][y+DY[kk]*cd]:0);
		int cn3=g[x][y]=='3'?-3:0; for(int kk=k;kk<8;kk+=2) cn3+=n3[kk][x][y]-(0<=x+DX[kk]*cd&&x+DX[kk]*cd<n&&0<=y+DY[kk]*cd&&y+DY[kk]*cd<n?n3[kk][x+DX[kk]*cd][y+DY[kk]*cd]:0);
		//printf("(%d,%d,%c): %d -> 2^%d*3^%d\n",x,y,k==0?'+':'x',cd,cn2,cn3);
		any=true; if(better(cn2,cn3,rn2,rn3)) rn2=cn2,rn3=cn3;
	}
	if(!any) { printf("0\n"); return; }
	int ret=1; REP(i,rn2) ret=(ll)2*ret%MOD; REP(i,rn3) ret=(ll)3*ret%MOD; printf("%d\n",ret);

}

int main() {
	run();
	return 0;
}