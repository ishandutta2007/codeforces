#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

typedef long long LL;
typedef pair<LL, int> PLI;

const int N = 222222;

bool v[N];
LL a[N], b[N], t[N];
priority_queue<PLI> q;

int main() {
    int n;
    scanf("%d", &n);
    vector<PLI> c;
    for (int i = 1; i <= n; ++i) {
        scanf("%lld%lld%lld", &a[i], &b[i], &t[i]);
        c.push_back(make_pair(a[i], -i));
        c.push_back(make_pair(b[i] - t[i], i));
    }
    sort(c.begin(), c.end());
    LL cur = -1, ans = 0;
    for (int i = 0; i < c.size(); ++i) {
        LL tm = c[i].first;
        int id = -c[i].second;
        if (cur <= tm) {
            while (!q.empty()) {
                PLI x = q.top();
                if (v[x.second]) {
                    q.pop();
                    continue;
                }
                LL du = -x.first;
                LL num = (tm - cur) / du + 1;
                ans += num;
                cur += num * du;
                break;
            }
            if (q.empty()) {
                cur = -1;
            }
        }
        if (id > 0) {
            if (tm + t[id] < cur) {
                cur = tm + t[id];
            } else if (cur == -1) {
                cur = tm;
            }
            q.push(make_pair(-t[id], id));
        } else {
            v[-id] = true;
        }
    }
    printf("%lld\n", ans);
    return 0;
}