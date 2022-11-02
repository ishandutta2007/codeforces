#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    int pos = 0;
    set<int> st[26];
    int n = s.length(), m = t.length();
    for(int i = 0; i < n; ++i)
            st[s[i] - 'a'].insert(i);
    int res = 1, cur = -1;
    for(int j = 0; j < m; ++j) {
        set<int>::iterator ii = st[t[j] - 'a'].upper_bound(cur);
        if(ii == st[t[j] - 'a'].end())
              res++, cur = -1;
        ii = st[t[j] - 'a'].upper_bound(cur);
        if(ii == st[t[j] - 'a'].end()) {
              cout << -1;
              return 0;
        }
        cur = *ii;
    }
    cout << res;
    cin >> n;
    return 0;
}