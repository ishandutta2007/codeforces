
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1e5 + 5;
int t, n;
ll a[N], s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> s;
        ll sum = 0;
        int best = 0, part = 0, part2 = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
            if(a[i] > a[part]) part = i;
            if(sum <= s) best = max(best, i + 1);
            if(sum - a[part] <= s) {
                best = max(best, i);
                part2 = part;
            }
        }
        cout << (best == n ? 0 : part2 + 1) << endl;
    }
}