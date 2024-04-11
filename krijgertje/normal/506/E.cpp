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

const int MOD=10007;

char s[201]; int slen;
int want;

// ways[a][b][c] = number of ways to match palindrom a times on both sides, b times on the left and c times on the right
// (so remaining range is (a+b)..(slen-a-c-1)
int ways[101][201][201]; 
#define INC(x) if((x+=ways[a][b][c])>=MOD) x-=MOD;

// cnt[b][c][d] -> prod(25^bi,i=1..b)*prod(24^ci,i=1..c)*prod(26^di,i=1..d) s.t. b+c+d-1+sum(bi)+sum(ci)+sum(di)=want/2
int cnt[101][201][2];

int n;
int A[401][401];
int B[401][401];
int C[401][401];

void mmult(int A[401][401],int B[401][401]) {
	REP(i,n) FOR(j,i,n) {
		int c=0;
		FORE(k,i,j) {
			c+=A[i][k]*B[k][j];
			if(c>INT_MAX-MOD*MOD) c%=MOD;
		}
		C[i][j]=c%MOD;
	}
	REP(i,n) REP(j,n) A[i][j]=C[i][j];
}

void mpow(int k) {
	REP(i,n) REP(j,n) B[i][j]=A[i][j];
	REP(i,n) REP(j,n) A[i][j]=i==j?1:0;
	while(k>0) {
		if(k&1) mmult(A,B);
		k/=2; if(k==0) break; else mmult(B,B);
	}
}

void run() {
	scanf("%s%d",s,&want); slen=strlen(s); want+=slen;

	memset(ways,0,sizeof(ways));
	memset(cnt,0,sizeof(cnt));
	ways[0][0][0]=1;
	REPE(a,slen/2) REPE(b,slen) REPE(c,slen) if(ways[a][b][c]>0) {
		int p=a+b,q=slen-a-c;
		//printf("%d %d %d = %d -> %d,%d -> %c %c\n",a,b,c,ways[a][b][c],p,q,s[p],s[q]);
		if(p>=q) {
			REP(i,want%2==0?1:26) INC(cnt[a][b+c][1]);
		} else if(p==q-1) {
			if(want%2==1) INC(cnt[a+1][b+c][0]);
			REP(i,want%2==0?1:26) INC(cnt[a+1][b+c][1]);
		} else if(s[p]==s[q-1]) {
			INC(ways[a+1][b][c]);
		} else {
			INC(ways[a][b+1][c]);
			INC(ways[a][b][c+1]);
		}
	}

	// i<maxC				maxC-i ci left
	// i<maxC+maxB			working on (i-maxC+1)th bi
	// i<maxC+maxB+maxB+1	done i-maxC-maxB bi and working on di
	//1148

	// ccccCccccCbbbbBbbbB

	int maxC=slen,maxB=(slen+1)/2;
	n=maxC+maxB+maxB+1;
	REP(i,n) REP(j,n) A[i][j]=0;
	REP(i,maxC) A[i][i]=24,A[i][i+1]=1; A[maxC-1][maxC+maxB]=1;
	FOR(i,maxC,maxC+maxB) A[i][i]=25,A[i][i+maxB+1]=1; FOR(i,maxC,maxC+maxB-1) A[i][i+1]=1;
	FOR(i,maxC+maxB,maxC+maxB+maxB+1) A[i][i]=26;
	//REP(i,n) { REP(j,n) printf("%2d ",A[i][j]); puts(""); }
	mpow(want/2); // not last one
	//REP(i,n) { REP(j,n) printf("%2d ",A[i][j]); puts(""); }

	int ret=0;
	REPE(b,(slen+1)/2) REPE(c,slen) REP(d,2) if(cnt[b][c][d]>0) {
		n=b+c+d;
		int i=c!=0?maxC-c:b!=0?maxC:maxC+maxB,j=d!=0?maxC+maxB+b:b!=0?maxC+b-1:maxC-1,cur=A[i][j];
		//printf("%d* p(25^(bi-1),%d)p(24^(ci-1),%d)p(26^(di-1),%d), s(bi)+s(ci)+s(di)=%d\n",cnt[b][c][d],b,c,d,want/2+1);
		//printf("A[%d][%d]=%d\n",i,j,cur);
		ret+=cnt[b][c][d]*cur;
		if(ret>INT_MAX-MOD*MOD) ret%=MOD;
	}
	ret%=MOD;
	printf("%d\n",ret);

}

int main() {
	clock_t tStart = clock();
	run();
	fprintf(stderr,"Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	return 0;
}