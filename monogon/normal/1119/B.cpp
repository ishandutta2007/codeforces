
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1e3 + 5;
int n;
ll h, a[N], dp[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> h;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dp[0] = 0;
    for(int i = 1; i <= n; i++) {
        vector<int> v(a + 1, a + i + 1);
        sort(v.begin(), v.end());
        for(int j = i - 1; j >= 0; j -= 2) {
            dp[i] += v[j];
        }
    }
    for(int i = n; i >= 0; i--) {
        if(dp[i] <= h) {
            cout << i << endl;
            return 0;
        }
    }
}