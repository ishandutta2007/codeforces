
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1e5 + 5;
int t, n, m, a, b, p[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> m;
        for(int i = 0; i < n; i++) {
            cin >> a;
            p[a] = i;
        }
        int M = -1;
        ll cnt = 0;
        for(int i = 0; i < m; i++) {
            cin >> b;
            if(p[b] < M) {
                cnt++;
            }else {
                cnt += 2 * (p[b] - i) + 1;
                M = p[b];
            }
        }
        cout << cnt << endl;
    }
}