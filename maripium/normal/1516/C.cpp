#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int N; cin >> N;

    bitset<200200> bs;
    bs.set(0);

    vector<int> A(N);
    int tot = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        bs |= bs << A[i];
        tot += A[i];
    }

    if (tot % 2 == 0 && bs[tot / 2]) {
        while (true) {
            for (int i = 0; i < N; ++i) {
                if (A[i] % 2) {
                    cout << "1\n" << i+1 << '\n';
                    return 0;
                }
            }
            for (int i = 0; i < N; ++i) A[i] /= 2;
        }
    }

    cout << "0\n";
    return 0;
}