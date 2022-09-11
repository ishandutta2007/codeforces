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
#include <cstring>
#include <list>  
#include <cassert>
#include <climits>
#include <bitset>
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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MAXVISITS=12;
const int MAXFORWARD=4;
const int MAXDIM=161;
const int MOD=1000000007;
typedef vector<vector<int>> Mat;
void inc(int &a,int b) { if((a+=b)>=MOD) a-=MOD; }

int nplanets,nvisits,nforward;

int dim;
vector<pair<int,int>> states;

void mmlt(Mat &A,const Mat &B) {
	Mat C(dim,vector<int>(dim));
	REP(i,dim) REP(j,dim) { int cur=0; REP(k,dim) cur=(cur+(ll)A[i][k]*B[k][j])%MOD; C[i][j]=cur; }
	REP(i,dim) REP(j,dim) A[i][j]=C[i][j];
}

Mat mpw(Mat x,int n) {
	Mat ret(dim,vector<int>(dim,0)); REP(i,dim) ret[i][i]=1;
	while(true) { if(n&1) mmlt(ret,x); if((n>>=1)==0) return ret; mmlt(x,x); }
}

Mat A;
Mat B;

int solve() {
	states.clear();
	REP(i,nvisits) REP(mask,1<<nforward) {
		int cnt=0; REP(k,nforward) if(mask&(1<<k)) ++cnt; if(cnt>i) continue;
		states.PB(MP(i,mask));
	}
	states.PB(MP(nvisits,0));
	dim=SZ(states);
	//printf("dim=%d\n",dim); REPSZ(i,states) printf("%d=(%d,%x)\n",i,states[i].first,states[i].second);
	assert(dim<=MAXDIM);
	A=vector<vector<int>>(dim,vector<int>(dim,0));
	REPSZ(i,states) {
		int cnt=0; REP(k,nforward) if(states[i].second&(1<<k)) ++cnt;
		REPSZ(j,states) {
			if(states[j].first==states[i].first&&states[j].second==((states[i].second<<1)&((1<<nforward)-1))) inc(A[i][j],1);
			if(states[j].first==states[i].first+1&&(states[j].first==nvisits&&states[j].second==0||states[j].first<nvisits&&states[j].second==(((states[i].second<<1)|1)&((1<<nforward)-1)))) inc(A[i][j],cnt+1);
		}
	}
	//REP(i,dim) { REP(j,dim) printf("%2d",A[i][j]); puts(""); }
	B=mpw(A,nplanets);
	return B[0][dim-1];
}

void run() {
	scanf("%d%d%d",&nplanets,&nvisits,&nforward);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}