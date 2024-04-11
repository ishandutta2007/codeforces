#include <bits/stdc++.h>
using namespace std;
long long n;
int main() {
    srand(time(0));
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    if (n == 0) {
        cout << 0;
        return 0;
    }
    if (n & 1) {
        cout << (n + 1) / 2;
    }
    else cout << n + 1;
    return 0;
}