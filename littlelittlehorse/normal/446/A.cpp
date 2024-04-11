#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, a[100001], f[100011], v[100011];

int main(){
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);    
    f[1] = 1; f[0] = 0;
    for (int i = 2; i <= n; i++)
        if (a[i] > a[i - 1]) f[i] = f[i - 1] + 1;
        else f[i] = 1;
    v[n] = 1; v[n + 1] = 0;
    for (int i = n - 1; i; --i)
        if (a[i] < a[i + 1]) v[i] = v[i + 1] + 1;
        else v[i] = 1;
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, f[i]);
    if (ans != n) ++ans;
    for (int i = 2; i < n; i++)
        if (a[i - 1] + 1 < a[i + 1]) 
        ans = max(ans, f[i - 1] + v[i + 1] + 1);
    printf("%d\n", ans);
}