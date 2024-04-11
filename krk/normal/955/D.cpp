#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005;
const int Inf = 1000000000;

int n, m, k;
char S[Maxn];
char T[Maxn];
char str[Maxn];
int slen;
int Z[Maxn];
int res1[Maxn];
int res2[Maxn];
set <int> St;

void Solve(int res[])
{
    St.clear();
    for (int i = 0; i <= m; i++)
        St.insert(i);
    fill(res, res + m + 1, Inf);
    int L = -1, R = -1;
    for (int i = 1; i < slen; i++) {
        if (i <= R) Z[i] = min(R - i, Z[i - L]);
        else Z[i] = 0;
        while (i + Z[i] < slen && str[i + Z[i]] == str[Z[i]])
            Z[i]++;
        if (i >= m + 1) {
            int tk = min(Z[i], k);
            int ind = i - m - 1;
            if (tk + ind >= k) {
                int lef = max(0, k - ind);
                int rig = tk;
                if (lef <= rig) {
                    auto it = St.lower_bound(lef);
                    while (it != St.end() && *it <= rig) {
                        res[*it] = ind;
                        St.erase(it++);
                    }
                }
            } else if (tk == m) {
                int mnind = max(0, ind + tk - k);
                auto it = St.lower_bound(m);
                if (it != St.end()) {
                    res[*it] = mnind;
                    St.erase(it);
                }
            }
        }
        if (i + Z[i] - 1 > R) {
            R = i + Z[i] - 1;
            L = i;
        }
    }
}

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    scanf("%s", S);
    scanf("%s", T);
    for (int i = 0; i < m; i++)
        str[slen++] = T[i];
    str[slen++] = '#';
    for (int i = 0; i < n; i++)
        str[slen++] = S[i];
    Solve(res1);
    slen = 0;
    for (int i = m - 1; i >= 0; i--)
        str[slen++] = T[i];
    str[slen++] = '#';
    for (int i = n - 1; i >= 0; i--)
        str[slen++] = S[i];
    Solve(res2);
    for (int i = 0; i <= m; i++) {
        int j = m - i;
        if (res1[i] + i + res2[j] + j <= n) {
            printf("Yes\n");
            printf("%d %d\n", max(1, res1[i] + i - k + 1),
                              min(n - k + 1, n - res2[j] - j + 1));
            return 0;
        }
    }
    printf("No\n");
    return 0;
}