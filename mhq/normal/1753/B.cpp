#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxN = 5e5 + 10;
int cnt[maxN];
int n, x;
int a[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    int f = 0;
    for (int i = 1; i < x; i++) {
        f += cnt[i];
        if (f % (i + 1) != 0) {
            cout << "No\n";
            return 0;
        }
        f /= (i + 1);
    }
    cout << "Yes\n";

    return 0;
}