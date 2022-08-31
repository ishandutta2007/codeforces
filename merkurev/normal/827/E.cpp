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
#include <complex>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif






//int MOD;
double pi = atan2(0., -1.);
const int LOG = 20;
const int SZ = (1 << LOG);

int rev[SZ];
complex <double> alpha[SZ];

void initFFT()
{
	for (int i = 1; i < SZ; i++)
	{
		int it = 0;
		while (!(i & (1 << it) ) ) it++;
		rev[i] = rev[i ^ (1 << it) ] ^ (1 << (LOG - it - 1) );
	}
	for (int i = 0; i < SZ; i++)
	{
		double x = pi * i / (double) SZ;
		alpha[i] = complex <double> (cos(x), sin(x) );
	}
}

vector <complex <double> > FFT(vector <complex <double> > &st)
{
	int n = (int) st.size();
	int k = 0;
	while ( (1 << k) < n) k++;
	if ( (1 << k) != n) throw;
	vector <complex <double> > v, oth;
	oth.resize(n);
	v.resize(n);
	for (int i = 0; i < n; i++)
		v[rev[i] >> (LOG - k) ] = st[i];

	for (int it = LOG - k; it < LOG; it++)
	{
		int half = (n >> (LOG - it) );
		for (int pos = 0; pos < n; pos += (half << 1) )
		{
			for (int i = 0; i < half; i++)
			{
				complex <double> a = v[pos + i];
				complex <double> b = v[pos + half + i] * alpha[i << (LOG - k + LOG - it)];
				oth[pos + i] = a + b;
				oth[pos + half + i] = a - b;
			}
		}
		v.swap(oth);
	}
	
	return v;
}

vector <complex <double> > FFT(const vector <int> &v, int n)
{
	vector <complex <double> > cv(n, 0.);
	for (int i = 0; i < (int) v.size(); i++)
		cv[i] = complex <double> (v[i] );
	
	return FFT(cv);
}


vector <int> mulFFT(const vector <int> &a, const vector <int> &b)
{
	int n = (int) a.size() + (int) b.size();
	while (n & (n - 1) ) n++;

	vector <complex <double> > A = FFT(a, n);
	vector <complex <double> > B = FFT(b, n);

	for (int i = 0; i < n; i++)
		A[i] *= B[i];

	B = FFT(A);
	reverse(B.begin() + 1, B.end() );
	for (auto &it : B)
		it /= n;

//	eprintf("1\n");
	vector <int> ans;
	ans.resize(n);
//	eprintf("2\n");
//	eprintf("%d\n", (int) ans.size() );
//	eprintf("%d n = %d\n", (int) B.size(), n);
	for (int i = 0; i < n; i++)
		ans[i] = ((long long) (B[i].real() + 0.5));// % MOD;
//	eprintf("3\n");


	return ans;
}


void testFFT()
{
//	MOD = 1235121;

	vector <int> a = {1, 1, 0, 0, 0, 0, 0, 0, 0, 0};
	vector <int> ans = mulFFT(a, a);

	for (int x : ans)
		eprintf("%d ", x);
	eprintf("\n");
}


char str[SZ];
bool bad[SZ];

void solve()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		bad[i] = false;
	scanf("%s", str);
	vector <int> a, b;
	a.resize(n, 0);
	b.resize(n, 0);
	for (int i = 0; i < n; i++)
		if (str[i] == 'V')
			a[i] = 1;
		else if (str[i] == 'K')
			b[n - i - 1] = 1;

//	eprintf("??\n");
	vector <int> ans = mulFFT(a, b);
//	eprintf("!!\n");

	for (int i = 0; i < 2 * n - 1; i++)
		if (ans[i] )
			bad[abs((n - 1) - i)] = true;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 2; !bad[i] && i * j <= n; j++)
			if (bad[i * j] ) bad[i] = true;
	}
	vector <int> answ;
	for (int i = 1; i <= n; i++)
		if (!bad[i] )
			answ.push_back(i);
	printf("%d\n", (int) answ.size() );
	for (int x : answ)
		printf("%d ", x);
	printf("\n");
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	initFFT();

	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
		solve();

	return 0;
}