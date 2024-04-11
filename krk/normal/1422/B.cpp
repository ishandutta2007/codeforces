#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 105;

int T;
int n, m;
int A[Maxn][Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                scanf("%d", &A[i][j]);
        ll res = 0;
        for (int i = 0; i <= n - 1 - i; i++)
            for (int j = 0; j <= m - 1 - j; j++) {
                vector <int> seq;
                seq.push_back(A[i][j]);
                if (j < m - 1 - j)
                    seq.push_back(A[i][m - 1 - j]);
                if (i < n - 1 - i) {
                    seq.push_back(A[n - 1 - i][j]);
                    if (j < m - 1 - j)
                        seq.push_back(A[n - 1 - i][m - 1 - j]);
                }
                sort(seq.begin(), seq.end());
                int mid = int(seq.size()) / 2;
                for (int z = 0; z < seq.size(); z++)
                    res += abs(seq[z] - seq[mid]);
            }
        printf("%I64d\n", res);
    }
    return 0;
}