#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
int val[55];
int p[55];
int bck[55];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        p[i] = i;
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            val[i] += x;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (val[i] > val[j]) {
                swap(val[i], val[j]);
                swap(p[i], p[j]);
            }
        }
    }
    for (int i = 1; i <= n; i++) bck[p[i]] = i;
    for (int i = 1; i <= n; i++) cout << bck[i] << " ";
    return 0;
}