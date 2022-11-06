#include <bits/stdc++.h>
#define uint unsigned long long
#define ll long long
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
const int M = 1e6 + 10;
const int N = 5e5 + 10;
const int inf = 1e9;
int n, m, r, b;
int S, T, SS, TT, num, tot, ans, sum1;
int a[2][N], cnt[2],X[N],Y[N], sum[2][N];
int head[N << 1], nex[M], to[M], val[M];
int mx[2][N], mn[2][N], du[N << 1];
int Dep[N << 1], pos[N];
queue<int> Q;
int get(int x, int y)
{
    return lower_bound(a[y] + 1, a[y] + 1 + cnt[y], x) - a[y];
}
void add(int x, int y, int z)
{
    nex[++ tot] = head[x];
    head[x] = tot;
    to[tot] = y;
    val[tot] = z;
}
int bfs(int S, int T)
{
    memset(Dep, -1, sizeof(Dep));
    while(!Q.empty()) Q.pop();
    Dep[S] = 0;
    Q.push(S);
    while(!Q.empty())
    {
        int tmp = Q.front();
        Q.pop();
        for(int i = head[tmp]; i; i = nex[i])
            if(Dep[to[i]] == -1 && val[i])
            {
                Dep[to[i]] = Dep[tmp] + 1;
                if(to[i] == T)return 1;
                Q.push(to[i]);
            }
    }
    return 0;
}

int dfs(int x, int mv, int T)
{
    if(x == T) return mv;
    int tmp = 0;
    for(int i = head[x]; i; i = nex[i])
        if(Dep[to[i]] == Dep[x] + 1 && val[i])
        {
            int t = dfs(to[i], min(val[i], mv - tmp), T);
            if(!t) Dep[to[i]] = -1;
            tmp += t;
            val[i] -= t;
            val[i ^ 1] += t;
            if(tmp == mv)break;
        }
    return tmp;
}

int dinic()
{
	int ans = 0;
	while(bfs(S, T))
		ans += dfs(S, inf, T);
	return ans;
}

int main()
{
	n = read();
	m = read();
	r = read();
	b = read();
	tot = 1;
	rep(i, 1, n)
	{
		X[i] = read();
		Y[i] = read();
		a[0][++ cnt[0]] = X[i];
        a[1][++ cnt[1]] = Y[i];
    }
    rep(i, 0, 1)
    {
        sort(a[i] + 1, a[i] + 1 + cnt[i]);
        cnt[i] = unique(a[i] + 1, a[i] + 1 + cnt[i]) - a[i] - 1;
    }
    num = cnt[0] + cnt[1];
    S = ++ num;
    T = ++ num;
    SS = ++ num;
    TT = ++ num;
    rep(i, 1, n)
    {
        X[i] = get(X[i], 0);
        sum[0][X[i]] ++;
        Y[i] = get(Y[i], 1);
        sum[1][Y[i]] ++;
        add(X[i], Y[i] + cnt[0], 1);
        pos[i] = tot;
        add(Y[i] + cnt[0], X[i], 0);
    }
    rep(i, 0, 1)
        rep(j, 1, cnt[i])
            mx[i][j] = sum[i][j];
    rep(i, 1, m)
    {
        int t = read();
        int l = read();
        int d = read();
        t --;
        int t1 = get(l, t);
        if(a[t][t1] != l)continue;
        mx[t][t1] = min(mx[t][t1], (d + sum[t][t1]) / 2);
        mn[t][t1] = max(mn[t][t1], (sum[t][t1] - d + 1) / 2);
        if(mx[t][t1] < mn[t][t1])
        {
            puts("-1");
            return 0;
        }
    }
    rep(i, 1, cnt[0])
    {
        if(mx[0][i] != mn[0][i])
        {
            add(S, i, mx[0][i] - mn[0][i]);
            add(i, S, 0);
        }
        du[i] += mn[0][i];
        du[S] -= mn[0][i];
    }
    rep(i, 1, cnt[1])
    {
        int t = i + cnt[0];
        if(mx[1][i] != mn[1][i])
        {
            add(t, T, mx[1][i] - mn[1][i]);
            add(T, t, 0);
        }
        du[T] += mn[1][i];
        du[t] -= mn[1][i];
    }
    rep(i, 1, T)
        if(du[i])
        {
            if(du[i] > 0) add(SS, i, du[i]),add(i,SS,0),sum1+=du[i];
            else add(i, TT, -du[i]), add(TT,i,0);
        }
    add(T, S, inf);
    add(S, T, 0);
    while(bfs(SS, TT))
        ans += dfs(SS, inf, TT);
    if(ans != sum1) {puts("-1");return 0;}
    ans = dinic();
    printf("%I64d\n", (ll)ans * min(r, b) + (ll)(n - ans) * max(r, b));
    rep(i, 1, n)
    {
        if(!val[pos[i]]) putchar(r < b ? 'r':'b');
        else putchar(r > b ? 'r':'b');
    }
    return 0;
}