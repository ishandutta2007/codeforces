#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int n;
int cnt[Maxn];
int res;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        cnt[a]++;
    }
    for (int i = 1; i < Maxn; i++) if (cnt[i] > 0) {
        res++;
        for (int j = i; j < Maxn; j += i) cnt[j] = 0;
    }
    printf("%d\n", res);
    return 0;
}