#include <bits/stdc++.h>
using namespace std;;
int a[(int)1e5 + 10];
int n;
int b[(int)1e5 + 10];
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("log.in", "r", stdin);
    //freopen("log.out", "w", stdout);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    int mn = (int)1e5 + 10;
    int mx = -1;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        b[x]++;
    }
    for (int i = 1; i <= (int)1e5 + 5; i++) {
        if ((b[i] % 2) == 1) {
            cout << "Conan";
            return 0;
        }
    }
    cout << "Agasa";
    return 0;
}