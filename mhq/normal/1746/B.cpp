#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> prefZero(n + 1);
        vector<int> prefOne(n + 1);
        int cnt_one = 0;
        int cur_bal = 0;
        int max_bal = 0;
        int cnt_zero = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == 0) {
                cnt_zero++;
            }
            else {
                cnt_one++;
            }
        }
        int cur_zero = 0;
        int cur_one = 0;
        int best = max(cnt_zero, cnt_one);
        for (int i = 0; i < n; i++) {
            if (a[i] == 0) {
                cur_zero++;
            }
            else {
                cur_one++;
            }
            best = max(best, cur_zero + (cnt_one - cur_one) + min(cur_one, cnt_zero - cur_zero));
        }
        cout << n - best << '\n';
    }
    return 0;
}