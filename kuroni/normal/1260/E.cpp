#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n), b;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == -1) {
            for (int j = 0; j <= i; j++) {
                a[j] = 0;
            }
        }
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(a.back()); a.pop_back();
    long long ans = 0;
    for (; n >= 1; n /= 2) {
        ans += pq.top(); pq.pop();
        for (int i = 0; i < n / 2; i++) {
            pq.push(a.back());
            a.pop_back();
        }
    }
    cout << ans;
}