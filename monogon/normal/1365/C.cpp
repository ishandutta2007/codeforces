
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

const int N = 2e5 + 5;
int n, a[N], b[N], inva[N];
map<int, int> ma;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 0, n) {
        cin >> a[i];
        inva[a[i]] = i;
    }
    rep(i, 0, n) {
        cin >> b[i];
        int k = ((i - inva[b[i]]) % n + n) % n;
        ma[k]++;
    }
    int mx = 0;
    for(auto &p : ma) {
        mx = max(mx, p.se);
    }
    cout << mx << '\n';
}