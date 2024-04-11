#include <bits/stdc++.h>

using namespace std;
int hh, mm;
int h, d, n;
string h1, m1;
long double c;
int main() {
    //freopen("input.txt", "r", stdin);
    //calc();
    ios_base::sync_with_stdio(false);
    cin >> h1 >> m1 >> h >> d >> c >> n;
    hh = (int)(h1[0] - '0') * 10 + (int)(h1[1] - '0');
    mm = (m1[0] - '0') * 10 + (m1[1] - '0');
    //cout << hh << " " << mm << endl;
    if (hh >= 20) c = 0.8 * c;
    long double ans = (((h + n - 1) / n) * c);
    if (hh < 20) {
        long long to = h + d * ((20 - hh - 1) * 60 + (60 - mm));
        c = 0.8 * c;
        ans = min(ans, ((to + n - 1) / n) * c);
    }
    cout << fixed << setprecision(10) << ans;
    return 0;
}