#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

const int MAXN = 105;

int n;
set<int> st[MAXN];
bool bad[MAXN];

bool in(int a, int b) {
    for (typeof(st[a].begin()) it = st[a].begin(); it != st[a].end(); it++) {
        if (!st[b].count(*it)) return 0;
    }
    return 1;
}

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    cin >> n;
    for (int i=0; i<n; i++) {
        int m; cin >> m;
        for (int j=0; j<m; j++) {
            int a; cin >> a; st[i].insert(a);
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (i == j) continue;
            if (in(i, j)) bad[j] = 1;
        }
    }
    for (int i=0; i<n; i++) {
        if (bad[i]) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}