#include <bits/stdc++.h>
using namespace std;

const int Maxn = 12;

int n;
int a[Maxn];
int res;

int main()
{
    scanf("%d", &n);
    int mn = 100;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        mn = min(mn, a[i]);
    }
    int res = 2 + (mn ^ a[2]);
    printf("%d\n", res);
    return 0;
}