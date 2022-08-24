#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int n, k;
string s;
int val[26];
int main() {
    srand(123 + 23123123 + 123123 - 123123);
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    if (n == 1 || n == 2) {
        cout << "No";
        return 0;
    }
    cout << "Yes" << '\n';
    cout << 1 << " " << n << '\n';
    cout << n - 1 << " ";
    for (int i = 1; i <= n - 1; i++) cout << i << " ";
    return 0;
}