#include <bits/stdc++.h>
using namespace std;

const int Maxn = 4015;
const int nil = 2005;

int T;
int n;
int P[Maxn];
bool dp[Maxn][Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < 2 * n; i++)
            scanf("%d", &P[i]);
        vector <int> V;
        for (int i = 0, j; i < 2 * n; i = j) {
            j = i;
            while (j < 2 * n && P[i] >= P[j]) j++;
            V.push_back(j - i);
        }
        for (int i = 0; i <= V.size(); i++)
            for (int j = nil - n; j <= nil + n; j++)
                dp[i][j] = false;
        dp[0][nil] = true;
        for (int i = 0; i < V.size(); i++)
            for (int j = nil - n; j <= nil + n; j++) if (dp[i][j]) {
                if (j - V[i] >= nil - n) dp[i + 1][j - V[i]] = true;
                if (j + V[i] <= nil + n) dp[i + 1][j + V[i]] = true;
            }
        printf("%s\n", dp[V.size()][nil]? "YES": "NO");
    }
    return 0;
}