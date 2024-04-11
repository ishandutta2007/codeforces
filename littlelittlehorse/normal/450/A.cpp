#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, a[101], c[100001];

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int k = n;
    for (int i = 1; i <= n; i++) c[i] = i;
    int ans = 0;
    for (int l = 1; l <= k; l++)
    {
        int index = c[l];
        a[index] -= m; ans = index;
        if (a[index] > 0) c[++k] = index;
    }
    printf("%d\n", ans);
}