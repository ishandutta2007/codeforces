
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5;
int n, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) {
        if(a[i] == 0) {
            rotate(a, a + i + 1, a + n);
            break;
        }
    }
    int cnt = 0, ans = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == 1) cnt++;
        else cnt = 0;
        ans = max(ans, cnt);
    }
    cout << ans << endl;
}