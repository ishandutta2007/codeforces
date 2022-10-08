
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

const int N = 505;
int t, n;
ll a[N], b[N];
map<ll, vi> ma;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        ma.clear();
        rep(i, 0, n) {
            cin >> a[i];
        }
        rep(i, 0, n) {
            cin >> b[i];
            ma[b[i]].push_back(a[i]);
        }
        if(sz(ma) > 1) {
            cout << "Yes\n";
        }else {
            bool flag = true;
            for(auto &p : ma) {
                vi v = p.second;
                int m = sz(v);
                rep(i, 0, m - 1) {
                    if(v[i] > v[i + 1]) flag = false;
                }
            }
            cout << (flag ? "Yes" : "No") << '\n';
        }
    }
}