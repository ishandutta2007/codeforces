#include <bits/stdc++.h>
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define eps 1e-9
#define all(x) (x).begin(), (x).end()
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
int n, q, m;
int a[200010];
int t[200010], l[200010], r[200010];
int main()
{
	n = read();
	q = read();
	m = read();
	rep(i, 1, n)
		a[i] = read();
	rep(i, 1, q)
		t[i] = read(), l[i] = read(), r[i] = read();
	rep(tt, 1, m)
	{
		int x = read();
		rrep(i, q, 1)
			if(l[i] <= x && r[i] >= x)
			{
				if(t[i] == 1)
				{
					if(x == l[i]) x = r[i];
					else x --;
				}
				else x = r[i] - x + l[i];
			}
		cout << a[x] << " ";
	}
	return 0;
}