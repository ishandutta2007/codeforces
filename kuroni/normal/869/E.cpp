#include <iostream>
#include <cstdio>
#include <random>
#include <map>
#define rec make_pair(make_pair(r1, c1), make_pair(r2, c2))
using namespace std;

const int N = 2505, M = 2505;

mt19937_64 mt(1337);
uniform_int_distribution<long long> uni(1, 1E15);
int m, n, q, t, r1, c1, r2, c2;
long long bit[M][N];
map<pair<pair<int, int>, pair<int, int>>, long long> val;

void upd(int u, int v, long long ret)
{
    for (int i = u; i <= m; i += i & -i)
        for (int j = v; j <= n; j += j & -j)
            bit[i][j] += ret;
}

long long get(int u, int v)
{
    long long ret = 0;
    for (int i = u; i > 0; i -= i & -i)
        for (int j = v; j > 0; j -= j & -j)
            ret += bit[i][j];
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> m >> n >> q;
    while (q--)
    {
        cin >> t >> r1 >> c1 >> r2 >> c2;
        if (t == 3)
        {
            long long le = get(r1, c1), ri = get(r2, c2);
            cout << (le == ri ? "Yes\n" : "No\n");
        }
        else
        {
            long long ran;
            if (t == 1)
                val[rec] = ran = uni(mt);
            else
            {
                ran = -val[rec];
                val.erase(val.find(rec));
            }
            upd(r1, c1, ran);
            upd(r1, c2 + 1, -ran);
            upd(r2 + 1, c1, -ran);
            upd(r2 + 1, c2 + 1, ran);
        }
    }
}