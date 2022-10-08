
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
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

int n, a, b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    vector<pii> ve;
    rep(i, 0, n) {
        cin >> a >> b;
        ve.emplace_back(a, b);
    }
    sort(all(ve));
    rep(i, 0, n - 1) {
        if(ve[i].fi < ve[i + 1].fi && ve[i].se > ve[i + 1].se) {
            cout << "Happy Alex\n";
            return 0;
        }
    }
    cout << "Poor Alex\n";
}