
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1e5 + 5;
int t, n, a[N], b[N];
bool bb[N][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            bb[i][0] = bb[i - 1][0] || (a[i] == 1);
            bb[i][1] = bb[i - 1][1] || (a[i] == -1);
        }
        bool flag = true;
        for(int i = 1; i <= n; i++) {
            cin >> b[i];
            if((b[i] < a[i] && !bb[i - 1][1]) || (b[i] > a[i] && !bb[i - 1][0])) flag = false;
        }
        cout << (flag ? "YES" : "NO") << '\n';
    }
}