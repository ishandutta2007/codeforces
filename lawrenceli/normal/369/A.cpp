#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, k, ans;

int main() {
    cin >> n >> m >> k;
    for (int i=0; i<n; i++) {
        int a; cin >> a;
        if (a == 1) {
            if (m == 0) ans++;
            else m--;
        } else {
            if (k == 0) {
                if (m == 0) ans++;
                else m--;
            } else k--;
        }
    }
    cout << ans << endl;
}