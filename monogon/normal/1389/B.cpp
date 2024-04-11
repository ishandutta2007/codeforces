
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

const int N = 1e5 + 5;
ll a[N], dp[N][6];
map<tuple<int, int, int, bool>, ll> ma;

ll solve(int i, int k, int z, bool le) {
    auto tup = make_tuple(i, k, z, le);
    if(ma.count(tup)) return ma[tup];
    if(k == 0) return a[i];
    if(z == 0 || !le) return ma[tup] = a[i] + solve(i + 1, k - 1, z, true);
    else return ma[tup] = max(a[i] + solve(i + 1, k - 1, z, true), a[i] + solve(i - 1, k - 1, z - 1, false));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        int n, k, z;
        cin >> n >> k >> z;
        ma.clear();
        rep(i, 0, n) {
            cin >> a[i];
        }
        cout << solve(0, k, z, true) << '\n';
    }
}