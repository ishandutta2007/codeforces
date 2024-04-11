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

const int N = (int) 5e5 + 100;
char str[N];

const int mod = (int) 1e9 + 7;

void add(int &a, int b)
{
	a += b;
	if (a >= mod)
		a -= mod;
}
int mul(int a, int b)
{
	return (a * 1LL * b) % mod;
}

int dx[N], dy[N];
int mdx[N], Mdx[N], mdy[N], Mdy[N];

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int n, h, w;
	scanf("%d%d%d", &n, &h, &w);
	scanf("%s", str);

	for (int i = 0; i < n; i++)
	{
		dx[i + 1] = dx[i];
		dy[i + 1] = dy[i];
		if (str[i] == 'U')
			dy[i + 1]++;
		if (str[i] == 'D')
			dy[i + 1]--;
		if (str[i] == 'L')
			dx[i + 1]--;
		if (str[i] == 'R')
			dx[i + 1]++;

		mdx[i + 1] = min(dx[i + 1], mdx[i] );
		Mdx[i + 1] = max(dx[i + 1], Mdx[i] );
		mdy[i + 1] = min(dy[i + 1], mdy[i] );
		Mdy[i + 1] = max(dy[i + 1], Mdy[i] );
	}

	if (dx[n] == 0 && dy[n] == 0 && Mdx[n] - mdx[n] + 1 <= w && Mdy[n] - mdy[n] + 1 <= h)
	{
		printf("-1\n");
		return 0;
	}

	int l = 1, r = w;
	int d = 1, u = h;

	int ans = 0;

	long long t = 0;
	long long MT = N * 1LL * N;

	while (true)
	{
		long long bl = t;
		long long br = MT;

		while (br - bl > 1)
		{
			long long bm = (bl + br) / 2;
		
			long long full = bm / n;
			long long rem = bm % n;
			long long _mdx = dx[n] * full + mdx[rem];
			long long _Mdx = dx[n] * full + Mdx[rem];
			long long _mdy = dy[n] * full + mdy[rem];
			long long _Mdy = dy[n] * full + Mdy[rem];
			if (full != 0)
			{
				_mdx = min(_mdx, dx[n] * (full - 1) + mdx[n] );
				_Mdx = max(_Mdx, dx[n] * (full - 1) + Mdx[n] );
				_mdy = min(_mdy, dy[n] * (full - 1) + mdy[n] );
				_Mdy = max(_Mdy, dy[n] * (full - 1) + Mdy[n] );
				
				_mdx = min(_mdx, (long long) mdx[n] );
				_Mdx = max(_Mdx, (long long) Mdx[n] );
				_mdy = min(_mdy, (long long) mdy[n] );
				_Mdy = max(_Mdy, (long long) Mdy[n] );
			}
				
			if (l + _mdx < 1 || d + _mdy < 1 || r + _Mdx > w || u + _Mdy > h)
				br = bm;
			else
				bl = bm;
		}
//		eprintf("ans = %d\n", ans);
//		eprintf("t = %lld, nt = %lld, [%d .. %d] x [%d .. %d]\n", t, br, l, r, d, u);
		add(ans, mul(br - t, mul(r - l + 1, u - d + 1) ) );
//		eprintf("ans = %d\n", ans);
		t = br;

		long long full = br / n;
		long long rem = br % n;
		long long _mdx = dx[n] * full + mdx[rem];
		long long _Mdx = dx[n] * full + Mdx[rem];
		long long _mdy = dy[n] * full + mdy[rem];
		long long _Mdy = dy[n] * full + Mdy[rem];
		if (full != 0)
		{
			_mdx = min(_mdx, dx[n] * (full - 1) + mdx[n] );
			_Mdx = max(_Mdx, dx[n] * (full - 1) + Mdx[n] );
			_mdy = min(_mdy, dy[n] * (full - 1) + mdy[n] );
			_Mdy = max(_Mdy, dy[n] * (full - 1) + Mdy[n] );
			
			_mdx = min(_mdx, (long long) mdx[n] );
			_Mdx = max(_Mdx, (long long) Mdx[n] );
			_mdy = min(_mdy, (long long) mdy[n] );
			_Mdy = max(_Mdy, (long long) Mdy[n] );
		}
		
		long long _l = max(0LL, 1 - (l + _mdx) );
		long long _r = max(0LL, (r + _Mdx) - w);
		long long _d = max(0LL, 1 - (d + _mdy));
		long long _u = max(0LL, (u + _Mdy) - h);

		l += _l;
		r -= _r;
		d += _d;
		u -= _u;

		if (l > r || d > u)
			break;
	}

	printf("%d\n", ans);

	return 0;
}