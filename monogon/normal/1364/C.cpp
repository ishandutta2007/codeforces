
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

const int N = 1e5 + 5;
int n, a[N], b[N], inv[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 0, n) {
        cin >> a[i];
        b[i] = inv[i] = i;
    }
    inv[n] = b[n] = n;
    rep(i, 0, n) {
        if(inv[a[i]] <= i) {
            int p = inv[a[i]];
            // swap positions p and i + 1
            inv[a[i]] = i + 1;
            inv[b[i + 1]] = p;
            swap(b[p], b[i + 1]);
        }
    }
    rep(i, 0, n) {
        cout << b[i] << ' ';
    }
    cout << '\n';
}