#include <bits/stdc++.h>
#define uint unsigned long long
#define ll long long
#define db long double
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
#define ept 1e-9
#define INF 0x3f3f3f3f
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


int N;
ll X[100005], Y[100005];

bool coll(int a, int b, int c)
{
    return X[a] * (Y[b] - Y[c]) + X[b] * (Y[c] - Y[a]) + X[c] * (Y[a] - Y[b]) == 0;
}

bool allcoll(vector<int> &v)
{
    if(sz(v) < 3) return true;
    rep(i,2,sz(v)-1) if(!coll(v[0], v[1], v[i])) return false;
    return true;
}

bool ok(int a, int b)
{
    vector<int> v;
    rep(c, 1, N) if(c != a && c != b) if(!coll(a,b,c)) v.pb(c);
    return allcoll(v);
}

int main()
{
    cin >> N;
    rep(i,1,N) cin >> X[i] >> Y[i];
    if(ok(1,2) || ok(1,3) || ok(2,3)) cout << "YES";
    else cout << "NO";
}