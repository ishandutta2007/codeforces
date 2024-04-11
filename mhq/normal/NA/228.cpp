#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
string a[105], b[105];
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int j = 1; j <= n; j++) cin >> b[j];
    int cnt1 = 0;
    int cnt2 = 0;
    int ans = 0;
    for (int i = 1; i <= 3; i++) {
        int cnt1a = 0;
        int cnt1b = 0;
        int cnt2a = 0;
        int cnt2b = 0;
        for (int j = 1; j <= n; j++) {
            if (a[j].size() == i + 1) {
                if (a[j].back() == 'L') cnt1a++;
                else cnt2a++;
            }
            if (b[j].size() == i + 1) {
                if (b[j].back() == 'L') cnt1b++;
                else cnt2b++;
            }
        }
        ans += abs(cnt1a - cnt1b);
    }
    int am = 0;
    int al = 0;
    int as = 0;
    int bl = 0;
    int bm = 0;
    int bs = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i][0] == 'M') am++;
        else if (a[i][0] == 'L') as++;
        else al++;
        if (b[i][0] == 'M') bm++;
        else if (b[i][0] == 'L') bs++;
        else bl++;
    }
    ans += (abs(am - bm) + abs(as - bs) + abs(al - bl)) / 2;
    cout << ans;
    return 0;
}