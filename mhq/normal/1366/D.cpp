#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 1e7 + 10;
int lp[maxN];
const int maxK = 5e5 + 10;
int f1[maxK], f2[maxK];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    for (int i = 2; i < maxN; i++) {
        if (lp[i] == 0) {
            lp[i] = i;
            for (int j = 2 * i; j < maxN; j += i) {
                lp[j] = i;
            }
        }
    }
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x % 2 == 0) {
            while (x % 2 == 0) {
                x /= 2;
            }
            if (x == 1) {
                f1[i] = f2[i] = -1;
                continue;
            }
            f1[i] = 2;
            f2[i] = x;
        }
        else {
            vector < int > pr;
            while (x > 1) {
                int p = lp[x];
                while (x % p == 0) {
                    x /= p;
                }
                pr.emplace_back(p);
            }
            sort(pr.begin(), pr.end());
            if (pr.size() == 1) {
                f1[i] = f2[i] = -1;
            }
            else {
                f1[i] = pr[0];
                f2[i] = pr[1];
            }
        }
    }
    for (int i = 1; i <= n; i++) cout << f1[i] << " ";
    cout << '\n';
    for (int i = 1; i <= n; i++) cout << f2[i] << " ";
    cout << '\n';
    return 0;
}