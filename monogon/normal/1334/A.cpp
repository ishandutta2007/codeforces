
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 105;
int t, n;
int p[N], c[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        bool flag = true;
        for(int i = 0; i < n; i++) {
            cin >> p[i] >> c[i];
            if(p[i] < p[i - 1] || c[i] < c[i - 1] || p[i] - p[i - 1] < c[i] - c[i - 1]) {
                flag = false;
            }
        }
        cout << (flag ? "YES" : "NO") << '\n';
    }
}