#include<bits/stdc++.h>
#define int long long
using namespace std;

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector <int> s(n), g(n);
    vector <int> left(n), right(n);
    for(int i = 0; i< n; i++){
        cin >> s[i] >> g[i];
        if(i == 0) {
            left[i] = s[i];
            right[i] = s[i] + g[i];
        }
        else {
            left[i] = max(s[i], left[i - 1] - 1);
            right[i] = min(right[i - 1] + 1, s[i] + g[i]);
        }
        if(left[i] > right[i]) {
            cout << -1;
            return 0;
        }
    }
    vector <int> ans(n);
    int cur = right[n - 1];
    ans[n - 1] = cur;
    for(int i = n - 2; i >= 0; i--) {
        cur = min(right[i], cur + 1);
        ans[i] = cur;
    }
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += ans[i] - s[i];
    }
    cout << sum << "\n";
    for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}