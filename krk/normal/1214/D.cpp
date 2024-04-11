#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 1000005;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

char tmp[Maxn];
int mod1, mod2;
int n, m;
string B[Maxn];
vector <ii> dp1[Maxn], dp2[Maxn];

void Read(string &s)
{
    scanf("%s", tmp); s = tmp;
}

bool Prime(int x)
{
    if (x <= 1) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    for (int i = 3; i * i <= x; i += 2)
        if (x % i == 0) return false;
    return true;
}

void Update(ii &p, const ii &add)
{
    p.first = (p.first + add.first) % mod1;
    p.second = (p.second + add.second) % mod2;
}

int main()
{
    mod1 = uniform_int_distribution<int>(500000000, 1000000000)(rng);
    mod2 = uniform_int_distribution<int>(500000000, 1000000000)(rng);
    while (!Prime(mod1)) mod1++;
    while (!Prime(mod2)) mod2++;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        Read(B[i]);
        dp1[i].resize(m, ii(0, 0));
        dp2[i].resize(m, ii(0, 0));
    }
    dp1[0][0] = ii(1, 1);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) if (B[i][j] != '#') {
            if (i + 1 < n && B[i + 1][j] != '#') Update(dp1[i + 1][j], dp1[i][j]);
            if (j + 1 < m && B[i][j + 1] != '#') Update(dp1[i][j + 1], dp1[i][j]);
        }
    if (dp1[n - 1][m - 1] == ii(0, 0)) { printf("0\n"); return 0; }
    dp2[n - 1][m - 1] = ii(1, 1);
    for (int i = n - 1; i >= 0; i--)
        for (int j = m - 1; j >= 0; j--) if (B[i][j] != '#') {
            if (i - 1 >= 0 && B[i - 1][j] != '#') Update(dp2[i - 1][j], dp2[i][j]);
            if (j - 1 >= 0 && B[i][j - 1] != '#') Update(dp2[i][j - 1], dp2[i][j]);
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!(i == 0 && j == 0) && !(i == n - 1 && j == m - 1) && B[i][j] != '#')
                if (ll(dp1[i][j].first) * dp2[i][j].first % mod1 == dp1[n - 1][m - 1].first &&
                    ll(dp1[i][j].second) * dp2[i][j].second % mod2 == dp1[n - 1][m - 1].second) {
                    printf("1\n"); return 0;
                }
    printf("2\n");
    return 0;
}