#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const K = 505;

int n, m, k;
pii crd[K];

bool check(int t) {
    vec< int > xx, yy;
    for(int i = 1;i <= k;i++) {
        int x, y;
        tie(x, y) = crd[i];
        if(x - t - 1 >= 1) xx.push_back(x - t - 1);
        if(y - t - 1 >= 1) yy.push_back(y - t - 1);
        if(x + t + 1 <= n) xx.push_back(x + t + 1);
        if(y + t + 1 <= m) yy.push_back(y + t + 1);
    }

    xx.push_back(1);
    xx.push_back(n);
    yy.push_back(1);
    yy.push_back(m);

    sort(ALL(xx));
    sort(ALL(yy));
    xx.resize(unique(ALL(xx)) - xx.begin());
    yy.resize(unique(ALL(yy)) - yy.begin());

    int lx = inf + 10;
    int rx = -inf - 10;
    int ly = inf + 10;
    int ry = -inf - 10;

    for(int x : xx) {
        vec< pii > mas;
        for(int i = 1;i <= k;i++) {
            if(crd[i].first - t <= x && x <= crd[i].first + t) {
                mas.push_back(make_pair(max(1, crd[i].second - t), min(m, crd[i].second + t)));
            }
        }
        sort(ALL(mas));
        int last = 0;
        int len = 0;
        for(pii seg : mas) {
            if(last < seg.first) {
                len += seg.second - seg.first + 1;
                last = seg.second;
            }else if(last < seg.second) {
                len += seg.second - last;
                last = seg.second;
            }
        }
        if(len < m) {
            lx = min(lx, x);
            rx = max(rx, x);
        }
    }

    for(int y : yy) {
        vec< pii > mas;
        for(int i = 1;i <= k;i++) {
            if(crd[i].second - t <= y && y <= crd[i].second + t) {
                mas.push_back(make_pair(max(1, crd[i].first - t), min(n, crd[i].first + t)));
            }
        }
        sort(ALL(mas));
        int last = 0;
        int len = 0;
        for(pii seg : mas) {
            if(last < seg.first) {
                len += seg.second - seg.first + 1;
                last = seg.second;
            }else if(last < seg.second) {
                len += seg.second - last;
                last = seg.second;
            }
        }
        if(len < n) {
            ly = min(ly, y);
            ry = max(ry, y);
        }
    }

    if(lx == inf + 10) {
        return true;
    }else {
        if(rx - lx + 1 <= 2 * t + 1 &&
           ry - ly + 1 <= 2 * t + 1) {
            return true;
        }else {
            return false;
        }
    }
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d %d", &n, &m, &k);

    for(int i = 1;i <= k;i++) {
        scanf("%d %d", &crd[i].first, &crd[i].second);
    }

    int bl = -1;
    int br = inf;
    int bm;

    while(br - bl > 1) {
        bm = (bl + br) / 2;
        if(check(bm)) {
            br = bm;
        }else {
            bl = bm;
        }
    }

    printf("%d\n", br);

    return 0;
}