#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define ll long long
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define ls rt << 1
#define rs rt << 1 | 1
#define mod 1000000007
#define sz(x) (int)(x).size()
#define vi vector<int>
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
int n, T;
const int N = 200010;
struct Node
{
    int a, t, id;
} p[N];
bool operator < (Node a, Node b)
{
    if (a.t == b.t) return a.id < b.id;
    return a.t < b.t;
}
vi ans;
int main()
{
	n = read();
	T = read();
	rep(i, 1, n) p[i].id = i;
	rep(i, 1, n) p[i].a = read(), p[i].t = read();
	int l = 0, r = n;
    sort(p + 1, p + n + 1);
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        int cnt = 0, sum = 0;
        rep(i, 1, n)
            if (p[i].a >= mid)
            {
                sum += p[i].t;
                cnt ++;
                if (cnt >= mid) break;
            }
        if (cnt < mid)
        {
            r = mid - 1;
            continue;
        }
        if (sum <= T)
        {
            l = mid + 1;
            ans.clear();
            cnt = 0;
            rep(i, 1, n)
                if (p[i].a >= mid)
                {
                    ans.pb(p[i].id);
                    cnt ++;
                    if (cnt >= mid) break;
                }
        }
        else r = mid - 1;
    }
    printf("%d\n%d\n", sz(ans), sz(ans));
    rep(i, 0, sz(ans) - 1) printf("%d ", ans[i]);
    puts("");
    return 0;
}