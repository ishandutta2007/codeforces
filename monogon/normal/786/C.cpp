
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

const int N = 1e5 + 5;
int n, a[N], cnt[N], ans[N];

int check(int k) {
    if(ans[k] > 0) return ans[k];
    fill(cnt + 1, cnt + n + 1, 0);
    int i = 0, j = 0, s = 0, res = 0;
    while(i < n) {
        while(j < n) {
            if(cnt[a[j]] == 0) {
                if(s == k) break;
                s++;
            }
            cnt[a[j]]++;
            j++;
        }
        res++;
        while(i < j) {
            cnt[a[i]]--;
            i++;
        }
        s = 0;
    }
    return ans[k] = res;
}

void solve(int l, int r, int valL, int valR) {
    if(r < l) return;
    if(valL == valR) {
        fill(ans + l, ans + r + 1, valL);
        return;
    }
    int valM = valL + (valR - valL) / 2;
    // find first index with value <= valM
    int L = l, R = r;
    while(L < R) {
        int M = L + (R - L) / 2;
        if(check(M) > valM) {
            L = M + 1;
        }else {
            R = M;
        }
    }
    check(L);
    solve(l, L - 1, valM + 1, valR);
    solve(L + 1, r, valL, valM);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 0, n) {
        cin >> a[i];
    }
    solve(1, n, 1, n);
    rep(i, 1, n + 1) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}