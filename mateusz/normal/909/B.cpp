#include <bits/stdc++.h>

using namespace std;

int cnt[100005];

int main() {
    int n;
    cin >> n;
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            bool found = false;
            for (int k = i - j; k >= 1; k--) {
                if (cnt[k] > 0) {
                    cnt[k]--;
                    found = true;
                    break;
                }
            }
            cnt[i]++;
            if (found == false) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}