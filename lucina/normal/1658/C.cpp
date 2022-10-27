#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5 + 10;
int n;
int a[nax];

bool solve() {
    cin >> n;
    int g = -1;
    for (int i = 1 ; i <= n ; ++ i)
        cin >> a[i];
    for (int i = 1 ; i <= n ; ++ i) {
        a[n + i] = a[i];
        if (a[i] == 1) {
            if (g != -1) return false;
            g = i;
        } 
    }
    if (g == -1) return false;
    for (int i = 1 ; i < n ; ++ i) {
        int x = a[g + i - 1];
        int y = a[g + i];
        if (y > x && y != x + 1) return false;
    }
    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;
    
    for (cin >> T ; T -- ;) {
        cout << (solve() ? "YES" : "NO") << '\n';
    }
}