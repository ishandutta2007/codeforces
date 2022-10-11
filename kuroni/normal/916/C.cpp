#include <bits/stdc++.h>
using namespace std;
    
const int MX = 1E6 + 5;
    
int n, m;
bool pr[MX];
    
void print_edge(int u, int v, int w) {
    --m;
    cout << u << " " << v << " " << w << '\n';
}
    
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 2; i < MX; i++) {
        if (!pr[i]) {
            for (int j = 2 * i; j < MX; j += i) {
                pr[j] = true;
            }
        }
    }
    int cur;
    for (int i = n; i < MX; i++) {
        if (!pr[i]) {
            cur = i;
        }
    }
    cout << (m == 1 ? cur : 2) << " " << cur << '\n';
    for (int i = n; i >= 3; i--) {
        print_edge(1, i, 2);
        cur -= 2;
    }
    print_edge(1, 2, cur);
    for (int i = 2; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (m == 0) {
                return 0;
            }
            print_edge(i, j, cur + 1);
        }
    }
}