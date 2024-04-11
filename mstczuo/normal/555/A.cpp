# include <iostream>
# include <cstdio>
# include <cstring>

using namespace std;

int a[100010];

int main() {
    int n, k, m, ans = 0;
    cin >> n >> k;
    ans = n - 1;
    for(int i = 0; i < k; ++i) {
        cin >> m;
        ans += m - 1;
        for(int j = 0; j < m; ++j) {
            cin >> a[j];
        }
        if(a[0] != 1) continue;
        for(int j = 1; j < m; ++j) {
            if(a[j] != j +1) break;
            ans -= 2;
        }
    }
    cout << ans << endl;
    return 0;
}