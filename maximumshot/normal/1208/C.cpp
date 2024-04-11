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

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> a(n, vector<int>(n));
    
    int x = 0;
    for (int i = 0;i < n; i += 4) {
        for (int j = 0; j < n; j += 4) {
            for (int qi = 0; qi < 4; qi++) { 
                for (int qj = 0; qj < 4; qj++) {
                    a[i + qi][j + qj] = x++;
                }
            }
        }
    }
    
    for (auto i : a) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << "\n";
    }

    return 0;
}