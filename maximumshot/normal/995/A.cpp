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

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n, k;

    cin >> n >> k;

    vec< vec< int > > a(5, vec< int >(n + 1));

    for(int i = 1;i <= 4;i++) {
        for(int j = 1;j <= n;j++) {
            scanf("%d", &a[i][j]);
        }
    }

    vec< tuple< int, int, int > > res;

    int ei = -1, ej;

    for(int i = 1;i <= n;i++) {
        if(!a[2][i]) {
            ei = 2;
            ej = i;
            continue;
        }
        if(a[2][i] == a[1][i]) {
            res.push_back({a[2][i], 1, i});
            a[2][i] = 0;
            ei = 2;
            ej = i;
        }
    }
    for(int i = 1;i <= n;i++) {
        if(!a[3][i]) {
            ei = 3;
            ej = i;
            continue;
        }
        if(a[3][i] == a[4][i]) {
            res.push_back({a[3][i], 4, i});
            a[3][i] = 0;
            ei = 3;
            ej = i;
        }
    }

    if(ei == -1) {
        puts("-1");
        return 0;
    }

    for(int iter = 1;iter < 2 * n;iter++) {
        // rotate
        if(ei == 2) {
            for(int j = ej - 1;j >= 1;j--) {
                if(a[2][j]) {
                    res.push_back({a[2][j], 2, j + 1});
                    swap(a[2][j], a[2][j + 1]);
                }
            }
            if(a[3][1]) {
                res.push_back({a[3][1], 2, 1});
                swap(a[3][1], a[2][1]);
            }
            for(int j = 2;j <= n;j++) {
                if(a[3][j]) {
                    res.push_back({a[3][j], 3, j - 1});
                    swap(a[3][j], a[3][j - 1]);
                }
            }
            if(ej < n) {
                if(a[2][n]) {
                    res.push_back({a[2][n], 3, n});
                    swap(a[2][n], a[3][n]);
                }
                ej++;
                for(int j = n - 1;j >= ej;j--) {
                    if(a[2][j]) {
                        res.push_back({a[2][j], 2, j + 1});
                        swap(a[2][j], a[2][j + 1]);
                    }
                }
            }else {
                ei++;
            }
        }else {
            for(int j = ej + 1;j <= n;j++) {
                if(a[3][j]) {
                    res.push_back({a[3][j], 3, j - 1});
                    swap(a[3][j], a[3][j - 1]);
                }
            }
            if(a[2][n]) {
                res.push_back({a[2][n], 3, n});
                swap(a[2][n], a[3][n]);
            }
            for(int j = n - 1;j >= 1;j--) {
                if(a[2][j]) {
                    res.push_back({a[2][j], 2, j + 1});
                    swap(a[2][j], a[2][j + 1]);
                }
            }
            if(ej > 1) {
                if(a[3][1]) {
                    res.push_back({a[3][1], 2, 1});
                    swap(a[3][1], a[2][1]);
                }
                ej--;
                for(int j = 2;j <= ej;j++) {
                    if(a[3][j]) {
                        res.push_back({a[3][j], 3, j - 1});
                        swap(a[3][j], a[3][j - 1]);
                    }
                }
            }else {
                ei--;
            }
        }
        for(int i = 1;i <= n;i++) {
            if(!a[2][i]) continue;
            if(a[2][i] == a[1][i]) {
                res.push_back({a[2][i], 1, i});
                a[2][i] = 0;
                ei = 2;
                ej = i;
            }
        }
        for(int i = 1;i <= n;i++) {
            if(!a[3][i]) continue;
            if(a[3][i] == a[4][i]) {
                res.push_back({a[3][i], 4, i});
                a[3][i] = 0;
                ei = 3;
                ej = i;
            }
        }
    }

    printf("%d\n", (int)res.size());

    for(auto tu : res) {
        int i, r, c;
        tie(i, r, c) = tu;
        printf("%d %d %d\n", i, r, c);
    }

    return 0;
}