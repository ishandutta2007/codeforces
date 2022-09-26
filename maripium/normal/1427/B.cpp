#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int N, K; cin >> N >> K;
        string S; cin >> S;
        K = min<int>(K, count(S.begin(), S.end(), 'L'));
        int l = 0;
        while (l < N && S[l] == 'L') l++;
        if (l == N) {
            cout << max(0, 2*K-1) << '\n';
            continue;
        }
        int r = N-1;
        while (r >= 0 && S[r] == 'L') r--;
        int cur = 0;
        int add = 0;
        vector<int> lens;
        for (int i = l; i <= r; ++i) {
            if (S[i] == 'W') {
                if (cur > 0) lens.emplace_back(cur);
                cur = 0;
            } else {
                cur ++;
            }
        }
        sort(lens.begin(), lens.end());
        for (int v : lens) {
            if (K >=  v) {
                K -= v;
                add += 2*v+1;
            }
        }
        add += 2 * K;
        // cerr << "F " << add << '\n';
        for (int i = 0; i < N; ++i) {
            if (S[i] == 'W') {
                int c = 1;
                if (i && S[i-1] == 'W') c = 2;
                add += c;
            }
        }
        cout << add << '\n';
    }
}