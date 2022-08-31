#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> point;

const int max_n = 300111, inf = 1000111222;

point p[max_n];
vector<point> can;
int n;

int calc(point a, point b) {
    int maxx = max(a.F, b.F);
    int minx = min(a.F, b.F);
    int maxy = max(a.S, b.S);
    int miny = min(a.S, b.S);
    int res = 0;
    int rmaxx, rminx, rmaxy, rminy;
    for (int i = 0; i < n; ++i) {
        rmaxx = max(maxx, p[i].F);
        rminx = min(minx, p[i].F);
        rmaxy = max(maxy, p[i].S);
        rminy = min(miny, p[i].S);
        res = max(res, (rmaxx - rminx) * 2 + (rmaxy - rminy) * 2);
    }
    return res;
}

int find3() {
    if (can.size() > 10) {
        exit(228);
    }
    int ans = 0;
    for (int i = 0; i < can.size(); ++i) {
        for (int j = i + 1; j < can.size(); ++j) {
            ans = max(ans, calc(can[i], can[j]));
        }
    }
    return ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &p[i].F, &p[i].S);
    }
    int minx = p[0].F, maxx = p[0].F;
    for (int i = 0; i < n; ++i) {
        minx = min(minx, p[i].F);
        maxx = max(maxx, p[i].F);
    }
    int miny = p[0].S, maxy = p[0].S;
    for (int i = 0; i < n; ++i) {
        miny = min(miny, p[i].S);
        maxy = max(maxy, p[i].S);
    }
    int more3ans = ((maxx - minx) + (maxy - miny)) * 2;
    for (int i = 0; i < n; ++i) {
        point& pt = p[i];
        if (p[i].F == minx || p[i].F == maxx || p[i].S == miny || p[i].S == maxy) {
            can.PB(pt);
        }
    }
    int ans3 = find3();
    printf("%d ", ans3);
    for (int i = 4; i <= n; ++i) {
        printf("%d ", more3ans);
    }
    return 0;
}