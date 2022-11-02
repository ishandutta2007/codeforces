#include <cstdio>
#include <iostream>

using namespace std;

typedef long long ll;

int x1, y1, x2, y2, n, ans;

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> x1 >> y1 >> x2 >> y2;
    cin >> n;
    for (int i=0; i<n; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        ll v1 = a*x1+b*y1+c;
        ll v2 = a*x2+b*y2+c;
        if (v1>0 != v2>0) ans++;
    }
    cout << ans << endl;
}