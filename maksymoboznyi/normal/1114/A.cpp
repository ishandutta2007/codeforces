#include <bits/stdc++.h>
#define pb push_back
#define ll long long

using namespace std;



signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long x, y ,z, a, b, c;
    cin >> x >> y >> z >> a >> b >> c;
    if (a < x) {
        cout << "NO";
        return 0;
    }
    a -= x;
    if (a + b < y) {
        cout << "NO";
        return 0;
    }
    if (a + b + c - y < z) {
        cout << "NO";
        return 0;
    }
    cout << "YES";
    return 0;
}