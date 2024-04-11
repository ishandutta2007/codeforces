#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int a[201], n, limit, c[201], v[201], len1, len2;

bool cmp(const int &x, const int &y){
    return x > y;
}

int main(){
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    scanf("%d%d", &n, &limit);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int ans = - 1<<30;
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++) 
        {
            len1 = 0;
            len2 = 0;
            for (int k = 1; k < i; k++) c[++len1] = a[k];
            for (int k = j + 1; k <= n; k++) c[++len1] = a[k];
            sort(c + 1, c + len1 + 1, cmp);
            for (int k = i; k <= j; k++) v[++len2] = a[k];
            for (int k = 1; k <= limit && k <= len1; k++) v[++len2] = c[k];
            sort(v + 1, v + len2 + 1, cmp);
            int will = 0;
            for (int k = 1; k <= j - i + 1; k++) will += v[k];
            ans = max(ans, will);
        }
    printf("%d\n", ans);
        
}