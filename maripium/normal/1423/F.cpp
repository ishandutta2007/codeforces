#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, K; cin >> N >> K;
    int sum = 0;
    int64_t tot = 0;
    for (int i = 0; i < K; ++i) {
        int a, b; cin >> a >> b;
        sum = (sum + int64_t(a) * b) % N;
        tot += b;
    }
    if (tot < N) {
        cout << "1\n";
    } else if (tot == N) {
        int expect = (N % 2 == 0 ? N/2 : 0);
        if (sum == expect) cout << "1\n";
        else cout << "-1\n";
    } else cout << "-1\n";
    return 0;
}