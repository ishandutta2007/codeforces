
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

const int A = 1e6 + 5;
bool prime[2 * A];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vi a(n);
    map<int, int> ma;
    rep(i, 0, n) {
        cin >> a[i];
        ma[a[i]]++;
    }
    vector<pii> ve(all(ma));
    fill(prime, prime + 2 * A, true);
    rep(p, 2, 2 * A) {
        if(prime[p]) {
            for(int i = 2 * p; i < 2 * A; i += p) {
                prime[i] = false;
            }
        }
    }
    int k = sz(ve);
    int best = 1;
    vector<pii> ans = {make_pair(ve[0].first, 1)};
    rep(i, 0, k) {
        if(ve[i].first == 1) {
            if(ve[i].second > best) {
                best = ve[i].second;
                ans = {make_pair(ve[i].first, ve[i].second)};
            }
            rep(j, i + 1, k) {
                if(prime[ve[i].first + ve[j].first]) {
                    if(ve[i].second + 1 > best) {
                        best = ve[i].second + 1;
                        ans = {make_pair(ve[i].first, ve[i].second), make_pair(ve[j].first, 1)};
                    }
                }
            }
        }
        rep(j, i + 1, k) {
            if(prime[ve[i].first + ve[j].first] && 2 > best) {
                best = 2;
                ans = {make_pair(ve[i].first, 1), make_pair(ve[j].first, 1)};
            }
        }
    }
    cout << best << '\n';
    for(auto &pa : ans) {
        rep(i, 0, pa.second) {
            cout << pa.first << ' ';
        }
    }
    cout << '\n';
}