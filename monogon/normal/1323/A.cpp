
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int t, n, a;
vector<int> v[2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        v[0].clear();
        v[1].clear();
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> a;
            v[a % 2].push_back(i);
        }
        if(!v[0].empty()) {
            cout << 1 << endl << v[0][0] << endl;
        }else if(v[1].size() >= 2) {
            cout << 2 << endl << v[1][0] << " " << v[1][1] << endl;
        }else {
            cout << -1 << endl;
        }
    }
}