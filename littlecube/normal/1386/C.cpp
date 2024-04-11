#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define F first
#define S second
#define ll long long
using namespace std;

int T;
int N, M, Q, mxValid, rdx = -1;
array<int, 3> dsu[200005];
int ans[200005];
vector<pii> E = {{0, 0}};
pair<int, array<int, 3>> rollback[2000000];

pii Query(int k)
{
    if (k == dsu[k][0])
        return make_pair(k, dsu[k][2]);
    else
    {
        pii p = Query(dsu[k][0]);
        if (dsu[k][2])
            p.S ^= 1;
        return p;
    }
}

inline void Merge(int x, int y, bool flip)
{
    rollback[++rdx] = make_pair(x, dsu[x]);
    rollback[++rdx] = make_pair(y, dsu[y]);
    if (dsu[x][1] < dsu[y][1])
    {
        dsu[x][0] = y;
        if (flip)
            dsu[x][2] ^= 1;
        dsu[y][1] += dsu[x][1];
    }
    else
    {
        dsu[y][0] = x;
        if (flip)
            dsu[y][2] ^= 1;
        dsu[x][1] += dsu[y][1];
    }
}

inline int getAns(int L, int start)
{
    for (int i = start; i >= L && i >= 1; i--)
    {
        pii edge = E[i];
        pii rx = Query(edge.F), ry = Query(edge.S);
        if (rx.F == ry.F && rx.S == ry.S)
            return i;
        else if (rx.F != ry.F)
            Merge(rx.F, ry.F, (rx.S == ry.S));
    }
    return L;
}

void solve(int L, int R, int ansL, int ansR)
{
    //cout << "solve [" << L << ", " << R << "] with answer range [" << ansL << ", " << ansR << "]\n";
    if (R < L)
        return;
    if (ansL == ansR)
    {
        for (int i = L; i <= R; i++)
            ans[i] = ansL;
        return;
    }

    int mid = (L + R) / 2;
    int curSize = rdx;

    for (int i = L; i < mid; i++)
    {
        pii edge = E[i];
        pii rx = Query(edge.F), ry = Query(edge.S);
        if (rx.F != ry.F)
            Merge(rx.F, ry.F, (rx.S == ry.S));
    }

    ans[mid] = getAns(mid, ansR);

    for (int i = curSize + 1; i <= rdx; i++)
        dsu[rollback[i].F] = rollback[i].S;
    rdx = curSize;
    //for (int i = 1; i <= N; i++)
    //    cout << "(" << dsu[i][0] << " " << dsu[i][1] << " " << dsu[i][2] << ")"
    //         << " \n"[i == N];

    if (L == R)
        return;

    for (int i = ansR; i > ans[mid]; i--)
    {
        pii edge = E[i];
        pii rx = Query(edge.F), ry = Query(edge.S);
        if (rx.F != ry.F)
            Merge(rx.F, ry.F, (rx.S == ry.S));
    }

    solve(L, mid - 1, ansL, ans[mid]);

    for (int i = curSize + 1; i <= rdx; i++)
        dsu[rollback[i].F] = rollback[i].S;
    rdx = curSize;

    for (int i = L; i <= mid; i++)
    {
        pii edge = E[i];
        pii rx = Query(edge.F), ry = Query(edge.S);
        if (rx.F != ry.F)
            Merge(rx.F, ry.F, (rx.S == ry.S));
    }

    solve(mid + 1, R, max(mid + 1, ans[mid]), ansR);

    for (int i = curSize + 1; i <= rdx; i++)
        dsu[rollback[i].F] = rollback[i].S;
    rdx = curSize;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> M >> Q;

    for (int i = 1; i <= N; i++)
        dsu[i] = array<int, 3>{i, 1, 0};

    for (int i = 1; i <= M; i++)
    {
        int x, y;
        cin >> x >> y;
        E.emplace_back(make_pair(x, y));
    }

    mxValid = M;
    for (int i = 1; i <= M; i++)
    {
        pii edge = E[i];
        pii rx = Query(edge.F), ry = Query(edge.S);
        if (rx.F == ry.F && rx.S == ry.S)
        {
            mxValid = i;
            break;
        }
        if (rx.F != ry.F)
            Merge(rx.F, ry.F, (rx.S == ry.S));
    }

    for (int i = 0; i <= rdx; i++)
        dsu[rollback[i].F] = rollback[i].S;
    rdx = -1;

    solve(1, mxValid, 1, M);

    //for (int i = 1; i <= M; i++)
    //    cout << ans[i] << " ";

    for (int i = 1; i <= Q; i++)
    {
        int x, y;
        cin >> x >> y;
        if (y < ans[x] || x > mxValid)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}