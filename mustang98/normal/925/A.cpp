#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100111, inf = 1000111222;

vector<int> l;
vector<int> e;

int cntl, cnte;
int v;

int calc(int i1, int j1, int i2, int j2, int j, bool l) {
    ll ansh = 0;
    ll answ = 0;
    if (l) {
        ansh = abs(i1 - i2);
    } else {
        int d = abs(i1 - i2);
        ansh = d / v;
        if (d % v) {
            ansh++;
        }
    }
    answ = abs(j1 - j) + abs(j2 - j);
    return answ + ansh;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    cin >> cntl >> cnte >> v;
    for (int i = 0; i < cntl; ++i) {
        int cl;
        scanf("%d", &cl);
        l.PB(cl);
    }
    for (int i = 0; i < cnte; ++i) {
        int ce;
        scanf("%d", &ce);
        e.PB(ce);
    }
    int q;
    cin >> q;
    int i1, j1, i2, j2;
    for (int i = 0; i < q; ++i) {
        scanf("%d %d %d %d", &i1, &j1, &i2, &j2);
        if (i1 == i2) {
            printf("%d\n", abs(j1 - j2));
            continue;
        }
        int ans = inf;
        if (j1 > j2) {
            swap(j1, j2);
        }
        if (!l.empty()) {
            vector<int>::iterator lr = lower_bound(l.begin(), l.end(), j1);
            if (lr != l.end()) {
                ans = min(ans, calc(i1, j1, i2, j2, *lr, 1));
            }
            if (lr != l.begin()) {
                lr--;
                ans = min(ans, calc(i1, j1, i2, j2, *lr, 1));
            }
        }
        if (!e.empty()) {
            vector<int>::iterator er = lower_bound(e.begin(), e.end(), j1);
            if (er != e.end()) {
                ans = min(ans, calc(i1, j1, i2, j2, *er, 0));
            }
            if (er != e.begin()) {
                er--;
                ans = min(ans, calc(i1, j1, i2, j2, *er, 0));
            }
        }
        if (ans == inf) {
            printf("-1\n");
        } else {
            printf("%d\n", ans);
        }
    }

    return 0;
}