
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int n, x, o;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x;
        o += x % 2;
    }
    cout << min(o, n - o) << endl;
}