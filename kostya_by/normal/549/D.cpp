#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

const int MAXN = 111;

int n, m;
string a[MAXN];
long long b[MAXN][MAXN];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int answer = 0;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            int should_be = (a[i][j] == 'W' ? 1 : -1);
            if (b[i][j] == should_be) {
                continue;
            }
            answer += 1;
            long long value = should_be - b[i][j];

            for (int k = 0; k <= i; k++) {
                for (int l = 0; l <= j; l++) {
                    b[k][l] += value;
                }
            }
        }
    }

    cout << answer << "\n";
}

int main() {
	int cases; cases = 1;
	for (int i = 0; i < cases; i++) {
        solve();
    }
    return 0;
}