#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1005;

int n, m;
bool no[MAXN];

int main() {
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        no[a]=1; no[b]=1;
    }
    for (int i=0; i<n; i++) {
        if (!no[i]) {
            cout << n-1 << endl;
            for (int j=0; j<n; j++) {
                if (i==j) continue;
                cout << i+1 << ' ' << j+1 << endl;
            }
            return 0;
        }
    }
}