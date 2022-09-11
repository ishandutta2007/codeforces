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

const int MOD=1000000007;
const int MAXEACH=100;


ll want; int each;

const ll MODUNDOOVERFLOW=(1ULL<<63)/MOD*MOD;
vector<vector<int>> mmult(const vector<vector<int>> &a,const vector<vector<int>> &b) {
	int nrow=SZ(a),nmid=SZ(a[0]),ncol=SZ(b[0]); vector<vector<int>> ret(nrow,vector<int>(ncol));
	REP(i,nrow) REP(j,ncol) { ll sum=0; REP(k,nmid) { sum+=(ll)a[i][k]*b[k][j]; if(sum<0) sum-=MODUNDOOVERFLOW; } ret[i][j]=sum%MOD; } return ret;
}
vector<vector<int>> mexp(vector<vector<int>> x,ll n) {
	int dim=SZ(x); vector<vector<int>> ret(dim,vector<int>(dim,0)); REP(i,dim) ret[i][i]=1;
	while(true) { if(n&1) ret=mmult(ret,x); if((n>>=1)==0) return ret; x=mmult(x,x); }
}


int solve() {
	vector<vector<int>> A(each,vector<int>(each,0));
	A[0][0]=1; REP(i,each) A[i][(i+1)%each]=1;
	vector<vector<int>> B=mexp(A,want);
	return B[0][0];
}

void run() {
	scanf("%lld%d",&want,&each);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}