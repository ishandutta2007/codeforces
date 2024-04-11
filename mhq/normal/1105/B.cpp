#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int best = 0;
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    for (int j = 0; j < 26; j++) {
        int cur = 0;
        int last = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != j + 'a') {
                last = 0;
                continue;
            }
            else {
                last++;
                if (last == k) {
                    cur++;
                    last = 0;
                }
            }
        }
        best = max(best, cur);
    }
    cout << best;
    return 0;
}