#include <cstdio>
#include <string>
#include <iomanip>
#include <iostream>
using namespace std;

typedef long long ll;
typedef long double ld;

const int Maxn = 50;
const int Maxm = 20;
const int Maxl = 25;

int mem[1 << Maxm];
int n;
string s[Maxn];
int m;
ll has[Maxn][Maxm];
ll hasand[Maxl][1 << Maxm];
ll dp1[1 << Maxm];
int dp2[1 << Maxm];
ld res[1 << Maxm];

void Calc(int L, int R)
{
    for (int i = L; i <= R; i++)
        hasand[i - L][0] = ((1ll << n) - 1ll) ^ (1ll << i);
    for (int i = 1; i < 1 << m; i++) {
        int pos = mem[i & -i];
        int j = i ^ (1 << pos);
        for (int k = L; k <= R; k++) {
            hasand[k - L][i] = hasand[k - L][j] & has[k][pos];
            if (!hasand[k - L][i]) { dp1[i] |= 1ll << k; dp2[i]++; }
        }
    }
}

int main()
{
    for (int i = 0; i < Maxm; i++)
        mem[1 << i] = i;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    m = s[0].length();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int k = 0; k < n; k++) if (k != i)
                if (s[i][j] == s[k][j])
                    has[i][j] |= 1ll << ll(k);
    if (n == 1) { dp1[0] = 1; dp2[0] = 1; }
    int x = n >> 1;
    if (x > 0) Calc(0, x - 1);
    Calc(x, n - 1);
    res[(1 << m) - 1] = 0;
    for (int i = (1 << m) - 2; i >= 0; i--) {
        if (dp2[i] == n) { res[i] = 0; continue; }
        int cnt = 0;
        for (int j = 0; j < m; j++)
            if (!(i & 1 << j)) {
                int ni = i ^ (1 << j);
                res[i] += 1.0 + ld(n - dp2[ni]) / ld(n - dp2[i]) * res[ni];
                cnt++;
            }
        res[i] /= ld(cnt);
    }
    cout << fixed << setprecision(15) << res[0] << endl;
    return 0;
}