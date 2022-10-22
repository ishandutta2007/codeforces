#include <cstdio>
#include <cmath>
#include <string>
using namespace std;

const double eps = 1e-6;
const int Maxn = 1005;

int n;
int cur = 2;
bool B[Maxn][Maxn];

void Add(int a, int b, int c, int d, int e)
{
    for (int i = 1; i <= a; i++)
        B[1][cur + i] = B[cur + i][1] = true;
    for (int i = 1; i <= a; i++)
        for (int j = 1; j <= b; j++)
            B[cur + i][cur + a + j] = B[cur + a + j][cur + i] = true;
    for (int i = 1; i <= b; i++)
        for (int j = 1; j <= c; j++)
            B[cur + a + i][cur + a + b + j] = B[cur + a + b + j][cur + a + i] = true;
    for (int i = 1; i <= c; i++)
        for (int j = 1; j <= d; j++)
            B[cur + a + b + i][cur + a + b + c + j] = B[cur + a + b + c + j][cur + a + b + i] = true;
    for (int i = 1; i <= d; i++)
        for (int j = 1; j <= e; j++)
            B[cur + a + b + c + i][cur + a + b + c + d + j] = B[cur + a + b + c + d + j][cur + a + b + c + i] = true;
    for (int i = 1; i <= e; i++)
        B[cur + a + b + c + d + i][2] = B[2][cur + a + b + c + d + i] = true;
    cur += a + b + c + d + e;
}

int main()
{
    scanf("%d", &n);
    int a = 1;
    while ((a + 1) * (a + 1) * (a + 1) * (a + 1) * (a + 1) <= n) a++;
    while (n) {
        while (a * a * a * a * a > n) a--;
        int b = a;
        while (a * (b + 1) * (b + 1) * (b + 1) * (b + 1) <= n) b++;
        int c = b;
        while (a * b * (c + 1) * (c + 1) * (c + 1) <= n) c++;
        int d = c;
        while (a * b * c * (d + 1) * (d + 1) <= n) d++;
        int e = d;
        while (a * b * c * d * (e + 1) <= n) e++;
        Add(a, b, c, d, e);
        n -= a * b * c * d * e;
    }
    printf("%d\n", cur);
    for (int i = 1; i <= cur; i++) {
        for (int j = 1; j <= cur; j++)
            printf("%c", B[i][j]? 'Y': 'N');
        printf("\n");
    }
    return 0;
}