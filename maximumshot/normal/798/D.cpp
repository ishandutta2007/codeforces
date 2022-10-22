#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

double const TIME = 1.9 * CLOCKS_PER_SEC;

int const N = 1e5 + 5;

int n;
int a[N];
int b[N];
int p[N];

int main() {

    srand(time(NULL));

    scanf("%d", &n);

    ll Sa = 0;
    ll Sb = 0;

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
        Sa += a[i];
    }

    for(int i = 1;i <= n;i++) {
        scanf("%d", &b[i]);
        Sb += b[i];
    }

    for(int i = 1;i <= n;i++) {
        p[i] = i;
    }

    int k = n / 2 + 1;
    ll sa, sb;

    while(clock() < TIME) {
        random_shuffle(p + 1, p + n + 1);
        sa = sb = 0;
        for(int i = 1;i <= k;i++) {
            sa += a[p[i]];
            sb += b[p[i]];
        }
        if(2 * sa > Sa && 2 * sb > Sb) {
            printf("%d\n", k);
            for(int i = 1;i <= k;i++) {
                printf("%d ", p[i]);
            }
            printf("\n");
            return 0;
        }
    }

    return 0;
}