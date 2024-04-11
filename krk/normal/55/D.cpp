#include <cstdio>
#include <deque>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 20;
const int Maxm = 2520;
const int Maxid = 48;
const int Maxd = 10;

deque <int> id;
int itsid[Maxm + 1], G[Maxm][Maxd];
int t;
ll l, r;
ll f[Maxn][Maxm][Maxid][2];

void getDeq(ll x, deque <int> &D)
{
    D.clear();
    do {
        D.push_front(x % 10LL);
        x /= 10LL;
    } while (x);
}

int gcd(int x, int y) { return x? gcd(y % x, x): y; }

ll F(ll x)
{
    deque <int> D; getDeq(x, D);
    fill((ll*)f, (ll*)f + Maxn * Maxm * Maxid * 2, 0LL);
    ll res = 0LL;
    f[0][0][0][1] = 1LL;
    for (int i = 0; i <= D.size(); i++)
        for (int j = 0; j < Maxm; j++)
            for (int l = 0; l < Maxid; l++)
                for (int k = 0; k < 2; k++) if (f[i][j][l][k]) {
                    if (i == D.size()) {
                        if (j % id[l] == 0) res += f[i][j][l][k];
                        continue;
                    }
                    for (int d = 0; d < Maxd && (!k || d <= D[i]); d++)
                        f[i + 1][(10 * j + d) % Maxm][G[l][d]][k == 1 && d == D[i]] += f[i][j][l][k];
                }
    return res;
}

int main()
{
    for (int i = 1; i <= Maxm; i++)
        if (Maxm % i == 0LL) {
            itsid[i] = id.size();
            id.push_back(i);
        }
    for (int i = 0; i < id.size(); i++) {
        G[i][0] = i;
        for (int j = 1; j < Maxd; j++) G[i][j] = itsid[id[i] / gcd(id[i], j) * j];
    }
    scanf("%d", &t);
    while (t--) {
        scanf("%I64d %I64d", &l, &r);
        printf("%I64d\n", F(r) - F(l - 1LL));
    }
    return 0;
}