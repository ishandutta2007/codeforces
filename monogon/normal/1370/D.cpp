
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

const int N = 2e5 + 5;
int n, k, a[N];

// [i, j)
int check(int val, int l, int r) {
    int ans = 0;
    rep(i, l, r) {
        if(a[i] <= val) {
            i++;
            ans++;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    rep(i, 0, n) {
        cin >> a[i];
    }
    int L = 1, R = 1e9 + 5;
    // int even = k / 2;
    // int odd = k - even;
    while(L < R) {
        int m = L + (R - L) / 2;
        bool flag = false;
        if(k % 2 == 0) {
            flag = (check(m, 0, n - 1) >= k / 2 || check(m, 1, n) >= k / 2);
        }else {
            flag = (check(m, 0, n) >= (k + 1) / 2 || check(m, 1, n - 1) >= k / 2);
        }
        if(flag) {
            R = m;
        }else {
            L = m + 1;
        }
    }
    // rep(i, 0, 20) {
    //     bool flag = false;
    //     if(k % 2 == 0) {
    //         flag = (check(i, 0, n - 1) <= k / 2 || check(i, 1, n) <= k / 2);
    //     }else {
    //         flag = (check(i, 0, n) <= (k + 1) / 2 || check(i, 1, n - 1) <= k / 2);
    //     }
    //     cout << flag << ' ';
    // }
    // cout << endl;
    cout << L << '\n';
}