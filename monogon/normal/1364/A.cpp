
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
int t, n, x;
ll a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> x;
        ll sum = 0;
        int idx = n, idx2 = -1;
        rep(i, 0, n) {
            cin >> a[i];
            sum += a[i];
            if(a[i] % x != 0) {
                idx = min(idx, i);
                idx2 = max(idx2, i);
            }
        }
        if(sum % x != 0) {
            cout << n << '\n';
        }else if(idx > idx2) {
            cout << "-1\n";
        }else {
            cout << n - min(idx + 1, n - idx2) << '\n';
        }
    }
}