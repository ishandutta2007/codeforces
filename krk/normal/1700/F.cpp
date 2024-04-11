#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 200005;
const ll Inf = 4000000000000000000ll;

ll B[2][Maxn];
int n;
ll res;

void Read(int delt)
{
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < n; j++) {
            int num; scanf("%d", &num);
            B[i][j] += num * delt;
        }
}

int main()
{
    scanf("%d", &n);
    Read(1); Read(-1);
    for (int j = 0; j < n; j++) {
        if (B[0][j] > 0 && B[1][j] < 0) {
            int tk = min(B[0][j], -B[1][j]);
            res += tk;
            B[0][j] -= tk; B[1][j] += tk;
        } else if (B[0][j] < 0 && B[1][j] > 0) {
            int tk = min(-B[0][j], B[1][j]);
            res += tk;
            B[0][j] += tk; B[1][j] -= tk;
        }
        if (j + 1 < n) {
            res += abs(B[0][j]); B[0][j + 1] += B[0][j];
            res += abs(B[1][j]); B[1][j + 1] += B[1][j];
        }
    }
    if (B[0][n - 1] != 0 || B[1][n - 1] != 0) {
        printf("-1\n");
        return 0;
    }
    cout << res << endl;
    return 0;
}