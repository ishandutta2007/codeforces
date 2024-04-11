
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

const int N = 5e4 + 5;
int n, b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    vector<pii> ve;
    rep(i, 0, n) {
        cin >> b[i];
    }
    rep(i, 0, n) {
        ve.emplace_back(b[i] + b[(i + 1) % n], i);
    }
    sort(all(ve));
    rep(i, 0, n) {
        b[ve[i].se] = i;
    }
    rep(i, 0, n) {
        cout << b[i] << ' ';
    }
    cout << '\n';
}