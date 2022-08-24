#include <bits/stdc++.h>
using namespace std;
long long n, k;
map < long long, int > p;
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    if (k > 1000) {
        cout << "No";
        return 0;
    }
    for (int i = 1; i <= k; i++) {
        if (p[n % i] != 0) {
            cout << "No";
            return 0;
        }
        p[n % i] = 1;
    }
    cout << "Yes";
    return 0;
}