#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;

int mod;
void sadd(int &a, int b)
{
	a += b;
	if (a >= mod)
		a -= mod;
}
int add(int a, int b)
{
	sadd(a, b);
	return a;
}
int mul(int a, int b)
{
	return (a * 1LL * b) % mod;
}
void smul(int &a, int b)
{
	a = mul(a, b);
}
int fpow(int x, int n)
{
	if (n == 0) return 1;
	int a = fpow(x, n >> 1);
	smul(a, a);
	if (n & 1)
		smul(a, x);
	return a;
}
int rev(int x)
{
	return fpow(x, mod - 2);
}
int _div(int a, int b)
{
	return mul(a, rev(b) );
}
void sdiv(int &a, int b)
{
	smul(a, rev(b) );
}

const int N = 1005;
const int D = 11;
int n, d;

int dpTree[N][D];
int dpForestEq[D][N];
int dpForest[N][D][N];

int getTree(int v, int rd);
int getForest(int vs, int rs, int md);
int getForestEq(int cnt, int vone);

int C(int a, int b)
{
//	eprintf("! C %d %d\n", a, b);
	int ans = 1;
	for (int i = 0; i < b; i++)
	{
		smul(ans, (a - i + mod) % mod);
		sdiv(ans, i + 1);
	}
	eprintf("C a = %d b = %d : %d\n", a, b, ans);
	return ans;
}

int place(int cnt, int diff)
{
	return C(cnt - 1, diff - 1);
}

int getSplit(int k, int cnt)
{
//	eprintf("! getSplit k = %d, cnt %d\n", k, cnt);
	if (cnt == 0) return 1;
	int ans = 0;
	for (int diff = 1; diff <= min(cnt, k); diff++)
		sadd(ans, mul(C(k, diff), place(cnt, diff) ) );
	eprintf("getSplit k = %d cnt = %d : %d\n", k, cnt, ans);
	return ans;
}

int getForestEq(int cnt, int vone)
{
	eprintf("! getForestEq cnt = %d, vone = %d\n", cnt, vone);
	int &ans = dpForestEq[cnt][vone];
	if (ans != -1)
		return ans;
	if (vone <= 0) return ans = 0;
	int k = ((cnt == 0) ? 1 : getTree(vone, d - 1));
	ans = getSplit(k, cnt);
	eprintf("! getForestEq cnt = %d, vone = %d : %d\n", cnt, vone, ans);
	return ans;
}

int getForest(int vs, int rs, int md)
{
	eprintf("! getForest vs = %d, rs = %d, md = %d\n", vs, rs, md);
	int &ans = dpForest[vs][rs][md];
	if (ans != -1)
		return ans;
	if (vs == 0 && rs == 0) return 1;
	if (md == 0) return 0;
	if (rs > vs) return 0;
	if (rs * md < vs) return 0;
	int curans = 0;
	for (int cnt = 0; cnt * md <= vs && cnt <= rs; cnt++)
	{
//		eprintf("cnt = %d, ans = %d\n", cnt, ans);
		sadd(curans, mul(getForest(vs - cnt * md, rs - cnt, md - 1), getForestEq(cnt, md) ) );
	}
	eprintf("getForest vs = %d, rs = %d, md = %d : %d\n", vs, rs, md, ans);
	return ans = curans;
}

int getTree(int vs, int rd)
{
	eprintf("getTree vs = %d, rd = %d\n", vs, rd);
	int &ans = dpTree[vs][rd];
	if (ans != -1)
		return ans;
	if (vs == 0)
		return 0;
	ans = getForest(vs - 1, rd, (n - 1) / 2);
	eprintf(">>>> getTree vs = %d, rd = %d : %d\n", vs, rd, ans);
	return ans;
}

int main(int,  char **)
{
	memset(dpForest, -1, sizeof dpForest);
	memset(dpForestEq, -1, sizeof dpForestEq);
	memset(dpTree, -1, sizeof dpTree);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d", &n, &d, &mod);
	
	dpTree[1][d] = 1;
	dpTree[1][d - 1] = 1;


//	getForestEq(1, 3);
//	getForest(1, 2, 1);
//	return 0;

//	getForest(2, 2, 1);
//	getTree(3, 2);
//	return 0;
	
	int ans = 0;
	sadd(ans, getTree(n, d) );
	if (n % 2 == 0)
		sadd(ans, getForestEq(2, n / 2) );
	printf("%d\n", ans);

	return 0;
}