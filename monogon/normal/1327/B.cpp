
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1e5 + 5;
int t, n, k, g;
// vector<int> g[N];
bool b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        fill(b, b + n + 1, false);
        int idx = 0;
        for(int i = 0; i < n; i++) {
            cin >> k;
            // g[i].clear();
            bool flag = true;
            for(int j = 0; j < k; j++) {
                cin >> g;
                if(flag && !b[g]) {
                    b[g] = true;
                    flag = false;
                }
            }
            if(flag) {
                idx = i + 1;
            }
        }
        if(idx == 0) {
            cout << "OPTIMAL\n";
        }else {
            cout << "IMPROVE\n" << idx << " ";
            for(int i = 1; i <= n; i++) {
                if(!b[i]) {
                    cout << i << "\n";
                    break;
                }
            }
        }
    }
}