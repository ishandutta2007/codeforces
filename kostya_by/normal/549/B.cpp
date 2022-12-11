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

int n;
string a[MAXN];
int d[MAXN];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }

    set<int> answer;
    while (true) {
        vector<int> zeroes;
        for (int i = 0; i < n; i++) {
            if (d[i] == 0) {
                zeroes.push_back(i);
            }
        }

        if (zeroes.size() == 0) {
            break;
        }

        for (int v : zeroes) {
            for (int i = 0; i < n; i++) {
                if (a[v][i] == '1') {
                    d[i] -= 1;
                }
            }
            answer.insert(v);
        }
    }

    cout << answer.size() << "\n";
    for (int v : answer) {
        cout << v + 1 << " ";
    }

    cout << "\n";
}

int main() {
	int cases; cases = 1;
	for (int i = 0; i < cases; i++) {
        solve();
    }
    return 0;
}