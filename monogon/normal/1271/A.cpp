
#include <bits/stdc++.h>

#define ll long long
using namespace std;

ll a, b, c, d, e, f;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> a >> b >> c >> d >> e >> f;
    cout << max(min(a, d) * e + min(d - min(a, d), min(b, c)) * f,
                min(d, min(b, c)) * f + min(d - min(d, min(b, c)), a) * e) << endl;
}