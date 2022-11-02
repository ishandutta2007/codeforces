#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

typedef long long ll;

const int MAXN = 1000100;

int n, x, y, cnt;
pair<ll, int> ar[2*MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> x >> y;
    int g = gcd(x, y);
    x /= g, y /= g;

    for (int i=1; i<=x; i++) ar[cnt++] = make_pair(ll(i)*y, 0);
    for (int i=1; i<=y; i++) ar[cnt++] = make_pair(ll(i)*x, 1);

    sort(ar, ar+cnt);

    for (int i=0; i<n; i++) {
        int a; cin >> a;
        a %= cnt;
        if (a == 0 || a == cnt-1) cout << "Both\n";
        else if (!ar[a-1].second) cout << "Vanya\n";
        else cout << "Vova\n";
    }
}