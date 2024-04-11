#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ls rt << 1
#define rs rt << 1 | 1
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define eps 1e-9
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
int T;
ll a, b;
bool check()
{
	a = read();
	b = read();
	long double lim = (pow((long double)a * b, 1.0 / 3));
	ll x = a / lim, y = b / lim;
	return x * x * y == a && x * y * y == b;
}
int main()
{
	T = read();
	while (T --)
		puts(check() ? "Yes" : "No");
	return 0;
}