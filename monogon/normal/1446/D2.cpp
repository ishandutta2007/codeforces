
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

const int K = 450;

struct stupidqueue {
    vi a, inv;
    int val = 0;
    stupidqueue(int n) {
        a.assign(n + 1, 0);
        inv.assign(n + 1, 0);
        val = 0;
    }
    void push(int x) {
        inv[a[x]]--;
        a[x]++;
        inv[a[x]]++;
        if(a[x] > val) val = a[x];
    }
    void pop(int x) {
        inv[a[x]]--;
        a[x]--;
        inv[a[x]]++;
        if(inv[val] == 0) val--;
    }
    bool ugh() {
        return inv[val] >= 2;
    }
    int mode() {
        return val;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vi a(n + 1, 0);
    vi freq(n + 1, 0);
    rep(i, 1, n + 1) {
        cin >> a[i];
        freq[a[i]]++;
    }
    int F = max_element(all(freq)) - freq.begin();
    rep(i, 1, n + 1) {
        if(i != F && freq[i] == freq[F]) {
            cout << n << '\n';
            return 0;
        }
    }
    if(freq[F] == n) {
        cout << 0 << '\n';
        return 0;
    }

    int ans = 0;
    rep(bruh, 1, K) {
        stupidqueue Q(n);
        int l = 1;
        rep(r, 1, n + 1) {
            Q.push(a[r]);
            while(Q.mode() > bruh) {
                Q.pop(a[l]);
                l++;
            }
            if(Q.ugh()) {
                ans = max(ans, r - l + 1);
            }
        }
    }

    rep(x, 1, n + 1) {
        if(x == F || freq[x] < K) continue;
        vi ve(2 * n + 5, -1);
        ve[n] = 0;
        int s = 0;
        rep(i, 1, n + 1) {
            if(a[i] == F) {
                s++;
            }else if(a[i] == x) {
                s--;
            }
            if(ve[n + s] == -1) {
                ve[n + s] = i;
            }
            ans = max(ans, i - ve[n + s]);
        }
    }
    cout << ans << '\n';
}