#include <bits/stdc++.h>
using namespace std;
long long n;
int k;
int main() {
    //freopen("input.txt", "r", stdin);
    long long opt = (long long)1e18 + 1;
    int ind = -1;
    long long need = -1;
    cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        long long x;
        cin >> x;
        if (opt > n % x) {
            opt = n % x;
            ind = i;
            need = (n / x);
        }
    }
    cout << ind << " " << need;
    return 0;
}