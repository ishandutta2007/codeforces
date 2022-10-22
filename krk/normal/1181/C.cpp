#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 1005;

int n, m;
char B[Maxn][Maxn];
int mx[Maxn][Maxn];
int en[Maxn][Maxn];
ll res;

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%s", B[i] + 1);
    for (int j = m - 1; j > 0; j--)
        for (int i = 1; i <= n; i++)
            if (B[i][j] == B[i][j + 1])
                if (i > 1 && B[i][j] == B[i - 1][j])
                    mx[i][j] = mx[i - 1][j] + 1;
                else mx[i][j] = 1;
            else mx[i][j] = 0;
    for (int j = m; j > 0; j--) {
        vector <ii> seq;
        for (int i = 1, i2; i <= n; i = i2) {
            i2 = i;
            while (i2 <= n && B[i][j] == B[i2][j]) i2++;
            seq.push_back(ii(i, i2 - 1));
        }
        for (int i = 1; i + 1 < seq.size(); i++) {
            int a = seq[i - 1].second - seq[i - 1].first + 1;
            int b = seq[i].second - seq[i].first + 1;
            int c = seq[i + 1].second - seq[i + 1].first + 1;
            if (b <= a && b <= c) {
                en[seq[i].second][j] = 1;
                if (j < m && mx[seq[i].second][j] >= b && mx[seq[i - 1].second][j] >= b &&
                             mx[seq[i].second + b][j] >= b)
                    en[seq[i].second][j] += en[seq[i].second][j + 1];
            }
            res += en[seq[i].second][j];
        }
    }
    cout << res << endl;
    return 0;
}