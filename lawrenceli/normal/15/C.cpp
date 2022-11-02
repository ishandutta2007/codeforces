#include <cstdio>
#include <iostream>
#include <ios>

using namespace std;

typedef long long ll;

int n;

ll sumxor(ll x) {
    if (x % 4 == 0) return x;
    else if (x % 4 == 1) return 1;
    else if (x % 4 == 2) return x+1;
    else return 0;
}

int main() {
    ios :: sync_with_stdio(false);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    ll num = 0;

    cin >> n;
    for (int i=0; i<n; i++) {
        ll x, m; cin >> x >> m;
        num ^= sumxor(x+m-1) ^ sumxor(x-1);
    }

    if (num) cout << "tolik\n";
    else cout << "bolik\n";

    return 0;
}