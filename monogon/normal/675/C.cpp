
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

// under some rotation, n - (num 0's in prefix sum)
// histogram of prefix sum.
// number of occurrences of pref[i] for each i

const int N = 1e5 + 5;
int n;
ll a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    map<ll, int> ma;
    rep(i, 1, n + 1) {
        cin >> a[i];
        a[i] += a[i - 1];
        ma[a[i]]++;
    }
    int mx = 0;
    rep(i, 1, n + 1) {
        mx = max(mx, ma[a[i]]);
    }
    cout << n - mx << '\n';
}