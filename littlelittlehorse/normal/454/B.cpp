#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, a[100001];
bool pre[100001], suf[100001];

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    memset(pre, false, sizeof(pre));
    pre[1] = true;
    for (int i = 2; i <= n; i++)
        if (a[i] >= a[i - 1]) pre[i] = true;
        else break;
    memset(suf, false, sizeof(suf));
    suf[n] = true;
    for (int i = n - 1; i; --i)
        if (a[i] <= a[i + 1]) suf[i] = true;
        else break;
    for (int i = n; i; --i) 
        if (pre[i] && (i == n || (suf[i + 1] && a[n] <= a[1])))
        {
            printf("%d\n", n - i);
            return 0;
        }
    printf("-1\n");
}