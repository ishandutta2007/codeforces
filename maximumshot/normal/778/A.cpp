#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 200005;

char t[N];
char p[N];
int n, m;
int a[N];
int w[N];

bool check(int x) {
    int i, j;
    for(i = 1, j = 1;i <= n;i++) {
        if(w[i] <= x) continue;
        if(t[i] != p[j]) continue;
        j++;
    }
    return j > m;
}

int main() {

    scanf("%s %s", t + 1, p + 1);

    n = strlen(t + 1);
    m = strlen(p + 1);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
        w[a[i]] = i;
    }

    int bl = 0;
    int br = n - m;
    int bm;

    while(br - bl > 1) {
        bm = (bl + br) / 2;
        if(check(bm)) bl = bm;
        else br = bm - 1;
    }

    if(bl < br && check(br)) {
        printf("%d\n", br);
    }else {
        printf("%d\n", bl);
    }

    return 0;
}