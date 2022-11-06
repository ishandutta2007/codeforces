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
const int N = 5e5 + 10;
vi v[N];
bool used[N];
int ans[N], glub[N];
struct S 
{
    int Xor = 0;
    int add = 0;
    int mx = 0;
    unordered_map<int, int> m;
};
char s[N];
S dfs(int x, int cur = 0) 
{
    S res;
    res.m[0] = 0;
    int nowAns = 0;
    glub[x] = cur;
    for (int to : v[x]) 
    {
        nowAns = max(nowAns, 1);
        auto f = dfs(to, cur + 1);
        nowAns = max(nowAns, ans[to]);
        f.add++;
        char c = s[to];
        f.Xor ^= (1 << c);
        if (f.m.size() > res.m.size()) swap(f, res);
        for (auto p : f.m)
        {
            int key = p.X ^ f.Xor ^ res.Xor;
            int val = p.Y + f.add + res.add;
            if (val + res.mx <= nowAns) continue;
            for (int mask = 0; mask < (1 << 22);) 
            {
                int what = key ^ mask;
                auto it = res.m.find(what);
                if (it != res.m.end()) 
                    nowAns = max(nowAns, val + it->Y);
                if (!mask) mask ++;
                else mask <<= 1;
            }
        }
        for (auto p : f.m)
        {
            int key = p.X ^ f.Xor ^ res.Xor;
            int val = p.Y + f.add - res.add;
            res.mx = max(res.mx, val);
            if (!res.m.count(key)) res.m[key] = val;
            else res.m[key] = max(res.m[key], val);
        }
    }
    ans[x] = nowAns;
    return res;
}
int main() 
{
    int n = read();
    rep(i, 1, n - 1)
	{
        char c;
        int x = read();
        c = getchar();
		x --;
        v[x].pb(i);
        s[i] = c - 'a';
    }
    dfs(0);
    rep0(i, n) printf("%d ", ans[i]);
    return 0;
}