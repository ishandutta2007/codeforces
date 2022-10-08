
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
int n, a[N], cnt[N], mask[N], match[N];
int odd, neg;
int dif[4] = {0, 1, -1, 1};

void upd(int idx, int val) {
    neg -= (cnt[idx] < 0);
    odd -= (cnt[idx] % 2 != 0);
    cnt[idx] = val;
    neg += (cnt[idx] < 0);
    odd += (cnt[idx] % 2 != 0);
}
void updmask(int idx, int newmask) {
    upd(a[idx], cnt[a[idx]] + dif[newmask] - dif[mask[idx]]);
    mask[idx] = newmask;
}

bool intervalmismatch(int l, int r) {
    if(r < l) return 0;
    return (r - l + 1) - match[r] + (l == 0 ? 0 : match[l - 1]) > 0;
}

bool mismatches(int i, int j) {
    j--;
    int i2 = n - j - 1;
    int j2 = n - i - 1;
    return intervalmismatch(0, min(i, i2) - 1) || intervalmismatch(min(j, j2) + 1, max(i, i2) - 1)
        || intervalmismatch(max(j, j2) + 1, n - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 0, n) {
        cin >> a[i];
    }
    rep(i, 0, n) {
        match[i] = (a[i] == a[n - i - 1]);
    }
    rep(i, 1, n) match[i] += match[i - 1];
    ll ans = 0;
    int j = 0;
    rep(i, 0, n) {
        while(j <= i || (j < n && (neg > 0 || odd > 1 || mismatches(i, j)))) {
            updmask(j, mask[j] | 1);
            updmask(n - j - 1, mask[n - j - 1] | 2);
            j++;
        }
        if(neg == 0 && odd <= 1 && !mismatches(i, j)) {
            ans += n - j + 1;
        }
        updmask(i, mask[i] & ~1);
        updmask(n - i - 1, mask[n - i - 1] & ~2);
    }
    cout << ans << '\n';
}