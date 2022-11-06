#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a, b, c, d;
vector<int> g[5005];
vector<int> nums;
int p, q, r, s;

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
int cnt;
int flag;
void dfs(int v, int par) 
{
    if (v == a) flag = 0;
    if (v == b) flag = 1;
    if (v == c) flag = 2;
    if (v == d) flag = 3;
    int leaf = 1;
    for (int to : g[v]) if (to != par) 
    {
        dfs(to, v);
        leaf = 0;
    }
    cnt += leaf;
}

bool can[15001];

int tot = 0, need;
void solve(int a, int b, int c, int d) 
{
    int from = max(0, need - a - b - c + 2);
    int to = need - b;
    int from2 = max(0, need - b - c - d + 2);
    int to2 = need - c;
    int z = 0;
    for (int i = from; i <= to; i ++)
        if (can[i]) 
        {
            z ++;
            break;
        }
    
    for (int i = from2; i <= to2; i ++) 
        if (can[i])
        {
            z ++;
            break;
        }
    
    if (z == 2) 
    {
        cout << "YES" << endl;
        exit(0);
    }
}

int main() 
{
    n = read();
    a = read();
    b = read();
    c = read();
    d = read();
    a --;
    b --;
    c --;
    d --;
    for (int i = 1; i < n; ++i) 
    {
        int to;
       	to = read();
       	--to;
        g[i].pb(to);
        g[to].pb(i);

    }
    for (int to : g[0]) 
   	{
        cnt = 0;
        flag = -1;
        dfs(to, 0);
        tot += cnt;
        if (flag == 0) p = cnt;
        if (flag == 1) q = cnt;
        if (flag == 2) r = cnt;
        if (flag == 3) s = cnt;
        if (flag == -1) nums.pb(cnt);
    }
    if (tot % 2 == 1) 
    {
        cout << "NO" << endl;
        return 0;
    }
    can[0] = true;
    for (int x : nums)
        for (int i = tot; i >= 0; --i) if (can[i]) 
            can[i + x] = true;
    
    need = tot / 2 - 1;
    a = p;
    b = q;
    c = r;
    d = s;
    solve(a, c, b, d);
    solve(d, a, c, b);
    solve(a, d, b, c);
    solve(c, a, d, b);
    cout << "NO" << endl;
    return 0;
}