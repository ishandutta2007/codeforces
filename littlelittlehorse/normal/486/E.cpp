#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int n, a[100001], f[100001], l[100001], r[100001], ans[100001], dhh[100001], cnt[100001];

inline void insert(int x, int y){
    for (; x <= 100000; x += x & (-x))
        if (y <= f[x]) return;
        else f[x] = y;
}

int calc(int x){
    int will = 0;
    for (; x; x -= x & (-x)) will = max(will, f[x]);
    return will;
}

    
int main(){
    //freopen("e.in", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    memset(f, 0, sizeof(f)); int limit = 0;
    for (int i = 1; i <= n; i++) 
    {
        l[i] = calc(a[i] - 1) + 1; limit = max(limit, l[i]);
        insert(a[i], l[i]);
    }
    memset(f, 0, sizeof(f));
    for (int i = n; i; --i)
    {
        r[i] = calc(100000 - a[i]) + 1;
        insert(100000 - a[i] + 1, r[i]);
    }
    memset(cnt, 0, sizeof(cnt));
    memset(dhh, 0, sizeof(dhh)); dhh[0] = 1 << 30;
    memset(ans, 0, sizeof(ans));
    for (int i = n; i >= 1; i--) 
    {
        if (dhh[limit - l[i]] > a[i]) ++cnt[l[i]];
        else ans[i] = 1;
        dhh[r[i]] = max(dhh[r[i]], a[i]);
    }
    for (int i = 1; i <= n; ++i)
        if (ans[i]) printf("1");
        else if (cnt[l[i]] == 1) printf("3");
        else printf("2");
    printf("\n");
}