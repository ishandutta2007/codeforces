
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

// to be in same class, for each integer only care about whether each prime occurs even or odd number of times
// getting rid of prime duplicates, we have a representative for each equivalence class
// just use set and scan in N^2 log N time
// negatives are ok only if everything in segment is negative, so just factorize negative version

const int N = 5005;
int n, a[N], c[N], ans[N], cnt[N];
map<int, int> ma;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    vi ve;
    rep(i, 1, n + 1) {
        cin >> a[i];
        ll x = a[i];
        bool b = (x < 0);
        x = abs(x);
        a[i] = 1;
        for(int k = 2; k * k <= x; k++) {
            if(x % k == 0) {
                bool b = false;
                while(x % k == 0) {
                    b = !b;
                    x /= k;
                }
                if(b) a[i] *= k;
            }
        }
        a[i] *= x;
        if(b) a[i] = -a[i];
        ve.push_back(a[i]);
    }
    sort(all(ve));
    ve.erase(unique(all(ve)), ve.end());
    rep(i, 0, sz(ve)) {
        ma[ve[i]] = i;
    }
    rep(i, 1, n + 1) {
        c[i] = ma[a[i]];
    }

    rep(i, 1, n + 1) {
        fill(cnt, cnt + n + 1, 0);
        int k = 0;
        rep(j, i, n + 1) {
            k += (a[j] != 0 && cnt[c[j]] == 0);
            cnt[c[j]]++;
            ans[max(1, k)]++;
        }
    }
    rep(i, 1, n + 1) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}