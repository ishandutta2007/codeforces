/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream> 
#include <fstream> 
#include <sstream> 
#include <cstdio> 
#include <cstring> 
#include <cstdlib> 
#include <cmath> 
#include <ctime> 
#include <algorithm> 
#include <vector> 
#include <queue> 
#include <deque> 
#include <stack> 
#include <set> 
#include <map> 
#include <complex> 
#include <bitset> 
#include <iomanip> 
#include <utility> 

using namespace std;

int C[110][110];
int n,mod;
int b[1<<20],init[1<<20];
int eff[1<<20][21];
long long t;

struct mat{
	int n,m;
	vector < vector <int> > a;
	mat () {}
	mat (int nn, int mm, bool h = false){
		n = nn, m = mm;
		a = vector < vector <int> > (n, vector <int>(m, 0));
		if (h)
			for (int i=0; i<n; i++)
				a[i][i] = 1;
	}
}res;

mat mul (const mat &A, const mat &B){
	mat ret(A.n, B.m);
	for (int i=0; i<ret.n; i++)
		for (int j=0; j<ret.m; j++)
			for (int k=0; k<A.m; k++)
				ret.a[i][j] = (ret.a[i][j] + A.a[i][k] * (long long)B.a[k][j]) % mod;
	return ret;
}

mat POW (const mat &base, long long p){
	mat cur = base;
	mat ret(base.n, base.m, true);
	while (p){
		if (p & 1) ret = mul(ret, cur);
		p>>=1;
		cur = mul(cur,cur);
	}
	return ret;
}

void solve (int lo, int hi){
	if (lo == hi){
		for (int i=0; i<=n; i++)
			eff[lo][i] = ((long long)res.a[i][0] * init[lo]) % mod;
		return;
	}
	int mid = (lo + hi) / 2;
	solve(lo, mid);
	solve(mid+1,hi);
	int len = (hi-lo+1) / 2;
	for (int j=0; j<n; j++)
		for (int i=lo; i<=hi; i++)
			eff[i][j] = (eff[i][j] + eff[i ^ len][j+1]) % mod;
}

int main(){
	scanf("%d%I64d%d", &n, &t, &mod);
	for (int i=0; i<100; i++){
		C[i][0] = 1;
		for (int j=1; j<=i; j++)
			C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
	}
	for (int i=0; i<(1<<n); i++)
		scanf("%d", &init[i]);
	for (int i=0; i<=n; i++)
		scanf("%d", &b[i]);
	mat base(n+1, 1);
	base.a[0][0] = 1;
	mat comb(n+1,n+1);
	for (int i=0; i<=n; i++)
		for (int j=0; j<=n; j++)
			for (int t=0; t<=n; t++) if ((j+i)%2 == t%2){
				int y = (t + j - i) / 2;
				int x = j - y;
				if (x>=0 && y>=0 && x+y==j && x<=i && y<=(n-i) && (i-x)+y==t){
					comb.a[i][j] = (comb.a[i][j] + b[t] * (long long)C[i][x] % mod * (long long)C[n-i][y]) % mod;
				}
			}
	res = mul(POW(comb, t), base);
	solve(0, (1<<n)-1);
	for (int i=0; i<(1<<n); i++)
		printf("%d\n", eff[i][0]);
	return 0;
}