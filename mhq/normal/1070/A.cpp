#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxN = (int)1e5 + 10;
int d, s;
int dist[505][5005];
pair < int, int > prv[505][5005];
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> d >> s;
    memset(dist, -1, sizeof dist);
    dist[0][0] = 0;
    queue < pair < int, int > > q;
    q.push(make_pair(0, 0));
    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        int res = t.first;
        int sum = t.second;
        for (int j = 0; j < 10; j++) {
            int nxt_res = (res * 10 + j) % d;
            int nxt_sum = sum + j;
            if (nxt_sum > s) continue;
            if (dist[nxt_res][nxt_sum] == -1) {
                dist[nxt_res][nxt_sum] = dist[res][sum] + 1;
                prv[nxt_res][nxt_sum] = make_pair(res, sum);
                q.push(make_pair(nxt_res, nxt_sum));
            }
        }
    }
    if (dist[0][s] == -1) {
        cout << -1;
        return 0;
    }
    string ans;
    int res = 0;
    int sum = s;
    while (make_pair(res, sum) != make_pair(0, 0)) {
        auto t = prv[res][sum];
        ans += (char)(sum - t.second + '0');
        sum = t.second;
        res = t.first;
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
    return 0;
}