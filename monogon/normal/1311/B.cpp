
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 105;
int t, n, m, a[N], p[N];
bool b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> m;
        fill(b, b + n, false);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for(int i = 0; i < m; i++) {
            cin >> p[i];
            b[p[i] - 1] = true;
        }
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                if(a[i] > a[i + 1] && b[i]) swap(a[i], a[i + 1]);
            }
        }
        bool flag = true;
        for(int i = 0; i < n - 1; i++) {
            if(a[i] > a[i + 1]) flag = false;
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
}