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

const int MAXN=18;
const int MOD=998244353;
void inc(int &a,int b) { if((a+=b)>=MOD) a-=MOD; }
void dec(int &a,int b) { inc(a,MOD-b); }

void fmt(int n,vector<int> &a) { REP(bit,n) REP(mask,1<<n) if(mask&(1<<bit)) inc(a[mask],a[mask-(1<<bit)]); }
void ifmt(int n,vector<int> &a) { REP(bit,n) REP(mask,1<<n) if(mask&(1<<bit)) dec(a[mask],a[mask-(1<<bit)]); }
vector<int> inversesubsetconvolution(int n,vector<int> a) {
	assert(a[0]==1);
	vector<int> cnt(1<<n); cnt[0]=0; FOR(mask,1,1<<n) cnt[mask]=cnt[mask>>1]+(mask&1);
	vector<vector<int>> ra(n+1,vector<int>(1<<n,0)); REP(mask,1<<n) ra[cnt[mask]][mask]=a[mask]; REPE(i,n) fmt(n,ra[i]); REP(mask,1<<n) assert(ra[0][mask]==1);
	vector<vector<int>> rb(n+1,vector<int>(1<<n,0)); REPE(i,n) REP(mask,1<<n) { rb[i][mask]=(i==0?1:0); REP(j,i) rb[i][mask]=(rb[i][mask]+MOD-(ll)ra[i-j][mask]*rb[j][mask]%MOD)%MOD; } REPE(i,n) ifmt(n,rb[i]);
	vector<int> b(1<<n); REP(mask,1<<n) b[mask]=rb[cnt[mask]][mask]; return b;
}

int n,m;
int outmask[MAXN];
int inmask[MAXN];
int adjmask[MAXN];

int solve() {
	REP(i,n) adjmask[i]=outmask[i]|inmask[i];
	vector<int> independent(1<<n); REP(i,1<<n) { independent[i]=1; REP(j,n) if((i&(1<<j))!=0&&(adjmask[j]&i)!=0) independent[i]=0; }
	vector<int> signedorientations=inversesubsetconvolution(n,independent);
	int orientations=signedorientations[(1<<n)-1]; if(n%2!=0) orientations=(MOD-orientations)%MOD;
	return (ll)orientations*m%MOD*((MOD+1)/2)%MOD;
}

void run() {
	scanf("%d%d",&n,&m);
	REP(i,n) outmask[i]=inmask[i]=0;
	REP(i,m) { int a,b; scanf("%d%d",&a,&b); --a,--b; outmask[a]|=1<<b,inmask[b]|=1<<a; }
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}