
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1e5 + 5;
int t, n;
int p[N], ans[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> p[i];
        }
        set<int> s;
        for(int i = 1; i <= n; i++) s.insert(i);
        s.erase(p[0]);
        ans[0] = p[0];
        for(int i = 1; i < n; i++) {
            ans[i] = p[i];
            if(p[i] == p[i - 1]) {
                ans[i] = *s.begin();
                if(ans[i] > p[i]) {
                    cout << -1 << endl;
                    goto endloop;
                }
            }
            s.erase(ans[i]);
        }
        for(int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        endloop:;
    }
}