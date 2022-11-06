#include <bits/stdc++.h>
#define N 200010
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
using namespace std;
const int inf = 1011111111;

int n, w, k, a[N], t[N], sum[2][N], used[N];
int sum_mx, TT[N];
set<pii> q, s;

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

int get_sum(int tp, int l, int r)
{
    if (l == 0) return sum[tp][r];
    return sum[tp][r] - sum[tp][l - 1];
}

void add(int x, int pos)
{
    //cout << "+ " << x << " " << pos << endl;
    q.insert(mp(x, pos));
    sum_mx += x;
    if (q.size() > w)
    {
        pii mn = *q.begin();
        q.erase(q.find(mn));
        s.insert(mn);
        sum_mx -= mn.X;
    }
}

void err(int x, int pos)
{
    if (q.count(mp(x, pos)))
    {
        sum_mx -= x;
        q.erase(mp(x, pos));
    }
    if (s.count(mp(x, pos))) s.erase(mp(x, pos));
    if (s.size() && q.size() < w)
    {
        pii p = *s.rbegin();
        q.insert(p);
        s.erase(p);
        sum_mx += p.X;
    }
}

int main()
{
    n = read();
    w = read();
    k = read();
    for (int i = 0; i < n; i ++)
    {
        a[i] = read();
        sum[0][i] = a[i];
    }
    for (int i = 0; i < n; i ++)
    {
        t[i] = read();
        TT[i] = t[i] - (t[i] + 1) / 2;
        sum[1][i] = t[i];
    }
    for (int i = 1; i < n; i ++)
    {
        sum[0][i] += sum[0][i - 1];
        sum[1][i] += sum[1][i - 1];
    }
    int pos = 0, ans = 0;
    for (int i = 0; i < n; i ++)
    {
        pos = max(pos, i);
        while (pos < n)
        {
            if (used[pos] == 0)
            {
                used[pos] = 1;
                add(TT[pos], pos);
            }
            int tm = get_sum(1, i, pos);
            tm -= sum_mx;
            if (tm <= k) pos ++;
            else break;

        }
        ans = max(ans, get_sum(0, i, pos - 1));
        err(TT[i], i);
    }
    printf("%d\n", ans);
    return 0;
}