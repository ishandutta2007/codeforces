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

const int MAXN = 1010;
const int MAXT = 110;

int n, T;
int t[MAXN], q[MAXN];
vector<int> tasks[MAXT];

int solve_height(int height) {
    priority_queue<int> p;

    for (int k = height; k <= T; k++) {
        for (int j = 0; j < tasks[k].size(); j++) {
            p.push(tasks[k][j] );
        }
    }

    for (int i = height; i > 0; i--) {
        if (p.size() < 2) {
            return 0;
        } 

        priority_queue<int> new_p;
        while (p.size() >= 2) {
            int a = p.top(); p.pop();
            int b = p.top(); p.pop();
            new_p.push(a + b);
        }
        while (p.size() ) {
            int a = p.top(); p.pop();
            new_p.push(a);
        } 

        p = new_p;

        for (int j = 0; j < tasks[i - 1].size(); j++) {
            p.push(tasks[i - 1][j] );
        }
    }

    return p.top();
}

void solve() {
    cin >> n >> T;
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> q[i];
        t[i] = T - t[i];
        tasks[t[i] ].push_back(q[i] );
        // cerr << t[i] << " " << q[i] << "\n"; 
    }
    int answer = 0;
    for (int height = 0; height <= T; height++) {
        // cerr << height << " -> " << solve_height(height) << "\n";
        answer = max(answer, solve_height(height) );
    }
    cout << answer << "\n";
}

int main() {
    int cases; cases = 1;
    for (int i = 1; i <= cases; i++) {
        solve();
    }
    return 0;
}