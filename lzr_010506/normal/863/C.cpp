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
ll k;
int a, b;
int A[4][4], B[4][4];

int sheng(int x, int y)
{
	if(x == y) return -1;
	if(x == 1 && y == 2) return 1;
	if(x == 1 && y == 3) return 0;
	if(x == 2 && y == 3) return 1;
	if(x == 2 && y == 1) return 0;
	if(x == 3 && y == 1) return 1;
	if(x == 3 && y == 2) return 0;
}

int main()
{
	cin >> k >> a >> b;
	rep(i, 1, 3)
		rep(j, 1, 3)
			cin >> A[i][j];

	rep(i, 1, 3)
		rep(j, 1, 3)
			cin >> B[i][j];

	vector<pii> v;
	v.pb(mp(a, b));
	ll l = 0, r = 0, p = 0, q = 0, len = 1;
	while(1)
	{
		if((int)v.size() - 1 == k - 1) break;
		int x = A[a][b];
		int y = B[a][b];
		rep(j, 0, (int)v.size() - 1)
			if(x == v[j].X && y == v[j].Y)
			{
				len = v.size() - j;
				rep(i, j, v.size() - 1)
					if(sheng(v[i].X, v[i].Y) == 1) q ++;
					else if(sheng(v[i].X, v[i].Y) == 0) p ++;
				rep(i, 0, j - 1)
					if(sheng(v[i].X, v[i].Y) == 1) r ++;
					else if(sheng(v[i].X, v[i].Y) == 0) l ++;
				k -= j;
				goto L1;
			}
		v.pb(mp(x, y));
		a = x;
		b = y;
	}
	rep(i, 0, v.size() - 1)
		if(sheng(v[i].X, v[i].Y) == 1) r ++;
		else if(sheng(v[i].X, v[i].Y) == 0) l ++;
	cout << l << " " << r << endl;
	return 0;
	L1:;
	ll num = k / len;
	ll rest = k % len;
	l += p * num;
	r += q * num;
	while(rest --)
	{
		int x = A[a][b];
		int y = B[a][b];
		if(sheng(x, y) == 1) r ++;
		else if(sheng(x, y) == 0) l ++;
		a = x;
		b = y;
	}
	cout << l << " " << r << endl;
	return 0;
}