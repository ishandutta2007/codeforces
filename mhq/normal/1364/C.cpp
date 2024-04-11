#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 1e5 + 10;
int b[maxN];
int n;
int a[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    int lst = 0;
    vector < int > free;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] != lst) {
            b[i] = lst;
            for (int j = lst + 1; j < a[i]; j++) {
                if (free.empty()) {
                    cout << -1 << '\n';
                    return 0;
                }
                b[free.back()] = j;
                free.pop_back();
            }
            lst = a[i];
        }
        else {
            free.emplace_back(i);
        }
    }
    while (!free.empty()) {
        b[free.back()] = n + 10;
        free.pop_back();
    }
    for (int i = 1; i <= n; i++) cout << b[i] << " ";
    return 0;
}