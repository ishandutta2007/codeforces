#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int N, K; cin >> N >> K;
        vector<int> A(N), B(K);
        for (int &a : A) cin >> a, --a;
        for (int &b : B) cin >> b, --b;
        vector<int> where(N);
        for (int i = 0; i < N; ++i) where[A[i]] = i;
        vector<bool> can_remove(N, true);
        for (int i = 0; i < K; ++i) can_remove[where[B[i]]] = false;
        int ans = 1;
        for (int b : B) {
            int cnt = 0;
            int w = where[b];
            if (w > 0) cnt += can_remove[w-1];
            if (w < N-1) cnt += can_remove[w+1];
            ans = (ans*cnt) % 998244353;
            // cerr << w << ' ' << cnt << " KEK\n";
            can_remove[w] = true;
        }
        cout << ans << '\n';
    }
}