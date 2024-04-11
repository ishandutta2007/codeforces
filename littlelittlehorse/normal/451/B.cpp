#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, a[100001], f[100001], cnt1, cnt2;

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    cnt1 = 1;
    for (int i = 2; i <= n; i++)
        if (a[i] > a[i - 1]) cnt1 = i;
        else break;
    cnt2 = n;
    for (int i = n - 1; i; --i)
        if (a[i] < a[i + 1]) cnt2 = i;
        else break;
    if (cnt1 >= cnt2) 
    {
        printf("yes\n1 1\n");
        return 0;
    }
    bool ok = true;
    for (int i = cnt1 + 1; i <= cnt2 && ok; i++)
        if (a[i] > a[i - 1]) ok = false;
    if (cnt1 != 1 && a[cnt2] < a[cnt1 - 1]) ok = false;
    if (cnt2 != n && a[cnt1] > a[cnt2 + 1]) ok = false;
    if (ok) printf("yes\n%d %d\n", cnt1, cnt2);
    else printf("no\n");
}