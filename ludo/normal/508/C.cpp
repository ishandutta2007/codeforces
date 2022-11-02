#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <utility>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int m, t, r;

int nlit = 0;
bool lit[1000] = {};
int burning[1000] = {};

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL

    cin >> m >> t >> r;

    if (t < r) {
        cout << "-1" << endl;
        return 0;
    }

    for (int i = 0; i < m; i++) {
        int w;
        cin >> w;

        if (i == 0) {
            // lit at moments, (w - 1, ..., w - r)
            nlit += r;
            for (int j = 1; w - j >= 0 && j <= r; j++) {
                lit[w - j] = true;
            }
            // burning[w + t] = 1
            // burning[w + t - 1] = 2
            // burning[w + t - 2] = 3
            // ...
            // burning[w + t - (r - 1)] = r

            for (int j = 1; j <= r; j++) {
                burning[w + t - j] = j;
            }
            for (int j = 0; j < t - r; j++) {
                burning[w + j] = r;
            }
        } else {
            while (burning[w] < r) {
                // lit some candles at the latest moment possible
                int littime = w - 1;
                while (littime >= 0 && lit[littime]) {
                    littime--;
                }
                if (littime < 0) {
                    cout << "-1" << endl;
                    return 0;
                }
                nlit++;
                lit[littime] = true;
                for (int j = 1; j <= t; j++) {
                    burning[littime + j]++;
                }
            }
        }
//        for (int i = 0; i < 20; i++) {
//            cerr << i << ":\t" << lit[i] << "\t" << burning[i] << endl;
//        }
//        cerr << endl;
    }
    cout << nlit << endl;
    return 0;
}