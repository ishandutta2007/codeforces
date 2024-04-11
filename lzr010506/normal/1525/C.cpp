#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define il inline
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define ept 1e-9
#define sz(x) (x).size()
#define ALL(x) (x).begin(), (x).end()
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
inline ll read1()
{
	ll x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int mod = 998244353;
const int N = 300005;
int n, m, x[N], ans[N];
char d[N];
pii O[N], E[N];
int st1[N], st2[N];
bool cmp(pair<int, int> A, pair<int, int> B) 
{
	return x[A.X] < x[B.X];
}
int main() 
{
	int T = read();
	while(T --)
	{
		n = read(); m = read();
		rep0(i, n) x[i] = read();
		rep0(i, n)
		 {
			d[i] = getchar();
			while (d[i] == ' ' || d[i] == '\n') d[i] = getchar();
		}
		int nn = 0, mm = 0;
		rep0(i, n)
		{
			if (x[i] & 1) 
			{
				if (d[i] == 'L') O[nn ++] = mp(i, 0); 
				else O[nn ++] = mp(i, 1);
			}
			else 
			{
				if (d[i] == 'L') E[mm ++] = mp(i, 0);
				else E[mm ++] = mp(i, 1);
			}
		}
		sort(O, O + nn, cmp);
		sort(E, E + mm, cmp);
		rep0(i, n) ans[i] = -1;
		int n1 = 0, n2 = 0;
		rep0(i, nn)
		{
			if (O[i].Y == 1) st2[n2 ++] = O[i].X;
			else 
			{
				if (n2 == 0) st1[n1 ++] = O[i].X;
				else 
				{
					int id = st2[-- n2];
					ans[id] = ans[O[i].X] = (x[O[i].X] - x[id]) >> 1;
				}
			}
		}

		for (int i = 0; i < n1; i += 2) 
		{
			if (i == n1 - 1) break;
			int A = st1[i], B = st1[i + 1];
			ans[A] = ans[B] = (x[B] - x[A]) / 2 + x[A];
		}
		for (int i = n2 - 1; i >= 0; i -= 2) 
		{
			if (i == 0) break;
			int A = st2[i], B = st2[i - 1];
			ans[A] = ans[B] = (x[A] - x[B]) / 2 + (m - x[A]);
		}
		if (n1 % 2 == 1 && n2 % 2 == 1) 
		{
			int A = st1[n1 - 1], B = st2[0];
			ans[A] = ans[B] = (m + m - x[B] + x[A]) / 2;
		}
		n1 = 0;
		n2 = 0;
		rep0(i, mm)
		{
			if (E[i].Y == 1) st2[n2 ++] = E[i].X;
			else 
			{
				if (n2 == 0) st1[n1 ++] = E[i].X;
				else 
				{
					int id = st2[-- n2];
					ans[id] = ans[E[i].X] = (x[E[i].X] - x[id]) >> 1;
				}
			}
		}
		for (int i = 0; i < n1; i += 2)
		{
			if (i == n1 - 1) break;
			int A = st1[i], B = st1[i + 1];
			ans[A] = ans[B] = (x[B] - x[A]) / 2 + x[A];
		}
		for (int i = n2 - 1; i >= 0; i -= 2) 
		{
			if (i == 0) break;
			int A = st2[i], B = st2[i - 1];
			ans[A] = ans[B] = (x[A] - x[B]) / 2 + (m - x[A]);
		}
		if (n1 % 2 == 1 && n2 % 2 == 1) 
		{
			int A = st1[n1 - 1], B = st2[0];
			ans[A] = ans[B] = (m + m - x[B] + x[A]) / 2;
		}
		rep0(i, n) printf("%d ", ans[i]);
		puts("");
	}
	
}