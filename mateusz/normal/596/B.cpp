#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

int n;
int b[N];

int main() {

    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    long long ans = 0;
    long long add = 0;

    for (int i = 1; i <= n; i++) {
        ans += abs(b[i] - add);
        add += b[i] - add;
    }

    cout << ans << "\n";

    return 0;
}