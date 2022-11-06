#include <bits/stdc++.h>
#define uint unsigned long long
#define ll long long
#define db long double
//#define ls rt << 1
//#define rs rt << 1 | 1
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define vi totor<int>
#define vl totor<ll>
#define rep(i, x, y) for(register int i = x; i <= y; i ++)
#define rrep(i, x, y) for(register int i = x; i >= y; i --)
#define eps 1e-15
#define lb(x) x & -x
#define sz(x) (x).size()
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
const int N = 2e5 + 10;
const int P = 1e9 + 7;
const int inf = 1e9 + 7;
int main()
{
    int n;
    cin >> n;
    if(n < 6) cout << -1 << "\n";
    else
    {
        cout << "1 2\n";
        cout << "2 3\n";
        cout << "2 4\n";
        cout << "3 5\n";
        cout << "3 6\n";
        rep(i, 7, n) cout << 3 << " " << i << "\n";
    }
    rep(i, 2, n) cout << i - 1 << " " << i << "\n";
    return 0;
}