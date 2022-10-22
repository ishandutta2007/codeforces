#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <functional>
#include <cstring>
#include <cassert>
#include <numeric>

//#define FAST_ALLOCATOR_MEMORY 2e8
//#include "optimization.h"

using namespace std;

typedef long long ll;
typedef long double ld;
const ll md = (ll)1e9 + 7, inf = (ll)1e18;

int main() {
    iostream::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

#ifdef LOCAL
    freopen("C:\\Users\\aytel\\CLionProjects\\common\\input.txt", "r", stdin);
    freopen("C:\\Users\\aytel\\CLionProjects\\common\\output.txt", "w", stdout);
#endif

    const int MG = 750, S = 5000 + 1;
    int d, s;
    cin >> d >> s;

    vector<int> pw(MG);
    pw[0] = 1;
    for (int i = 1; i < MG; i++)
        pw[i] = (pw[i - 1] * 10) % d;

    vector<vector<bitset<S>>> r(MG, vector<bitset<S>>(d));
    r[0][0][0] = 1;
    int st = -1;
    for (int i = 0; i + 1 < MG; i++) {
        for (int j = 0; j < d; j++) {
            if (!r[i][j].count())
                continue;
            for (int a = 0; a < 10; a++)
                r[i + 1][(10 * j + a) % d] |= r[i][j] << a;
        }
        if (r[i + 1][0][s]) {
            st = i + 1;
            break;
        }
    }

    if (st == -1) {
        cout << "-1\n";
        return 0;
    }

    string ans = "";
    int m = 0;
    for (int i = st - 1; i >= 0; i--) {
        for (int j = 0; j < min(10, s + 1); j++) {
            if (i == st - 1 && !j)
                continue;
            int ms = (j * pw[i]) % d;
            if (r[i][(m - ms + d) % d][s - j]) {
                ans += char(j + '0');
                m = (m - ms + d) % d;
                s -= j;
                break;
            }
        }
    }

    //reverse(ans.begin(), ans.end());
    cout << ans << '\n';

    return 0;
}