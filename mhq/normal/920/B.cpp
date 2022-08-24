#include <bits/stdc++.h>
using namespace std;
int t, n;
int l[1005];
int r[1005];
int ans[1005];
queue < int > q;
int timer;
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> l[i] >> r[i];
    timer = 0;
    int curind = 1;
    while (!q.empty()) q.pop();
    while (timer <= 5005) {
        while (l[curind] == timer && curind <= n) {
            q.push(curind);
            curind++;
        }
        while (!q.empty() && r[q.front()] < timer) {
            ans[q.front()] = 0;
            q.pop();
        }
        if (!q.empty() && l[q.front()] <= timer && timer <= r[q.front()]) {
            ans[q.front()] = timer;
            q.pop();
            timer++;
            continue;
        }
        timer++;
    }
    while (!q.empty()) {
        ans[q.front()] = 0;
        q.pop();
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << '\n';
}
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> t;
    for (int i = 1; i <= t; i++) solve();
    return 0;
}