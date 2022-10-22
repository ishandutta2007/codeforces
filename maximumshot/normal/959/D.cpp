#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int X = 2e6 + 5;
const int N = 1e5 + 5;

int pr[X];
vec< int > dv[X];

void precalc() {
    fill(pr, pr + X, 1);
    pr[0] = pr[1] = 0;
    for(int x = 2;x * x < X;x++) {
        if(!pr[x]) continue;
        for(int y = x * x;y < X;y += x) {
            pr[y] = 0;
        }
    }
    for(int x = 2;x < X;x++) {
        if(!pr[x]) continue;
        for(int y = x;y < X;y += x) {
            dv[y].push_back(x);
        }
    }
}

int n;
int a[N];
int used[X];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    precalc();

    scanf("%d", &n);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
    }

    int ln = 0;

    while(ln < n) {
        if(a[ln + 1] < 2) break;
        int ok = 1;
        for(int p : dv[a[ln + 1]]) {
            if(used[p]) {
                ok = 0;
                break;
            }
        }
        if(!ok) break;
        for(int p : dv[a[ln + 1]]) {
            used[p] = 1;
        }
        ln++;
    }

    for(int i = 1;i <= ln;i++) {
        printf("%d ", a[i]);
    }

    if(ln == n) return 0;

    {
        int vl = a[ln + 1];
        if(vl < 2) vl = 2;
        while(1) {
            int ok = 1;
            for(int p : dv[vl]) {
                if(used[p]) {
                    ok = 0;
                    break;
                }
            }
            if(ok) {
                printf("%d ", vl);
                for(int p : dv[vl]) {
                    used[p] = 1;
                }
                break;
            }else {
                vl++;
            }
        }
    }

    int vl = 2;

    for(int i = ln + 2;i <= n;i++) {
        while(used[vl] || !pr[vl]) vl++;
        printf("%d ", vl++);
    }

    return 0;
}