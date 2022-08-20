#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    long long n;
    cin >> n;

    if (n == 0) {
        cout << 1 << '\n';
        return 0;
    }

    int L = sqrt(n * n / 2);

    pair<long long, long long> near = {L + 1, L};

    int ans = (L * 2 + 1) * 4;

    if (near.first * near.first + near.second * near.second > n * n)
        ans -= 4;

    cout << ans << '\n';

    return 0;
}