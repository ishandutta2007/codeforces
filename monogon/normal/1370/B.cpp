
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

// pair even numbers
// pair odd numbers
// there might be an odd-even pair leftover, that's ok

const int N = 1005;
int t, n, a[2 * N];
bool taken[2 * N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        rep(i, 0, 2 * n) {
            cin >> a[i];
        }
        int cnt = 0;
        fill(taken, taken + 2 * n, false);
        for(int i = 0; cnt < n - 1; i++) {
            if(taken[i]) continue;
            int j = 0;
            while(j < 2 * n && (taken[j] || j == i || (a[i] + a[j]) % 2 != 0)) j++;
            if(j == 2 * n) continue;
            cout << i+1 << ' ' << j+1 << '\n';
            cnt++;
            taken[i] = true;
            taken[j] = true;
        }
    }
}