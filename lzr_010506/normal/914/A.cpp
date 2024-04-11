#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define ll long long
#define X first
#define Y second
#define pb push_back
#define mp Maxke_pair
#define pii pair<int, int>
#define ls rt << 1
#define rs rt << 1 | 1
#define sz(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
#define vi vector<int>
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
int a[1010];
int main()
{
	int n = read();
	rep(i, 1, n) a[i] = read();
	sort(a + 1, a + n + 1);
	rrep(i, n, 1)
	{
	    if(a[i] < 0) {cout << a[i]; return 0;}
		if((int)sqrt(a[i]) * (int)sqrt(a[i]) != a[i])
		{cout << a[i]; return 0;}
	}
	return 0;
}