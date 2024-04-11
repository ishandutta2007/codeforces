#include <bits/stdc++.h>

using namespace std;

int n, a, b;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> a >> b;
    for (int i = 0; i * a <= n; ++i) if ((n - i * a) % b == 0) {
        int j = (n - i * a) / b;
        for (int s = 1; s <= i * a; ++s) if (s % a == 0) cout << s + 1 - a << ' '; else cout << s + 1 << ' ';
        for (int s = i * a + 1; s <= n; ++s) if ((s - i * a) % b == 0) cout << s + 1 - b << ' '; else cout << s + 1 << ' ';
        cout << endl;
        return 0;
    }
    cout << -1 << endl;
    return 0;
}