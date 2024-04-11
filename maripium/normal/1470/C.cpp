#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, K; cin >> N >> K;
    auto query = [&](int q) {
        cout << "? " << q+1 << '\n';
        cout << flush;
        int ans; cin >> ans;
        return ans;
    };
    int S = sqrt(N / 2);
    for (int i = 0; i < S; ++i) query(0);
    int i = 0;
    while (true) {
        int v = query(i);
        if (v > K) {
            int p = i;
            while (query(p) != K) p = (p + N - 1) % N;
            cout << "! " << p+1 << '\n';
            cout << flush;
            return 0;
        } else if (v < K) {
            int p = i;
            while (query(p) != K) p = (p + 1) % N;
            cout << "! " << p+1 << '\n';
            cout << flush;
            return 0;
        } else {
            i = (i + 2 * S + 1) % N;
        }
    }
}