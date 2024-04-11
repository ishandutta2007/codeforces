#include <bits/stdc++.h>
using namespace std;

const int Maxn = 205;
const int Maxd = 4;
const int dy[Maxd] = {-1, 0, 1, 0};
const int dx[Maxd] = {0, -1, 0, 1};

int n, m;
int B[Maxn][Maxn];
int R[Maxn][2], C[Maxn][2];
char resR[Maxn], resC[Maxn];

bool Check()
{
    for (int i = 0; i + 1 < n; i++)
        if (R[i][0] > 0 && R[i][1] > 0) return false;
    for (int j = 0; j + 1 < m; j++)
        if (C[j][0] > 0 && C[j][1] > 0) return false;
    return true;
}

char Not(char ch) { return ch == '0'? '1': '0'; }

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            scanf("%d", &B[i][j]);
            if (i) R[i - 1][bool(B[i - 1][j] ^ B[i][j])]++;
            if (j) C[j - 1][bool(B[i][j - 1] ^ B[i][j])]++;
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (i) {
                R[i - 1][bool(B[i - 1][j] ^ B[i][j] ^ 1)]--;
                R[i - 1][bool(B[i - 1][j] ^ B[i][j])]++;
            }
            if (j) {
                C[j - 1][bool(B[i][j - 1] ^ B[i][j] ^ 1)]--;
                C[j - 1][bool(B[i][j - 1] ^ B[i][j])]++;
            }
            if (i + 1 < n) {
                R[i][bool(B[i][j] ^ B[i + 1][j])]--;
                R[i][bool(B[i][j] ^ B[i + 1][j] ^ 1)]++;
            }
            if (j + 1 < m) {
                C[j][bool(B[i][j] ^ B[i][j + 1])]--;
                C[j][bool(B[i][j] ^ B[i][j + 1] ^ 1)]++;
            }
            if (Check()) {
                resR[0] = '0';
                if (B[0][0] == 1) resC[0] = '1';
                else resC[0] = '0';
                for (int i = 0; i + 1 < n; i++)
                    if (R[i][0] > 0) resR[i + 1] = resR[i];
                    else resR[i + 1] = Not(resR[i]);
                for (int j = 0; j + 1 < m; j++)
                    if (C[j][0] > 0) resC[j + 1] = resC[j];
                    else resC[j + 1] = Not(resC[j]);
                resR[n] = '\0'; resC[m] = '\0';
                printf("YES\n%s\n%s\n", resR, resC);
                return 0;
            }
        }
    printf("NO\n");
    return 0;
}