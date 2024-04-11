#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define FOR(i, a, b) for (int i = (a), _end_ = (b); i <= _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define EXIT(...) printf(__VA_ARGS__), exit(0)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;

template<typename T> T &Read(T &x)
{
    static char c;
    while (!isdigit(c = getchar()));
    x = c - '0';
    while (isdigit(c = getchar())) (x *= 10) += c - '0';
    return x;
}

const int maxn = 200000;

int fa[maxn + 5];

int _fa[maxn + 5];

int n, q;

int find(const int &x, int *fa) { return fa[x] == x ? x : fa[x] = find(fa[x], fa); }

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &q);
    REP(i, 0, n) fa[i] = _fa[i] = i;
    REP(i, 0, q)
    {
        int ty, x, y;
        scanf("%d%d%d", &ty, &x, &y), --x, --y;
        if (ty == 3)
        {
            puts(find(x, fa) == find(y, fa) ? "YES" : "NO");
        }
        else if (ty == 1) fa[find(x, fa)] = find(y, fa);
        else
        {
            for (int i = find(x, _fa), nxt; i < y; i = nxt)
            {
                nxt = find(i + 1, _fa);
                _fa[i] = nxt;
                fa[find(i, fa)] = find(i + 1, fa);
            }
        }
    }
    return 0;
}