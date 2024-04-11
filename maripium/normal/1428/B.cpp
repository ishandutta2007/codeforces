#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        string S; cin >> S;
        vector<bool> ok(N, false);
        for (int i = 0; i < N; ++i) {
            if (S[i] == '-') {
                ok[i] = true;
                ok[(i+1)%N] = true;
            }
        }
        for (char c : {'>', '<'}) {
            bool f = true;
            for (int i = 0; i < N; ++i) {
                if (S[i] != '-' && S[i] != c) {
                    f = false;
                }
            }
            if (f) fill(ok.begin(), ok.end(), true);
        }
        cout << count(ok.begin(), ok.end(), true) << '\n';
    }
}