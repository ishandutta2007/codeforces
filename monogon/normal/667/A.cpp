
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

using ftype = long double;
const ftype pi = acosl(-1);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ftype d, h, v, e;
    cin >> d >> h >> v >> e;
    ftype drink = v / (pi * (d / 2) * (d / 2));
    ftype rate = drink - e;
    cout << fixed << setprecision(8);
    if(rate > 1e-9) {
        cout << "YES\n" << h / rate << '\n';
    }else {
        cout << "NO\n";
    }
}