
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

// x | lcm(a, b) and x | lcm(b, c)
// x has a certain factor if it appears in every pair
// so, gcd of all numbers
// but then if a factor appears in all but one number, we should still add it to x
// for each number 1 <= d <= 200000, check that all but at most one number is a multiple of it
// lcm of all such d is answer

const int N = 1e5 + 5, A = 2e5 + 5;
int n, a[N], cnt[A];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 0, n) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    ll ans = 1;
    rep(d, 2, A) {
        int amt = 0;
        for(int k = d; k < A; k += d) {
            amt += cnt[k];
        }
        if(amt >= n - 1) {
            ans = (ans * d) / gcd(ans, d);
        }
    }
    cout << ans << '\n';
}