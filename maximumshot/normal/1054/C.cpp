#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1e18;

const int N = 1e3 + 5;

int n;
int l[N], l1[N];
int r[N], r1[N];
int a[N], ql[N], qr[N];
int u[N];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d", &n);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &l[i]);
        l1[i] = l[i];
    }

    for(int i = 1;i <= n;i++) {
        scanf("%d", &r[i]);
        r1[i] = r[i];
    }

    for(int x = n, c = n;c > 0;x--) {
        vec< int > ps;
        for(int i = 1;i <= n;i++) {
            if(u[i]) continue;
            if(l[i] == 0 && r[i] == 0) {
                ps.push_back(i);
            }
        }
        if(ps.empty()) {
            puts("NO");
            return 0;
        }
        for(int p : ps) {
            u[p] = 1;
            a[p] = x;
        }
        for(int p : ps) {
            for(int j = 1;j <= n;j++) {
                if(u[j]) continue;
                if(j < p) {
                    if(r[j] > 0) r[j]--;
                    else { puts("NO"); return 0; }
                }else {
                    if(l[j] > 0) l[j]--;
                    else { puts("NO"); return 0; }
                }
            }
        }
        c -= (int)ps.size();
    }

    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            if(a[j] <= a[i]) continue;
            if(j < i) ql[i]++;
            else if(j > i) qr[i]++;
        }
    }

    for(int i = 1;i <= n;i++) {
        if(r1[i] != qr[i] || l1[i] != ql[i]) {
            puts("NO");
            return 0;
        }
    }

    puts("YES");

    for(int i = 1;i <= n;i++) {
        printf("%d ", a[i]);
    }

    printf("\n");

    return 0;
}