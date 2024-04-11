#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

const int Maxn = 5005;

int n, k;
int a[Maxn];
ld res;

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += a[j];
            if (j - i + 1 >= k)
                res = max(res, ld(sum) / (j - i + 1));
        }
    }
    cout << fixed << setprecision(10) << res << endl;
    return 0;
}