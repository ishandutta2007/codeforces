#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int Maxn = 5005;
const int Inf = 2000000000;

int n, m, k;
int A, B;
int r1, p1, p2 = Inf;
double r2;

int main()
{
    scanf("%d", &n);
    while (n--) {
        int x; scanf("%d", &x);
        r1 = max(r1, x);
    }
    scanf("%d", &m);
    while (m--) {
        int y; scanf("%d", &y);
        p1 = max(p1, y);
    }
    scanf("%d", &k);
    while (k--) {
        int z; scanf("%d", &z);
        p2 = min(p2, z);
    }
    scanf("%d %d", &A, &B);
    r2 = r1 * sqrt(1.0 / (1.0 + double(A * p2) / double(B * p1)));
    printf("%.12lf\n", r2);
    return 0;
}