
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1e5 + 5;
int t, n;
ll a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        ll sum1 = 0, sum2 = 0, best = INT_MIN;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            sum1 += a[i];
        }
        for(int i = 0; i < n - 1; i++) {
            sum2 += a[i];
            best = max(best, sum2);
            if(sum2 < 0) sum2 = 0;
        }
        sum2 = 0;
        for(int i = n - 1; i > 0; i--) {
            sum2 += a[i];
            best = max(best, sum2);
            if(sum2 < 0) sum2 = 0;
        }
        cout << (sum1 > best ? "YES" : "NO") << endl;
    }
}