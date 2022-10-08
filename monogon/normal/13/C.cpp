
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int n, a;
ll ans;
priority_queue<int> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    while(n--) {
        cin >> a;
        pq.push(a); pq.push(a);
        ans += pq.top() - a; pq.pop();
    }
    cout << ans << endl;
}