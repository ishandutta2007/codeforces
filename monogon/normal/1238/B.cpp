
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1e5 + 5;
int q, n, r, x;
vector<int> s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> q;
    while(q--) {
        cin >> n >> r;
        s.clear();
        for(int i = 0; i < n; i++) {
            cin >> x;
            s.push_back(x);
        }
        int M = 0;
        sort(s.begin(), s.end());
        s.erase(unique(s.begin(), s.end()), s.end());
        n = s.size();
        for(int i = 0; i < n; i++) {
            M = max(M, min((s[i] + r - 1) / r, n - i));
        }
        cout << M << endl;
    }
}