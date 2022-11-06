    #include <bits/stdc++.h>
    #define pcc pair<char, char>
    #define pii pair<int, int>
    #define vi vector<int>
    #define vl vector<ll>
    #define rep(i, x, y) for(int i = x; i <= y; i ++)
    #define rrep(i, x, y) for(int i = x; i >= y; i --)
    #define rep0(i, n) for(int i = 0; i < (n); i ++)
    #define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
    #define mp make_pair
    #define pb push_back
    #define ls rt << 1
    #define rs rt << 1 | 1
    #define F fisrt
    #define S second
    #define X fisrt
    #define Y second
    #define inf 0x3f3f3f3f
    #define sz(x) (x).size()
    #define ALL(x) (x).begin(), (x).end()
    #define ll long long
    #define db double
    #define trav(a, x) for(auto& a : x)
    using namespace std;
    namespace IO
    {
    const int sz = 1 << 15;
    char inbuf[sz], outbuf[sz];
    char *pinbuf = inbuf + sz;
    char *poutbuf = outbuf;
    inline char _getchar()
    {
    	if (pinbuf == inbuf + sz)fread(inbuf, 1, sz, stdin), pinbuf = inbuf;
    	return *(pinbuf++);
    }
    inline void _putchar(char x)
    {
    	if (poutbuf == outbuf + sz)fwrite(outbuf, 1, sz, stdout), poutbuf = outbuf;
    	*(poutbuf++) = x;
    }
    inline void flush()
    {
    	if (poutbuf != outbuf)fwrite(outbuf, 1, poutbuf - outbuf, stdout), poutbuf = outbuf;
    }
    }
    #define getchar IO::_getchar
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
    const int N = 1e6 + 5;
    int n, m, q, a[N], opt[N], optx[N], eu[N], ev[N], del[N], ord[N];
    int tot, fa[N], ft[30][N], tms, dfn[N], siz[N], val[N];
    vector<int> e[N];
    int fi[N * 4];
     
    void modify(int rt, int l, int r, int p, int x) 
    {
        if (l + 1 >= r) { fi[rt] = x; return; }
        int mid = l + r >> 1;
        if (p < mid) modify(ls, l, mid, p, x);
        else modify(rs, mid, r, p, x);
        if (a[fi[ls]] > a[fi[rs]])  fi[rt] = fi[ls];
        else fi[rt] = fi[rs];
    }
    void query(int rt, int l, int r, int pl, int pr, int &res)
    {
        if (pl >= pr) return; 
        if (l == pl && r == pr) 
        {
            if (a[fi[rt]] > a[res]) res = fi[rt];
            return;
        }
        int mid = l + r >> 1;
        if (pl >= mid)  query(rs, mid, r, pl, pr, res);
        else if (pr <= mid) query(ls, l, mid, pl, pr, res);
        else query(ls, l, mid, pl, mid, res), query(rs, mid, r, mid, pr, res);
    }
    bool compare(int i, int j) 
    {
        return del[i] < del[j];
    }
     
    int find(int x) 
    {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }
     
    void dfs(int x, int fa) 
    {
        ft[0][x] = fa;
        rep(i, 1, 20) ft[i][x] = ft[i - 1][ft[i - 1][x]];
        dfn[x] = tms ++; 
        siz[x] = 1;
        for (auto v : e[x]) 
    	{	
            dfs(v, x); 
            siz[x] += siz[v];
        }
    }
     
    int main() 
    {
        n = read(); m = read(); q = read();
        rep(i, 1, n) a[i] = read();
        rep(i, 1, m)
        {
            eu[i] = read(); ev[i] = read();
            del[i] = q; ord[i] = i;
        }
       	rep0(i, q)
       	{
            opt[i] = read(); 
            optx[i] = read();
            if (opt[i] == 2) del[optx[i]] = i;
        }
        sort(ord + 1, ord + m + 1, compare);
        rep(i, 1, n * 2) fa[i] = i;
        tot = n;
        rrep(i, m, 1)
        {
            int u = eu[ord[i]], v = ev[ord[i]];
            u = find(u); v = find(v);
            if (u == v) { continue; }
            tot ++; fa[u] = tot; fa[v] = tot; val[tot] = del[ord[i]];
            e[tot].pb(u); e[tot].pb(v);
        }
        rrep(i, tot, 1)
        {
            if (ft[0][i] != 0) continue; 
            dfs(i, 0);
        }
        rep(i, 1, n) modify(1, 0, tms, dfn[i], i);
        rep0(i, q)
    	{
            if (opt[i] == 2) continue; 
            int u = optx[i];
            rrep(j, 20, 0)
                if (val[ft[j][u]] > i) 
                    u = ft[j][u];
            int v = 0;
            query(1, 0, tms, dfn[u], dfn[u] + siz[u], v);
            if (a[v] == 0) { printf("0\n"); continue; }
            printf("%d\n", a[v]);
            a[v] = 0;
            modify(1, 0, tms, dfn[v], 0);
        }
        return 0;
    }