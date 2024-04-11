
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1e5 + 5;
int n, q, r, c;
set<pair<int, int>> s;
bool a[2][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for(int i = 0; i < q; i++) {
        cin >> r >> c;
        r--; c--;
        a[r][c] = !a[r][c];
        if(a[r][c]) {
            if(r) {
                if(c > 0 && a[0][c - 1]) s.emplace(c, c - 1);
                if(a[0][c]) s.emplace(c, c);
                if(c < n && a[0][c + 1]) s.emplace(c, c + 1);
            }else {
                if(c > 0 && a[1][c - 1]) s.emplace(c - 1, c);
                if(a[1][c]) s.emplace(c, c);
                if(c < n && a[1][c + 1]) s.emplace(c + 1, c);
            }
        }else if(r) {
            s.erase({c, c - 1});
            s.erase({c, c});
            s.erase({c, c + 1});
        }else {
            s.erase({c - 1, c});
            s.erase({c, c});
            s.erase({c + 1, c});
        }
        cout << (s.empty() ? "Yes" : "No") << endl;
    }
}