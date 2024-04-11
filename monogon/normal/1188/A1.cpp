
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int MAX_N = 1e5 + 5;
int n, u, v;
int deg[MAX_N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        u--; v--;
        deg[u]++;
        deg[v]++;
    }
    for(int i = 0; i < n; i++) {
        if(deg[i] == 2) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}