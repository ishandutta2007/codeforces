#include<bits/stdc++.h>
using namespace std;
const int nax = 4e5 + 10;
int n;
char s[nax];
int b[nax];

void solve() {
    cin >> n >> s;
    int start = -1;
    for (int i = 0 ; i < n ; ++ i) {
        if (s[i] == '1') {
            start = i;
            break;
        }
    }
    if (start == -1) {
        cout << "NO\n";
        return;
    }
    int sum = 0;
    for (int i = 0 ; i < n ; ++ i) {
        b[i] = s[(start + i) % n] - '0';
        sum += b[i];
   //     cout << b[i] << ' ';
    }
//    cout << '\n';
    if (sum % 2) {
        cout << "NO\n";
        return;
    }
    assert(start != -1);
    /**
     * 
     * 
     * 
     * 100000|111111|100000000|1111100000|111111|1000000
     * there must be odd degree nodes in tree
    */
    vector <pair <int, int>> ans;
    int f = -1;
    for (int i = 0 ; i < n ; ++ i) {
        if (b[i] == 1 && (i + 1 < n && b[i + 1] == 0)) {
            int j = i + 1; /// 1 1 0 0
            while (j < n && b[j] == 0) {
                ans.emplace_back(j - 1, j);
                j += 1;
            }
            if (f != -1) ans.emplace_back(f, ans.back().second);
            else f = ans.back().second;
            i = j - 1;
        } else if (b[i] == 1 && f != -1) {
            ans.emplace_back(f, i);
        } else f = i;
       // 1 | 1 0 0
    
        /// 1 1 0 0
        /// 1 2 3 0
    }
    cout << "YES\n";//1001
    for (auto [u, v] : ans) {
      //  cout << u << ' ' << v << '\n';
        u = (n + u + start) % n + 1 ;
        v = (n + v + start) % n + 1;
        cout << u << ' ' << v << '\n';
    }
    
}

int main() {
    int T;
    cin.tie(0)->sync_with_stdio(false);
    for (cin >> T ; T -- ;) {
        solve();
    }
}