#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int f1 = 0;
        int f2 = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '<' || s[i] == '-') f1++;
            if (s[i] == '>' || s[i] == '-') f2++;
        }
        if (f1 == n || f2 == n) {
            cout << n << '\n';
        }
        else {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (s[i] == '-' || s[(i + 1) % n] == '-') cnt++;
            }
            cout << cnt << '\n';
        }
    }
    return 0;
}