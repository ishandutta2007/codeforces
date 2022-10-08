
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 505;
int n, a[N], dp[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dp[0] = 0;
    for(int i = 1; i <= n; i++) {
        dp[i] = i;
        stack<int> s;
        for(int j = i; j >= 1; j--) {
            int x = a[j];
            while(!s.empty() && s.top() == x) {
                s.pop();
                x++;
            }
            s.push(x);
            dp[i] = min(dp[i], (int) s.size() + dp[j - 1]);
        }
    }
    cout << dp[n] << endl;
}