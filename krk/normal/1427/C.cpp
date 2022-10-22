#include <bits/stdc++.h>
using namespace std;

const int Inf = 1000000000;
const int lim = 1005;

typedef pair <int, int> ii;
typedef pair <ii, ii> iiii;

int r, n;
deque <iiii> seq;
int all;
int ans;

int main()
{
    scanf("%d %d", &r, &n);
    all = -Inf;
    seq.push_back(iiii(ii(0, 0), ii(1, 1)));
    for (int i = 0; i < n; i++) {
        int t, x, y; scanf("%d %d %d", &t, &x, &y);
        while (!seq.empty() && seq.front().first.first <= t - lim) {
            all = max(all, seq.front().first.second);
            seq.pop_front();
        }
        int res = all + 1;
        for (int i = 0; i < seq.size(); i++) {
            int nd = seq[i].first.first + abs(seq[i].second.first - x) + abs(seq[i].second.second - y);
            if (nd <= t) res = max(res, seq[i].first.second + 1);
        }
        seq.push_back(iiii(ii(t, res), ii(x, y)));
    }
    ans = all;
    for (int i = 0; i < seq.size(); i++)
        ans = max(ans, seq[i].first.second);
    printf("%d\n", ans);
    return 0;
}