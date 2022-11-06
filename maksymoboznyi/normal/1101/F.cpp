#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

const int N = 250001;

struct driver {
    int s, f, c, r;
};

int n, m, a[N];
driver d[N];

bool check(int pos, int V) {
    if (d[pos].s < d[pos].f) {
        int curV = V, cur = 0, cur_city = d[pos].s;
        while (cur_city != d[pos].f) {
            if (curV - (a[cur_city + 1] - a[cur_city])*d[pos].c >= 0)
                curV -= (a[cur_city + 1] - a[cur_city])*d[pos].c, cur_city++;
            else {
                curV = V;
                cur++;
                if (curV - (a[cur_city + 1] - a[cur_city])*d[pos].c >= 0)
                    curV -= (a[cur_city + 1] - a[cur_city])*d[pos].c, cur_city++;
                else
                    return 0;
            }
        }
        return cur <= d[pos].r;
    } else {
        int curV = V, cur = 0, cur_city = d[pos].s;
        while (cur_city != d[pos].f) {
            if (curV - (a[cur_city] - a[cur_city - 1])*d[pos].c >= 0)
                curV -= (a[cur_city] - a[cur_city - 1])*d[pos].c, cur_city--;
            else {
                curV = V;
                cur++;
                if (curV - (a[cur_city] - a[cur_city - 1])*d[pos].c >= 0)
                    curV -= (a[cur_city] - a[cur_city - 1])*d[pos].c, cur_city--;
                else
                    return 0;
            }
        }
        return cur <= d[pos].r;
    }
}

signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++) {
        int s, f, c, r;
        cin >> s >> f >> c >> r;
        d[i] = {s, f, c, r};
    }
    random_shuffle(d + 1, d + m + 1);
    int maxV = 0;
    for (int i = 1; i <= m; i++) {
        if (check(i, maxV))
            continue;
        int l = maxV, r = 1000000000000000001;
        while (l < r - 1) {
            int mm = (l + r) / 2;
            if (check(i, mm))
                r = mm;
            else
                l = mm;
        }
        maxV = r;
        //cout << i << endl;
    }
    cout << maxV;
    return 0;
}