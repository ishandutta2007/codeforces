
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

const int N = 2e5 + 5;
int n, k, a[N], cnt[N];

int check(int amt) {
    int ans = 0;
    rep(i, 0, N) {
        ans += cnt[i] / amt;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    rep(i, 0, n) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    int l = 0, r = n + 1;
    while(l < r) {
        int m = (l + r + 1) / 2;
        if(check(m) >= k) {
            l = m;
        }else {
            r = m - 1;
        }
    }
    int ans = 0;
    rep(i, 0, N) {
        while(ans < k && cnt[i] >= l) {
            cnt[i] -= l;
            cout << i << ' ';
            ans++;
        }
    }
    cout << '\n';
}