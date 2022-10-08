
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) {
        cin >> a[i];
    }
    int j = n - 1;
    ll s1 = 0, s2 = 0;
    ll ans = 0;
    rep(i, 0, n) {
        s1 += a[i];
        while(j >= 0 && s2 < s1) {
            s2 += a[j];
            j--;
        }
        if(s1 == s2 && i <= j) ans = max(ans, s1);
    }
    cout << ans << '\n';
}