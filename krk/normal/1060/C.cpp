#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 2005;
const int Inf = 2000000007;

int n, m;
int a[Maxn], b[Maxn];
int x;
int myA[Maxn], myB[Maxn];
int res;

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        myA[i] = Inf;
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d", &b[i]);
        myB[i] = Inf;
    }
    scanf("%d", &x);
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = i; j <= n; j++) {
            sum += a[j];
            myA[j - i + 1] = min(myA[j - i + 1], sum);
        }
    }
    for (int i = 1; i <= m; i++) {
        int sum = 0;
        for (int j = i; j <= m; j++) {
            sum += b[j];
            myB[j - i + 1] = min(myB[j - i + 1], sum);
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) if (ll(myA[i]) * myB[j] <= x)
            res = max(res, i * j);
    printf("%d\n", res);
    return 0;
}