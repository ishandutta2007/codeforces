#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    vector<ll> pw(10);
    pw[0] = 1;
    for (int i = 1; i < 10; i++)
        pw[i] = pw[i - 1] * 26;

    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        for (int l = 1;;l++) {
            unordered_map<string, int> cnt;
            for (int i = 0; i + l - 1 < n; i++) {
                string tmp;
                for (int j = 0; j < l; j++) {
                    tmp.push_back(s[i + j]);
                    cnt[tmp]++;
                }
            }
            int ok = 0;
            string res;
            for (int i = 0; i < l; i++) {
                for (char c = 'a'; c <= 'z'; c++) {
                    string tmp = res;
                    tmp.push_back(c);
                    if (cnt[tmp] >= pw[l - i - 1]) continue;
                    res = tmp;
                    break;
                }
            }
            if ((int) res.size() == l) {
                cout << res << "\n";
                break;
            }
        }
    }

    return 0;
}