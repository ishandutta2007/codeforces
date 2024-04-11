
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;

// mice with only one closest cheese are already determined
// consider mice at same distance to two cheeses
// scan and assign them greedily?
// make all undecided mice go left unless right is better
// it seems that Y coordinate plays no role

const int N = 1e5 + 5;
int n, m;
ll Y0, Y1, a[N], b[N];
vi ve[N], mice;
int choice[N], num[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> Y0 >> Y1;
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, m) cin >> b[i];
    int cheese = 0;
    rep(i, 0, n) {
        while(cheese < m && b[cheese] < a[i]) cheese++;
        if(cheese < m && cheese > 0 && b[cheese] - a[i] == a[i] - b[cheese - 1]) {
            // we get to choose
            mice.push_back(i);
            choice[i] = cheese;
        }else if(cheese == m || (cheese < m && cheese > 0 && b[cheese] - a[i] > a[i] - b[cheese - 1])) {
            // move left
            ve[cheese - 1].push_back(a[i] - b[cheese - 1]);
        }else {
            // move right
            ve[cheese].push_back(b[cheese] - a[i]);
        }
    }
    rep(i, 0, m) {
        sort(all(ve[i]));
        num[i] = !ve[i].empty();
        if(sz(ve[i]) >= 2 && ve[i][0] == ve[i][1]) num[i] = 2;
    }
    auto delta = [&](int cheese, int i) {
        if(ve[cheese].empty()) return 1;
        ll dist = abs(b[cheese] - a[i]);
        if(dist < ve[cheese][0]) return 1 - num[cheese];
        else if(dist == ve[cheese][0]) return 1 + num[cheese];
        else return 0;
    };
    auto upd = [&](int cheese, int i) {
        ll dist = abs(b[cheese] - a[i]);
        ve[cheese].push_back(dist);
        sort(all(ve[cheese]));
        num[cheese] = 1;
        if(sz(ve[cheese]) >= 2 && ve[cheese][0] == ve[cheese][1]) num[cheese] = 2;
    };
    for(int i : mice) {
        int d1 = delta(choice[i], i);
        int d2 = delta(choice[i] - 1, i);
        if(d1 > d2) {
            upd(choice[i], i);
        }else {
            upd(choice[i] - 1, i);
        }
    }
    int ans = n;
    rep(i, 0, m) ans -= num[i];
    cout << ans << endl;
}