#include <bits/stdc++.h>
using namespace std;
long long n;
const int maxN = 2 * (int)1e5 + 10;
long long a[maxN];
map < long long, int > need;
long long cnt1 = 0;
long long cnt2 = 0;
unsigned long long x1;
unsigned long long x2;
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        long long t = (1LL * n - 1 - 2 * (n - i)) * (1LL * a[i]);
        if (t > 0) x1 += t;
        else x2 += (-t);
    }
    //cout << ans;
    for (int i = 1; i <= n; i++) {
        auto it = need.find(a[i] + 1);
        if (it != need.end()) {
            cnt1 += it -> second;
        }
        it = need.find(a[i] - 1);
        if (it != need.end()) {
            cnt2 += it -> second;
        }
        it = need.find(a[i]);
        if (it != need.end()) {
            need[it -> first] = it -> second + 1;
        }
        else {
            need[a[i]] = 1;
        }
    }
    if (cnt1 > 0) x1 += cnt1;
    else x2 += (-cnt1);
    if (cnt2 > 0) x2 += cnt2;
    else x1 += (-cnt2);
    if (x1 >= x2) cout << x1 - x2;
    else cout << "-"<< x2 - x1;
    return 0;
}