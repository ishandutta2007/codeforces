#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define ll long long
#define ull unsigned long long
#define db double
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define pii pair<ll, ll>
#define ls rt << 1
#define rs rt << 1 | 1
#define sz(x) (int)(x).size()
#define ALL(x) (x).insgin(), (x).end()
#define vi vector<int>
#define EPS 1e-8
using namespace std;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
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
vector<int> v[26];
char ch[5010];
int len, vis[26];

int main()
{
    scanf("%s", ch);
    len = (int) strlen(ch);
    rep(i, 0, len - 1)
    	v[ch[i] - 'a'].pb(i);
    int ans = 0;
    rep(t, 0, 25)
    {
        int mx = 0;
        rep(i, 1, len - 1)
        {
            int nans = 0;
            memset(vis, 0, sizeof(vis));
            rep(k, 0, sz(v[t]) - 1)
            {
                int tin = (v[t][k] + i) % len;
                vis[ch[tin] - 'a'] ++;
            }
            rep(j, 0, 25) if (vis[j] == 1) nans ++;
            if (nans > mx) mx = nans;
        }
        ans += mx;
    }
    printf("%.10lf", (double)ans / len);
    return 0;
}