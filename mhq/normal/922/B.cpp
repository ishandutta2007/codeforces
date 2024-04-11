#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            int x = i ^ j;
            if (x < j) continue;
            if (x >= i + j) continue;
            if (x > n) continue;
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}