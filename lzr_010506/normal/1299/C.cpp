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
#define INF 0x3f3f3f3f
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
const int N = 1e6 + 10;
int n;
bool cmp(pair<db, db> a, pair<db, db> b)
{
	return a.X * b.Y > a.Y * b.X;
}
stack< pair<db, db> > S;
int a[N]; 
int main()
{
	n = read();
	rep(i, 1, n) a[i] = read();
	rep(i, 1, n)
	{
		pair<db, db> now = mp(a[i], 1);
		while(!S.empty() && cmp(S.top(), now))
		{
			now.X += S.top().X;
			now.Y += S.top().Y;
			S.pop();
		}
		S.push(now);
	}
	vector< pair<db, db> > Ans;
	while(!S.empty()) Ans.pb(S.top()), S.pop();
	reverse(Ans.begin(), Ans.end());
	for(auto x : Ans)
		rep(j, 1, x.Y) 
			printf("%.10lf\n", x.X / x.Y);
	return 0;
}