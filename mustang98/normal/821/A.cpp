#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 55, inf = 1000111222;

int m[max_n][max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> m[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int cur = m[i][j];
            if (cur == 1) continue;
            bool found = false;
            for (int i1 = 0; i1 < n; ++i1) {
                for (int j1 = 0; j1 < n; ++j1) {
                    if (m[i1][j] + m[i][j1] == cur) {
                        found = true;
                    }
                }
            }
            if (!found) {
                cout << "No";
                return 0;
            }
        }
    }
    cout << "Yes";
    return 0;
}