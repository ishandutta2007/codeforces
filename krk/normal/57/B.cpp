#include <cstdio>
using namespace std;

typedef long long ll;

const int Maxm = 100000;

int n, m, k, a[Maxm], b[Maxm], c[Maxm];

int main()
{
    ll res = 0;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; i++) scanf("%d %d %d", &a[i], &b[i], &c[i]);
    for (int i = 0; i < k; i++) { 
        int num;
        scanf("%d", &num);
        for (int j = 0; j < m; j++)
           if (a[j] <= num && num <= b[j]) res += num - a[j] + c[j];
    }
    printf("%I64d\n", res);
    return 0;
}