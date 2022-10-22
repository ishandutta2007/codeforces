#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        if (n <= 2) {
            for (int i = 0; i < n; i++)
                cout << a[i] << "\n";
            continue;
        }
        vector<int> cnt(3);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] == 'X')
                    cnt[(i + j) % 3]++;
            }
        }
        int d = min_element(cnt.begin(), cnt.end()) - cnt.begin();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] == 'X' && (i + j) % 3 == d)
                    a[i][j] = 'O';
            }
        }
        for (int i = 0; i < n; i++)
            cout << a[i] << "\n";
    }

    return 0;
}