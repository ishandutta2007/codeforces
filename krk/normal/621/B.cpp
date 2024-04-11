#include <cstdio>
using namespace std;

typedef long long ll;

const int Maxm = 2015;
const int nil = 1005;

int n;
int diag1[Maxm], diag2[Maxm];
ll res;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x, y; scanf("%d %d", &x, &y);
        diag1[x + y]++;
        diag2[x - y + nil]++;
    }
    for (int i = 0; i < Maxm; i++) {
        res += ll(diag1[i]) * (diag1[i] - 1) / 2;
        res += ll(diag2[i]) * (diag2[i] - 1) / 2;
    }
    printf("%I64d\n", res);
    return 0;
}