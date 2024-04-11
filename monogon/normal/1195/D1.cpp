
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int MAX_N = 1e5 + 5;
const int M = 998244353;
int n;
string a;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    ll tot = 0;
    for(int i = 0; i < n; i++) {
        cin >> a;
        int len = a.length();
        ll pow10 = 1;
        for(int j = 0; j < 2 * len; j++) {
            tot += (a[len - 1 - j / 2] - '0') * pow10;
            tot %= M;
            pow10 = (pow10 * 10) % M;
        }
    }
    cout << ((tot * n) % M) << endl;
}