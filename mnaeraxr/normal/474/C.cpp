#include <bits/stdc++.h>

using namespace std;

#define DB(x) cout<<#x<<"="<<x<<endl;
#define MP make_pair

typedef long long int64;
typedef pair<int64,int64> pii;
typedef vector<int> vi;

const int oo = 1 << 29;
const double EPS = 1e-9;
const int MAXN = (int)1e5 + 10;
const int MOD = 1000000007;

pii M[4][2];
int64 D[6];

pii rot(pii p, pii c)
{
    pii t = MP(p.first - c.first, p.second - c.second);
    pii ans = MP(-t.second, t.first);
    return MP(c.first + ans.first, c.second + ans.second);
}

pii rotn(pii p, pii c, int t)
{
    for (int i = 0; i < t; ++i)
        p = rot(p, c);
    return p;
}

int64 sqr(int64 a)
{
    return a * a;
}

int64 sqrdist(pii a, pii b)
{
    return sqr(a.first - b.first) + sqr(a.second - b.second);
}

bool square(pii a, pii b, pii c, pii d)
{
    D[0] = sqrdist(a, b);
    D[1] = sqrdist(a, c);
    D[2] = sqrdist(a, d);
    D[3] = sqrdist(b, c);
    D[4] = sqrdist(b, d);
    D[5] = sqrdist(c, d);

    sort(D, D + 6);
    return D[0] != 0 && D[0] == D[3] && D[4] == D[5];
}

int solve()
{
    int best = oo;

    pii p1, p2, p3, p4;
    for (int a1 = 0; a1 < 4; ++a1)
    {
        for (int a2 = 0; a2 < 4; ++a2)
        {
            for (int a3 = 0; a3 < 4; ++a3)
            {
                for (int a4 = 0; a4 < 4; ++a4)
                {
                    p1 = rotn(M[0][0], M[0][1], a1);
                    p2 = rotn(M[1][0], M[1][1], a2);
                    p3 = rotn(M[2][0], M[2][1], a3);
                    p4 = rotn(M[3][0], M[3][1], a4);
                    if (square(p1, p2, p3, p4))
                    {
                        best = min(best, a1 + a2 + a3 + a4);
                    }
                }
            }
        }
    }
    return (best == oo) ? -1 : best;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < 4; ++j)
            cin >> M[j][0].first >> M[j][0].second >> M[j][1].first >> M[j][1].second;

        cout << solve() << endl;
    }

    return 0;
}