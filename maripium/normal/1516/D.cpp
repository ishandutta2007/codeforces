#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    const int MX = 100100;

    vector<int> pr(MX);
    for (int i = 2; i < MX; ++i) if (!pr[i]) {
        for (int j = i; j < MX; j += i) {
            pr[j] = i;
        }
    }

    int N, Q; cin >> N >> Q;
    vector<int> A(N); for (int &a : A) cin >> a;
    vector<int> last(MX, N);
    int nxt = N;

    vector<array<int, 17>> jump(N);
    for (int i = N-1; i >= 0; --i) {
        while (A[i] > 1) {
            int p = pr[A[i]];
            nxt = min(nxt, last[p]);
            last[p] = i;
            while (A[i] % p == 0) A[i] /= p;
        }
        cerr << nxt << '\n';
        jump[i][0] = nxt;
    }

    for (int j = 1; j < 17; ++j) {
        for (int i = 0; i < N; ++i) {
            if (jump[i][j-1] == N) {
                jump[i][j] = N;
            } else {
                jump[i][j] = jump[jump[i][j-1]][j-1];
            }
        }
    }

    while (Q--) {
        int l, r; cin >> l >> r; --l, --r;
        int ans = 0;
        for (int i = 16; i >= 0; --i) if (jump[l][i] <= r) {
            ans |= 1 << i;
            l = jump[l][i];
        }
        cout << ans+1 << '\n';
    }
}