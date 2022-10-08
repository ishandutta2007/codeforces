
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1e5;
int n, m;
ll f[N];
const int M = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    if(n < m) swap(n, m);
    f[1] = 1;
    f[2] = 2;
    for(int i = 3; i <= n; i++) {
        f[i] = (f[i - 1] + f[i - 2]) % M;
    }
    cout << (2 * (f[n] + f[m] - 1)) % M << endl;
}