//Dlove's template
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

#define R register
#define ll long long
#define ull unsigned long long
#define db double
#define ld long double
#define sqr(_x) ((_x) * (_x))
#define Cmax(_a, _b) ((_a) < (_b) ? (_a) = (_b), 1 : 0)
#define Cmin(_a, _b) ((_a) > (_b) ? (_a) = (_b), 1 : 0)
#define Max(_a, _b) ((_a) > (_b) ? (_a) : (_b))
#define Min(_a, _b) ((_a) < (_b) ? (_a) : (_b))
#define Abs(_x) (_x < 0 ? (-(_x)) : (_x))

using namespace std;

namespace Dntcry
{
	//char Bs[1 << 22], *Ss = Bs, *Ts = Bs;
	//#define getchar() (Ss == Ts && (Ts = (Ss = Bs) + fread(Bs, 1, 1 << 22, stdin), Ss == Ts) ? EOF : *Ss++) 
	inline int read()
	{
		R int a = 0, b = 1; R char c = getchar();
		for(; c < '0' || c > '9'; c = getchar()) (c == '-') ? b = -1 : 0;
		for(; c >= '0' && c <= '9'; c = getchar()) a = (a << 1) + (a << 3) + c - '0';
		return a * b;
	}
	inline ll lread()
	{
		R ll a = 0, b = 1; R char c = getchar();
		for(; c < '0' || c > '9'; c = getchar()) (c == '-') ? b = -1 : 0;
		for(; c >= '0' && c <= '9'; c = getchar()) a = (a << 1) + (a << 3) + c - '0';
		return a * b;
	}
	const int Maxn = 100010, INF = 1 << 30;
	const db pi = acos(-1);
	struct Complex
	{
		db real, imag;
		Complex operator + (const Complex &b) const
		{
			return (Complex){real + b.real, imag + b.imag};
		}
		Complex operator - (const Complex &b) const
		{
			return (Complex){real - b.real, imag - b.imag};
		}
		Complex operator * (const Complex &b) const
		{
			return (Complex){real * b.real - imag * b.imag, b.real * imag + real * b.imag};
		}
	}A[Maxn], B[Maxn], W[150010], wl;
	void FFT(R Complex *A, R int bit, R int opt)
	{
		static int rev[Maxn], len = 0;
		R int tmp = 1 << bit;
		if(tmp != len)
		{
			len = tmp;
			for(R int i = 0; i < len; i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << bit - 1);
		}
		for(R int i = 0; i < len; i++)
			if(i < rev[i]) swap(A[i], A[ rev[i] ]);
		R Complex *w;
		for(R int i = 2; i <= len; i <<= 1)
		{
			for(R int j = 0, step = i >> 1; j < len; j += i)
			{
				w = W + step;
				for(R int k = j; k < j + step; w++, k++)
				{
					R Complex x = A[k], y = *w * A[k + step];
					A[k] = x + y;
					A[k + step] = x - y;
				}	
			}
		}
		if(opt == -1) 
			for(R int i = 0; i < len; i++) A[i].real /= 1.0 * len, A[i].imag /= 1.0 * len;
	}
	struct node
	{
		int x, y, z;
	}s[210];
	int n, m, T, X;
	db d[60][60], f[60][Maxn], g[210][Maxn], p[210][20010];
	void update(R int l, R int mid, R int r)
	{
		R int len = r - l;
	    for(R int j = 1; j <= m; j++)
		{
	        R int bit = ceil(log2(len + r - mid));
	        fill(A, A + (1 << bit), (Complex){0, 0});
			fill(B, B + (1 << bit), (Complex){0, 0});
	        for(R int i = 0; i < r - mid + 1; i++) A[i].real = f[ s[j].y ][r - i];
	    	for(R int i = 0, lim = Min(T, len); i < lim; i++) B[i].real = p[j][i + 1];
	    	FFT(A, bit, 1), FFT(B, bit, 1);
	        for(R int i = 0; i < (1 << bit); i++) A[i] = A[i] * B[i];
	        reverse(A + 1, A + (1 << bit));
	        FFT(A, bit, -1);
	        for(R int i = mid - 1; i >= l; i--) g[j][i] += A[r - i - 1].real;
		}
	}
	void Solve(R int l, R int r)
	{
		if(l == r)
		{
	        for(R int i = 1; i <= m; i++) 
				f[ s[i].x ][l] = Min(f[ s[i].x ][l], s[i].z + g[i][l]);
	        return;
	    }
	    R int mid = l + r >> 1;
	    Solve(mid + 1, r);
	    update(l, mid + 1, r);
	    Solve(l, mid);
	}
	int Main()
	{
		n = read(), m = read(), T = read(), X = read();
		for(R int i = 1; i <= n; i++)
			for(R int j = 1; j <= n; j++)
				if(i ^ j) d[i][j] = INF;
		for(R int i = 1; i <= m; i++)
		{
			R int x = read(), y = read(), z = read();
	        s[i] = (node){x, y, z};
	        d[x][y] = Min(d[x][y], 1.0 * z);
	        for(R int j = 1; j <= T; j++) p[i][j] = (db)read() / 100000; 
		}
	    for(R int k = 1; k <= n; k++)
	    	for(R int i = 1; i <= n; i++)
	    		for(R int j = 1; j <= n; j++)
	    			d[i][j] = Min(d[i][j], d[i][k] + d[k][j]);
    	for(R int i = T + 1; i <= 2 * T; i++) f[n][i] = X;
	    for(R int i = 1; i < n; i++)
		{
	        for(R int j = 0; j <= T; j++) f[i][j] = INF;
	        for(R int j = T + 1; j <= 2 * T; j++) f[i][j] = d[i][n] + X;
	    }
		R int l = 131072;
	    R int tmp = l >> 1;
		W[tmp] = (Complex) {1.0, 0.0};
		wl = W[++tmp] = (Complex) {cos(2.0 * pi / l), sin(2.0 * pi / l)};
		for(tmp++; tmp < l; tmp++) W[tmp] = (Complex) {cos(2.0 * pi * (tmp - (l >> 1)) / l), sin(2.0 * pi * (tmp - (l >> 1)) / l)};
		for(R int i = (l >> 1) - 1; i; i--) W[i] = W[i << 1];
	    update(1, T + 1, 2 * T);
	    Solve(0, T);
	    printf("%.10f", f[1][0]);
		return 0;
	}
}
int main()
{
	return Dntcry :: Main();
}