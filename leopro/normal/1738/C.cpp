#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

#define answer(out) { cout << (out) << '\n'; return; }
#define answerExit(out) { cout << (out) << '\n'; exit(0); }

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    do { solve(); } while (--t);
    return 0;
}

void solve() {
    int n = 202;
    vector eA(n, vector(n, false)), eB(n, vector(n, false)), oA(n, vector(n, false)), oB(n, vector(n, false));
    eA[0][0] = eB[0][0] = true;
    for (int s = 1; s < n; ++s) {
        for (int i = 0; i <= s; ++i) {
            int j = s - i;
            eA[i][j] = (i && eB[i - 1][j]) || (j && oB[i][j - 1]);
            oA[i][j] = (i && oB[i - 1][j]) || (j && eB[i][j - 1]);
            eB[i][j] = (!i || eA[i - 1][j]) && (!j || eA[i][j - 1]);
            oB[i][j] = (!i || oA[i - 1][j]) && (!j || oA[i][j - 1]);
        }
    }
    int t;
    cin >> t;
    for (int tc = 0; tc < t; ++tc) {
        cin >> n;
        int cnt0 = 0, cnt1 = 0;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            (x & 1 ? cnt1 : cnt0)++;
        }
        cout << (eA[cnt0][cnt1] ? "Alice" : "Bob") << '\n';
    }
}