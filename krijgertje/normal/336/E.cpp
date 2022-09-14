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

const int MOD=1000000007;
int size,ncolors;

int ntriangles[5],npairs[5];
int choose[13][13];
int ways[5][13];

ll dp[201][201][5];	//dp[size][need][state] = number of ways to choose 'need' triangles for a structure of size 'size' form the given state (state=0 -> two opposite empty quadrants / otherwise state is the number of consecutive empty quadrants)

void run(int casenr) {
	ntriangles[0]=6; npairs[0]=0;
	ntriangles[1]=3; npairs[1]=0;
	ntriangles[2]=6; npairs[2]=1;
	ntriangles[3]=9; npairs[3]=2;
	ntriangles[4]=12; npairs[4]=4;
	REPE(i,12) { choose[i][0]=choose[i][i]=1; FOR(j,1,i) choose[i][j]=choose[i-1][j-1]+choose[i-1][j]; }
	REP(state,5) REPE(k,ntriangles[state]) { ways[state][k]=0; REPE(x,npairs[state]) if(x<=k&&ntriangles[state]-2*x>=k-x) ways[state][k]+=choose[npairs[state]][x]*choose[ntriangles[state]-2*x][k-x]; }

	scanf("%d%d",&size,&ncolors);

	memset(dp,0,sizeof(dp));
	REPE(k,2) dp[0][k][0]+=choose[2][k];
	REPE(k,1) dp[0][k][1]+=choose[1][k];
	REPE(k,2) dp[0][k][2]+=choose[2][k]; dp[0][1][2]++;
	REPE(k,3) dp[0][k][3]+=choose[3][k]; dp[0][1][3]+=2; dp[0][2][3]+=2;
	REPE(k,4) dp[0][k][4]+=choose[4][k]; dp[0][1][4]+=4; dp[0][2][4]+=8+2; dp[0][3][4]+=4;
	FORE(i,1,size) REPE(j,ncolors) {
		// state=0
		if(j==2) ++dp[i][j][0]; // two single quadrants
		if(j>=1) REPE(k,min(3,j-1)) dp[i][j][0]+=2*dp[i-1][j-1-k][1]*ways[1][k]; // one single quadrant
		REPE(k,min(6,j)) dp[i][j][0]+=dp[i-1][j-k][0]*ways[0][k];
		// state=1
		if(j==1) ++dp[i][j][1]; // one single quadrant
		REPE(k,min(3,j)) dp[i][j][1]+=dp[i-1][j-k][1]*ways[1][k];
		// state=2
		if(j==1) ++dp[i][j][2]; // one double quadrant
		if(j==2) ++dp[i][j][2]; // two single quadrants
		if(j>=1) REPE(k,min(3,j-1)) dp[i][j][2]+=2*dp[i-1][j-1-k][1]*ways[1][k]; // one quadrant
		REPE(k,min(6,j)) dp[i][j][2]+=dp[i-1][j-k][2]*ways[2][k];
		// state=3
		if(j==2) dp[i][j][3]+=2; // one double and one single quadrant
		if(j==3) ++dp[i][j][3]; // three single quadrants
		if(j>=1) REPE(k,min(3,j-1)) dp[i][j][3]+=2*dp[i-1][j-1-k][1]*ways[1][k]; // one double quadrant
		if(j>=2) REPE(k,min(3,j-2)) dp[i][j][3]+=3*dp[i-1][j-2-k][1]*ways[1][k]; // two single quadrants
		if(j>=1) REPE(k,min(6,j-1)) dp[i][j][3]+=2*dp[i-1][j-1-k][2]*ways[2][k]; // a single quadrant (non-middle)
		if(j>=1) REPE(k,min(6,j-1)) dp[i][j][3]+=1*dp[i-1][j-1-k][0]*ways[0][k]; // a single quadrant (middle)
		REPE(k,min(9,j)) dp[i][j][3]+=dp[i-1][j-k][3]*ways[3][k];
		// state=4
		if(j==2) dp[i][j][4]+=2; // two double quadrants
		if(j==3) dp[i][j][4]+=4; // one double and two single quadrants
		if(j==4) ++dp[i][j][4]; // four single quadrants
		if(j>=2) REPE(k,min(3,j-2)) dp[i][j][4]+=8*dp[i-1][j-2-k][1]*ways[1][k]; // one double and one single quadrant
		if(j>=3) REPE(k,min(3,j-3)) dp[i][j][4]+=4*dp[i-1][j-3-k][1]*ways[1][k]; // three single quadrants
		if(j>=1) REPE(k,min(6,j-1)) dp[i][j][4]+=4*dp[i-1][j-1-k][2]*ways[2][k]; // one double quadrant
		if(j>=2) REPE(k,min(6,j-2)) dp[i][j][4]+=4*dp[i-1][j-2-k][2]*ways[2][k]; // two single quadrants (adjacent)
		if(j>=2) REPE(k,min(6,j-2)) dp[i][j][4]+=2*dp[i-1][j-2-k][0]*ways[0][k]; // two single quadrants (opposite)
		if(j>=1) REPE(k,min(9,j-1)) dp[i][j][4]+=4*dp[i-1][j-1-k][3]*ways[3][k]; // one single quadrant
		REPE(k,min(12,j)) dp[i][j][4]+=dp[i-1][j-k][4]*ways[4][k];
		REP(state,5) dp[i][j][state]%=MOD;
	}
	ll ret=dp[size][ncolors][4];
	FORE(i,1,ncolors) ret=ret*i%MOD;
	cout<<ret;
}

int main() {
//	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}