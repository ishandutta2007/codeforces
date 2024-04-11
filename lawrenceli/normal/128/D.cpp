#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <ios>

using namespace std;

const int maxn = 100100;

int n, a[maxn], freq[maxn];

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n;
    int mi = 1e9, ma = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mi = min(mi, a[i]);
        ma = max(ma, a[i]);
    }

    for (int i = 0; i < n; i++) {
        if (a[i] > mi + n) {
            cout << "NO\n";
            return 0;
        }

        freq[a[i] - mi]++;
    }

    int m = ma - mi;
    freq[0]--, freq[m]--;
    for (int i = 1; i < m; i++) freq[i] -= 2;
    
    for (int i = 0; i <= m; i++)
        if (freq[i] < 0) {
            cout << "NO\n";
            return 0;
        }

    for (int i = 0; i < m; i++) {
        int x = min(freq[i], freq[i + 1]);
        freq[i] -= x, freq[i + 1] -= x;
    }

    for (int i = 0; i <= m; i++)
        if (freq[i]) {
            cout << "NO\n";
            return 0;
        }

    cout << "YES\n";
    return 0;
}