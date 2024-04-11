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

const int MAXN = 55;

int n, m;
string a[MAXN];

void solve() {
	cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int answer = 0;
    for (int i = 0; i + 1 < n; i++) {
        for (int j = 0; j + 1 < m; j++) {
            vector<char> c;
            c.push_back(a[i][j] );
            c.push_back(a[i + 1][j] );
            c.push_back(a[i][j + 1] );
            c.push_back(a[i + 1][j + 1] );
            sort(c.begin(), c.end() );
            if (c[0] == 'a' && c[1] == 'c' && c[2] == 'e' && c[3] == 'f') {
                answer += 1;
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