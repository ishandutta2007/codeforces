
#include <bits/stdc++.h>

#define ll long long
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
#define vi vector<int>

using namespace std;

ll k;

vi solve(const vector<ll> &x) {
    vi ans;
    int j = 0;
    int n = sz(x);
    rep(i, 0, n) {
        while(abs(x[i] - x[j]) > k) j++;
        ans.push_back(i == 0 ? i - j + 1 : max(ans.back(), i - j + 1));
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        int n;
        cin >> n >> k;
        vector<ll> x(n);
        rep(i, 0, n) cin >> x[i];
        sort(all(x));
        ll bruh;
        rep(i, 0, n) cin >> bruh;
        vi v1 = solve(x);
        reverse(all(x));
        vi v2 = solve(x);
        reverse(all(x));
        reverse(all(v2));
        int ans = v2[0];
        int j = 0;
        /*
        rep(i, 0, n) {
            cout << v1[i] << ' ';
        }
        cout << endl;
        rep(i, 0, n) {
            cout << v2[i] << ' ';
        }
        cout << endl;*/
        rep(i, 0, n) {
            while(j < n && x[i] == x[j]) j++;
            if(j < n) {
                ans = max(ans, v1[i] + v2[j]);
            }
        }
        cout << ans << '\n';
    }
}