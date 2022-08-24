#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
string s;
const int maxN = 2 * (int)1e5 + 100;
int ans[maxN];
void solve() {
    cin >> n >> s;
    string cop = s;
    int cur = n;
    int i = 1;
    while (i <= n) {
        if (i == n) {
            cout << cur << " ";
            break;
        }
        if (s[i - 1] == '>') {
            cout << cur << " ";
            cur--;
            i++;
        }
        else {
            int j = i;
            while (j - 1 < n - 1 && s[j - 1] == '<') j++;
            for (int it = i; it <= j; it++) {
                cout << cur + it - j << " ";
            }
            cur = (cur + i - j) - 1;
            i = j + 1;
        }
    }
    cout << '\n';
    i = 1;
    cur = 1;
    while (i <= n) {
        if (i == n) {
            cout << cur << " ";
            break;
        }
        if (s[i - 1] == '<') {
            cout << cur << " ";
            cur++;
            i++;
        }
        else {
            int j = i;
            while (j - 1 < n - 1 && s[j - 1] == '>') j++;
            for (int it = i; it <= j; it++) {
                cout << cur + j - it << " ";
            }
            cur = (cur + j - i) + 1;
            i = j + 1;
        }
    }
    cout << '\n';

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        solve();
    }
    return 0;
}