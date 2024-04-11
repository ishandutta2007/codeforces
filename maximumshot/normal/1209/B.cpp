#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    string s;
    cin >> s;

    const int X = 1e4;
    vector<int> cnt(X);

    for (int a, b, i = 0; i < n; i++) {
        cin >> a >> b;
        if (s[i] == '1') {
            for (int j = 0; j < b; j++) {
                cnt[j]++;
            }
            for (int j = b + a; j < X; j += 2 * a) {
                int jj = min(X, j + a);
                for (int q = j; q < jj; q++) {
                    cnt[q]++;
                }
            }
        } else {
            for (int j = b; j < X; j += 2 * a) {
                int jj = min(X, j + a);
                for (int q = j; q < jj; q++) {
                    cnt[q]++;
                }
            }
        }
    }

    cout << *max_element(cnt.begin(), cnt.end()) << "\n";

    return 0;
}