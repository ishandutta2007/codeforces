
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
int t, n;
ll k, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> k;
        map<ll, int> ma;
        rep(i, 0, n) {
            cin >> a[i];
            a[i] %= k;
            if(a[i] != 0) {
                ma[k - a[i]]++;
            }
        }
        ll low = 0;
        for(auto &p : ma) {
            ll val;
            int amt;
            tie(val, amt) = p;
            low = max(low, 1 + val + k * (amt - 1));
        }
        cout << low << '\n';
    }
}