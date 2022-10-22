#include <bits/stdc++.h>

using namespace std;

#define ALL(x) begin(x), end(x)
#define vec vector

typedef long long ll;
typedef unsigned int ui;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = ll(1e18);

const int N = 3e5 + 5;

int n, x1, x2;
pii c[N];
int a[N];
int b[N];
int value[N];
pii pref[N];
pii suff[N];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d %d", &n, &x1, &x2);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &c[i].first);
        c[i].second = i;
    }

    sort(c + 1, c + n + 1);

    for(int i = 1;i <= n;i++) {
        a[i] = (x1 + c[i].first - 1) / c[i].first;
        b[i] = (x2 + c[i].first - 1) / c[i].first;
        value[i] = n - i + 1 - b[i];
    }

    for(int i = 1;i <= n;i++) {
        if(i == 1) {
            pref[i] = make_pair(value[i], i);
        }else {
            pref[i] = max(pref[i - 1], make_pair(value[i], i));
        }
    }

    for(int i = n;i >= 1;i--) {
        if(i == n) {
            suff[i] = make_pair(value[i], i);
        }else {
            suff[i] = max(suff[i + 1], make_pair(value[i], i));
        }
    }

    for(int j = 1, k1 = n - 1;k1 >= 1;k1--) {
        while(j <= n && a[j] > k1) j++;
        if(j + k1 - 1 > n) {
            continue;
        }
        int L = j;
        int R = L + k1 - 1;
        if(R < n && suff[R + 1].first >= 0) {
            int p = suff[R + 1].second;
            puts("Yes");
            int k2 = b[p];
            printf("%d %d\n", k1, k2);
            for(int i = L;i <= R;i++) {
                printf("%d ", c[i].second);
            }
            printf("\n");
            for(int i = p;i < p + k2;i++) {
                printf("%d ", c[i].second);
            }
            printf("\n");
            return 0;
        }
        if(L > 1 && pref[L - 1].first - k1 >= 0) {
            int p = pref[L - 1].second;
            puts("Yes");
            int k2 = b[p];
            printf("%d %d\n", k1, k2);
            for(int i = L;i <= R;i++) {
                printf("%d ", c[i].second);
            }
            printf("\n");
            int cnt = 0;
            while(cnt < k2) {
                if(p < L || p > R) {
                    printf("%d ", c[p].second);
                    cnt++;
                }
                p++;
            }
            return 0;
        }
    }

    puts("No");

    return 0;
}