#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int n;
int a[Maxn];
int S[Maxn];
int res;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = n - 1; i >= 0; i--)
        S[i] = a[i] - S[i + 1];
    int sum = 0;
    for (int i = 0; i < n; i++)
        if (i % 2 == 0) {
            if (sum + S[i + 1] == 0) res++;
            sum += a[i];
        } else {
            if (sum - S[i + 1] == 0) res++;
            sum -= a[i];
        }
    printf("%d\n", res);
    return 0;
}