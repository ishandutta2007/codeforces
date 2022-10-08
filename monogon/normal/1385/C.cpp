
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
int n, a[N];

bool check(int x) {
    int l = x, r = n - 1;
    int pr = INT_MIN;
    while(l < r) {
        if(a[l] < a[r]) {
            if(a[l] < pr) return false;
            pr = a[l];
            l++;
        }else {
            if(a[r] < pr) return false;
            pr = a[r];
            r--;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        vector<pii> ve;
        rep(i, 0, n) {
            cin >> a[i];
            ve.emplace_back(a[i], i);
        }
        int L = 0, R = n;
        while(L < R) {
            int m = (L + R) / 2;
            if(check(m)) {
                R = m;
            }else {
                L = m + 1;
            }
        }
        cout << L << '\n';
    }
}