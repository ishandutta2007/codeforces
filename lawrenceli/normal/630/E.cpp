#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

typedef unsigned long long ll;

int main() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if ((x1 + y1) % 2) x1++, x2++;
    int no, ne;
    if (y1 % 2) no = (y2 - y1) / 2 + 1, ne = y2 - y1 + 1 - no;
    else ne = (y2 - y1) / 2 + 1, no = y2 - y1 + 1 - ne;
    ll ans;
    int a = (x2 - x1) / 2 + 1, b = x2 - x1 + 1 - a;
    if (x1 % 2) ans = ll(no) * a + ll(ne) * b;
    else ans = ll(no) * b + ll(ne) * a;
    cout << ans << '\n';
}