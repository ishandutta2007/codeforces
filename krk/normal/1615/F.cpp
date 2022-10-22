#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 2005;
const int Maxm = 2 * Maxn + 15;
const int mod = 1000000007;

int T;
int n;
char A[Maxn];
char B[Maxn];
int nil;
int ways[Maxn][Maxm], all[Maxn][Maxm];

bool Check(char a, char b) { return a == '?' || a == b; }

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        scanf("%s", A);
        scanf("%s", B);
        for (int i = 1; i < n; i += 2) {
            if (A[i] != '?') A[i] = A[i] == '0'? '1': '0';
            if (B[i] != '?') B[i] = B[i] == '0'? '1': '0';
        }
        int m = 2 * n + 15;
        nil = n + 5;
        for (int i = 0; i <= n; i++)
            for (int j = 0; j < m; j++) {
                ways[i][j] = 0;
                all[i][j] = 0;
            }
        ways[0][nil] = 1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) if (ways[i][j] || all[i][j]) {
                if (Check(A[i], '0') && Check(B[i], '0')) {
                    ways[i + 1][j] = (ways[i + 1][j] + ways[i][j]) % mod;
                    all[i + 1][j] = (all[i + 1][j] + all[i][j]) % mod;
                }
                if (Check(A[i], '0') && Check(B[i], '1')) {
                    int add = j > nil? i: (mod - i) % mod;
                    ways[i + 1][j - 1] = (ways[i + 1][j - 1] + ways[i][j]) % mod;
                    all[i + 1][j - 1] = (all[i + 1][j - 1] + ll(ways[i][j]) * add + ll(all[i][j])) % mod;
                }
                if (Check(A[i], '1') && Check(B[i], '0')) {
                    int add = j < nil? i: (mod - i) % mod;
                    ways[i + 1][j + 1] = (ways[i + 1][j + 1] + ways[i][j]) % mod;
                    all[i + 1][j + 1] = (all[i + 1][j + 1] + ll(ways[i][j]) * add + ll(all[i][j])) % mod;
                }
                if (Check(A[i], '1') && Check(B[i], '1')) {
                    ways[i + 1][j] = (ways[i + 1][j] + ways[i][j]) % mod;
                    all[i + 1][j] = (all[i + 1][j] + all[i][j]) % mod;
                }
            }
        printf("%d\n", all[n][nil]);
    }
    return 0;
}