#include <bits/stdc++.h>

using namespace std;

const long long inf = 1e15;
int n, k;
string s, t;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k >> s >> t;
    long long ans = 0;
    int h = 0;
    int flag = 0;
    for (int i = 0; i < n; ++i) {
        h = min(k, h * 2 + t[i] - s[i]);
        ans += min(k, h + 1);
    }
    cout << ans << endl;
    return 0;
}