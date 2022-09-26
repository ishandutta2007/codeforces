#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    const int M = int(1e6) + 5;
    vector<bool> np(M);
    vector<int> pref(M);
    for (int i = 2; i < M; ++i) if (!np[i]) {
        pref[i] = pref[i-1]+1;
        for (int j = i+i; j < M; j += i) np[j] = true;
    } else pref[i] = pref[i-1];
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        int _N = floor(sqrt(N));
        cout << 1 + pref[N] - pref[_N] << '\n';
    }
}