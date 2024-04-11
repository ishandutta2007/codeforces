#include <bits/stdc++.h>
using namespace std;

const int N = 2E5 + 5;

int n, u;
long long ans = 0;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    while (n--) {
        cin >> u;
        if (!pq.empty() && pq.top() < u) {
            ans += u - pq.top();
            pq.pop(); pq.push(u);
        }
        pq.push(u);
    }
    cout << ans;
}