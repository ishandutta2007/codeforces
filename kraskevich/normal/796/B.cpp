#include <bits/stdc++.h>    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair
    
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    vector<bool> is_hole(n + 1, false);
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        is_hole[x] = true;
    }
    int x = 1;
    for (int i = 0; i < k; i++) {
        if (is_hole[x]) {
            cout << x << endl;
            return 0;
        }
        int a, b;
        cin >> a >> b;
        if (x == a) {
            x = b;
            continue;
        }
        if (x == b)
            x = a;
    }
    cout << x << endl;
}