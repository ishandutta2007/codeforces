
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5;
int t, n, a[N];
bool covered[N];

bool checkperm(int L, int R) {
    fill(covered + 1, covered + R - L + 2, 0);
    for(int i = L; i <= R; i++) {
        covered[a[i]] = true;
    }
    for(int i = 1; i <= R - L + 1; i++) {
        if(!covered[i]) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        int mx = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            mx = max(mx, a[i]);
        }
        vector<pair<int, int>> ways;
        if(checkperm(0, mx - 1) && checkperm(mx, n - 1)) {
            ways.emplace_back(mx, n - mx);
        }
        if(mx * 2 != n && checkperm(0, n - mx - 1) && checkperm(n - mx, n - 1)) {
            ways.emplace_back(n - mx, mx);
        }
        cout << ways.size() << endl;
        for(auto p : ways) {
            cout << p.first << " " << p.second << endl;
        }
    }
}