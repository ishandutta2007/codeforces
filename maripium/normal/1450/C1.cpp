#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        vector<string> S(N);
        for (int i = 0; i < N; ++i) cin >> S[i];
        vector<int> cnts(3);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (S[i][j] == 'X') cnts[(i+j)%3] ++;
            }
        }
        int z = min_element(cnts.begin(), cnts.end()) - cnts.begin();
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (S[i][j] == 'X' && (i+j)%3 == z) S[i][j] = 'O';
            }
        }
        for (int i = 0; i < N; ++i) cout << S[i] << '\n';
    }
}