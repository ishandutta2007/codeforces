#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int da, db;
    cin >> da >> db;
    if (da == db) {
        cout << da << "1 " << db << 2;
        return 0;
    }
    if (db == da + 1) {
        cout << da << ' ' << db;
        return 0;
    }
    if (da == 9 && db == 1) {
        cout << "9 10";
        return 0;
    }
    cout << -1;
    return 0;
}