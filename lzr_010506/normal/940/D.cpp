#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define ll long long
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define pii pair<ll, ll>
#define ls rt << 1
#define rs rt << 1 | 1
#define sz(x) (int)(x).size()
#define ALL(x) (x).insgin(), (x).end()
#define lson (p << 1)
#define rson (p << 1 | 1)
#define vi vector<int>
#define EPS 1e-8
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


const int N = 1e5 + 10;
char b[N];
int a[N];

ll r = 1e9, l = -1e9;

int main()
{
    int n = read();
    rep(i, 1, n) a[i] = read();
    scanf("%s", b + 1);
    rep(i, 5, n)
    {
        if (b[i] == '0') 
        {
            if (b[i - 1] != '0')
                r = min(min(a[i], min(min(a[i - 1], a[i - 2]), min(a[i - 3], a[i - 4]))) - 1ll, r);
        } 
        else 
        {
            if (b[i - 1] != '1')
                l = max(max(a[i], max(max(a[i - 1], a[i - 2]), max(a[i - 3], a[i - 4]))) + 1ll, l);
        }
    }
    cout << l << ' ' << r << endl;
}