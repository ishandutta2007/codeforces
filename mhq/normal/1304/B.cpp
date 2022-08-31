#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;
string s[105];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    int cnt = 0;
    string ans;
    string rv;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        string t = s[i];
        reverse(t.begin(), t.end());
        if (t == s[i] && rv.empty()) {
            cnt++;
            rv += t;
        }
        else {
            for (int j = 0; j < i; j++) {
                if (t == s[j]) {
                    ans += t;
                    cnt += 2;
                    break;
                }
            }
        }
    }
    cout << 2 * ans.size() + rv.size() << '\n';
    cout << ans + rv;
    reverse(ans.begin(), ans.end());
    cout << ans;
    return 0;
}