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

inline ll read1()
{
	ll x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int mod = 1e6 + 3;
int f[2010][2010], sum[2010];
vector<int> a;
string ch;
int main()
{
	cin >> ch;
	int now = 0;
	int len = ch.size();
	rep(i, 0, len - 1)
	{
		if(ch[i] < '0' || ch[i] > '9') now ++;
		else if(now) a.pb(now), now = 0;
		if(ch[i] == '*' || ch[i] == '/')
			if(i == 0 || ch[i - 1] < '0' || ch[i - 1] > '9')
				{ cout << 0 << endl; return 0; }
	}
	if(now) { cout << 0 << endl; return 0; }
	f[0][0] = 1;
	int nn = a.size();
	int cnt = 0;
	rep(i, 0, nn - 1)
	{
		int cur = a[i];
		sum[0] = f[i][0];
		rep(j, 1, cnt) sum[j] = (sum[j - 1] + f[i][j]) % mod;
		for(int j = cnt + cur; j >= 0; j --)
            if(j <= cur) f[i + 1][j] = sum[cnt];
            else f[i + 1][j] = (sum[cnt] - sum[j - cur - 1] + mod) % mod;
		cnt += cur;
	}
	cout << f[nn][0] << endl;
	return 0;
}