#include <bits/stdc++.h>    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair
    
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    vector<int> ans;
    bool any = false;
    for (int i = 0; i <= m - n; i++) {
        vector<int> cur;
        for (int j = 0; j < n; j++)
            if (s[j] != t[i + j])
                cur.push_back(j);
        if (!any || cur.size() < ans.size()) {
            any = true;
            ans = cur;
        }
    }
    cout << ans.size() << "\n";
    for (int x : ans)
        cout << x + 1 << " ";
    cout << "\n";
}