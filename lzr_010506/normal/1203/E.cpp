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
#define All(x) (x).begin(), (x).end()
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
int n, a[200010];
set<int> st;
int main()
{
	n = read();
	rep(i, 1, n) a[i] = read();
	sort(a + 1, a + n + 1);
	st.insert(0);
	rep(i, 1, n)
	{
		if(st.count(a[i]) == 1)
		{
			if(st.count(a[i] - 1) == 1) st.insert(a[i] + 1);
			else if(a[i] != 1) st.insert(a[i] - 1);
		} 
		else
		{
			if(st.count(a[i] - 1) == 0) st.insert(a[i] - 1);
			else st.insert(a[i]);
		}
	}
	cout << st.size() - 1;

	return 0;
}