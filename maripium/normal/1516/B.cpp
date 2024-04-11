#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int T; cin >> T;

    while (T--) {
        int N; cin >> N;

        vector<int> pref(N+1);
        for (int i = 0; i < N; ++i) {
            int a; cin >> a;
            pref[i+1] = pref[i] ^ a;
        }

        if (pref[N] == 0) {
            cout << "YES\n";
            continue;
        }

        int state = 0;
        for (int i = 1; i <= N-1; ++i) {
            if (state == 0 && pref[i] == pref[N]) {
                state = 1;
            } else if (state == 1 && pref[i] == 0) {
                state = 2;
            }
        }
        cout << (state == 2 ? "YES" : "NO") << '\n';
    }
}