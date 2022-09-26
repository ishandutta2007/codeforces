#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
    []() {
        int N, K, M; cin >> N >> K >> M;
        vector<bool> alive(N, false);
        for (int i = 0; i < M; ++i) {
            int a; cin >> a;
            alive[--a] = true;
        }
        if ((N - M) % (K - 1)) {
            cout << "NO\n";
            return;
        }
        int pref = 0;
        for (int i = 0; i < N; ++i) {
            if (i) pref += !alive[i-1];
            if (alive[i] && pref >= (K/2) && (N-M-pref) >= (K/2)) {
                // cerr << i << ' ' << pref << '\n';
                // cerr << N - M - pref << '\n';
                cout << "YES\n";
                return;
            }
        }
        cout << "NO\n";
    }();
    }
}