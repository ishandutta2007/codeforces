#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 14;
const int Maxh = 1 << 6;

int n;
char M[Maxn + 2][Maxn + 2];
int A, B;
int cntA[1 << Maxn][Maxn][Maxh];
int cntB[1 << Maxn][Maxn][Maxh];
ll res[1 << Maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%s", M[i]);
    A = n / 2;
    B = n - A;
    for (int i = 0; i < 1 << n; i++) {
        int b = __builtin_popcount(i);
        if (b == A || b == B) {
            vector <int> seq;
            for (int j = 0; j < n; j++)
                if (i & 1 << j) seq.push_back(j);
            do {
                int my = 0;
                for (int j = 0; j + 1 < seq.size(); j++)
                    if (M[seq[j]][seq[j + 1]] == '1') my |= 1 << j;
                if (b == A) cntA[i][seq.back()][my]++;
                if (b == B) cntB[i][seq[0]][my]++;
            } while (next_permutation(seq.begin(), seq.end()));
        }
    }
    int all = (1 << n) - 1;
    for (int i = 0; i < 1 << n; i++) {
        int b = __builtin_popcount(i);
        if (b == A) {
            int j = (all ^ i);
            for (int c = 0; c < n; c++) if (i & 1 << c)
                for (int d = 0; d < n; d++) if (!(i & 1 << d))
                    for (int m1 = 0; m1 < 1 << A - 1; m1++)
                        for (int m2 = 0; m2 < 1 << B - 1; m2++)
                            res[m1 | (M[c][d] == '1') << A - 1 | m2 << A] += ll(cntA[i][c][m1]) * cntB[j][d][m2];
        }
    }
    for (int i = 0; i < 1 << n - 1; i++)
        printf("%I64d%c", res[i], i + 1 < (1 << n - 1)? ' ': '\n');
    return 0;
}