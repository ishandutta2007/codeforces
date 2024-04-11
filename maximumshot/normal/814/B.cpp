#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 1005;

int n;
int a[N];
int p[N];
int b[N];
int cnt[N];

bool check() {
    int i = -1;
    int j = -1;
    for(int q = 1;q <= n;q++) {
        if(p[q] != a[q]) {
            if(i != -1) return 0;
            i = q;
        }
        if(p[q] != b[q]) {
            if(j != -1) return 0;
            j = q;
        }
    }
    return i != -1 && j != -1;
}

int main() {

#ifdef maximumSHOT
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d", &n);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
        p[i] = a[i];
        cnt[a[i]]++;
    }

    for(int i = 1;i <= n;i++) {
        scanf("%d", &b[i]);
    }

    int value;

    for(int i = 1;i <= n;i++) {
        if(cnt[i] == 2) {
            value = i;
        }
    }

    int x = 0;
    int y = 0;

    for(int i = 1;i <= n;i++) {
        if(a[i] == value) {
            if(x == 0) {
                x = i;
            }else {
                y = i;
            }
        }
    }

    int need = 0;

    for(int i = 1;i <= n;i++) {
        if(cnt[i] == 0) {
            need = i;
        }
    }

    p[x] = need;

    if(check()) {
        for(int i = 1;i <= n;i++) {
            printf("%d ", p[i]);
        }
        printf("\n");
    }else {
        p[x] = value;
        p[y] = need;
        for(int i = 1;i <= n;i++) {
            printf("%d ", p[i]);
        }
        printf("\n");
    }

    return 0;
}