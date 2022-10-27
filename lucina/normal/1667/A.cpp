#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
int a[nax];

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;
    for (int i = 1 ; i <= n ; ++ i)
        cin >> a[i];
    int64_t mn_ans = 1e18;
    for (int i = 1 ; i <= n ; ++ i) {
        int64_t ans = 0;
        for (int64_t lst = 0, j = i + 1 ; j <= n ; ++ j) {
            int64_t d = (lst + 1 + a[j] - 1) / a[j];
            ans += d;
            lst = d * a[j];
        }

        for (int64_t lst = 0, j = i - 1 ; j >= 1 ; -- j) {
            int64_t d = (lst + 1 + a[j] - 1) / a[j];
            ans += d;
            lst = d * a[j];
        }
        mn_ans = min(mn_ans, ans);
    }
    cout << mn_ans << '\n';
}
/**
    long time no div.1
*/