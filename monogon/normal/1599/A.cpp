
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
    string s;
    cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    cin >> s;
    int cnt = 0;
    rep(i, 1, n) cnt += (s[i] != s[i - 1]);
    sort(all(a));
    vector<ll> w(n);
    int j = 0, k = 0;
    rep(i, 0, n) {
        if(i == 0 || (s[i] != s[i - 1])) {
            w[i] = a[n - cnt - 1 + j];
            j++;
        }else {
            k++;
            w[i] = a[n - cnt - 1 - k];
        }
    }
    ll sum = 0;
    rep(i, 0, n) {
        char c = 'L';
        if(i == 0 || (s[i] != s[i - 1])) c = s[i];
        else {
            if(w[i] < abs(sum)) c = s[i] ^ 'L' ^ 'R';
            else c = s[i];
        }
        cout << w[i] << ' ' << c << '\n';
        if(c == 'L') sum -= w[i];
        else sum += w[i];
    }
}