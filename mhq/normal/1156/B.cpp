#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
int z;
const int maxN = 2 * (int)1e5 + 100;
int x[maxN];
bool used[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
     //   cout << tst << endl;
        string s;
        cin >> s;
        vector < int > cnt(26);
        for (char& c : s) cnt[c - 'a']++;
        int od = 0, ev = 0;
        for (int i = 0; i < 26; i++) {
            if (i & 1) od += cnt[i];
            else ev += cnt[i];
        }
        if (od == 0 || ev == 0) {
            cout << s << '\n';
            continue;
        }
        bool ok = false;
        for (int i = 0; i < 26; i += 2) {
            if (ok) break;
            for (int j = 1; j < 26; j += 2) {
                if (ok) break;
                if (cnt[i] > 0 && cnt[j] > 0) {
                    if (abs(i - j) == 1) continue;
                    ok = true;
                    cnt[i]--;
                    cnt[j]--;
                    for (int k = 0; k < 26; k += 2) {
                        for (int t = 0; t < cnt[k]; t++) {
                            cout << (char)('a' + k);
                        }
                    }
                    cout << (char)('a' + i);
                    cout << (char)('a' + j);
                    for (int k = 1; k < 26; k += 2) {
                        for (int t = 0; t < cnt[k]; t++) {
                            cout << (char)('a' + k);
                        }
                    }
                    cout << '\n';
                    break;
                }
            }
        }
        if (ok) {
            continue;
        }
        else {
            cout << "No answer" << '\n';
        }
    }
    return 0;
}