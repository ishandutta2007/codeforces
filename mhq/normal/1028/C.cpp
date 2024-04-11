#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
set < pair < int, int > > for_mn_x, for_mn_y, for_mx_x, for_mx_y;
int n;
const int maxN = 2 * (int)1e5;
int x[maxN][2], y[maxN][2];
int main() {
    srand(time(0));
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x[i][0] = x1;
        y[i][0] = y1;
        x[i][1] = x2;
        y[i][1] = y2;
        for_mn_x.insert(make_pair(x[i][0], i));
        for_mx_x.insert(make_pair(x[i][1], i));
        for_mn_y.insert(make_pair(y[i][0], i));
        for_mx_y.insert(make_pair(y[i][1], i));
    }
    for (int i = 1; i <= n; i++) {
        for_mn_x.erase(make_pair(x[i][0], i));
        for_mx_x.erase(make_pair(x[i][1], i));
        for_mn_y.erase(make_pair(y[i][0], i));
        for_mx_y.erase(make_pair(y[i][1], i));
        int mn_x = (*(--for_mn_x.end())).first;
        int mn_y = (*(--for_mn_y.end())).first;
        int mx_x = (*(for_mx_x).begin()).first;
        int mx_y = (*(for_mx_y).begin()).first;
        if (mn_x <= mx_x && mn_y <= mx_y) {
            cout << mn_x << " " << mn_y;
            return 0;
        }
        for_mn_x.insert(make_pair(x[i][0], i));
        for_mx_x.insert(make_pair(x[i][1], i));
        for_mn_y.insert(make_pair(y[i][0], i));
        for_mx_y.insert(make_pair(y[i][1], i));
    }
    return 0;
}