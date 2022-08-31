#include <bits/stdc++.h>
using namespace std;
const int maxN = 2 *(int)1e5 + 10;
int n;
long long a[maxN];
long long ans;
priority_queue < long long > hp;
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        hp.push(-a[i]);
    }
    if (n % 2 == 0) {
            hp.push(0);
            n++;
    }
    while (n > 1) {
        long long a1 = -hp.top();
        hp.pop();
        long long a2 = -hp.top();
        hp.pop();
        long long a3 = -hp.top();
        hp.pop();
        ans += a1 + a2 + a3;
        hp.push(-a1 - a2 - a3);
        n -= 2;
    }
    cout << ans;
    return 0;
}