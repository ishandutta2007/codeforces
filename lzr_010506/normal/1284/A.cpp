#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define il inline
#define db double
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
const int N = 1010;
string a[N], b[N];
int n, m;
vector<string> ans;
int main()
{
	n = read();
	m = read();
	rep0(i, n) cin >> a[i];
	rep0(i, m) cin >> b[i];
    int q = read();
    int A = 0;
    int B = 0;
    while (1)
    {
    	ans.pb(a[A] + b[B]);
    	A = (A + 1) % n;
    	B = (B + 1) % m;
    	if (ans.size() == n * m) break;
    }
    while (q --)
    {
        int P = read();
        P --;
        P %= (n * m);
        cout << ans[P] << endl;
    }
    
    return 0;
}