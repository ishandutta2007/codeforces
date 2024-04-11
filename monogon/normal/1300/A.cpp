
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int t, n, a[105];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        int sum = 0, cnt = 0, pos = 0, m1 = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(a[i] == 0) {
                a[i]++;
                cnt++;
            }
            pos += (a[i] > 0);
            m1 += (a[i] == -1);
            sum += a[i];
        }
        if(sum == 0) {
            cnt++;
            if(m1 == n) cnt++;
        }
        cout << cnt << endl;
    }
}