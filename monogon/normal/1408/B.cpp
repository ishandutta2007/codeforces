
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        int n, k;
        cin >> n >> k;
        vi a(n);
        int cnt = 0;
        rep(i, 0, n) {
            cin >> a[i];
            if(i > 0 && a[i] != a[i - 1]) cnt++;
        }
        if(cnt == 0) {
            cout << 1 << '\n';
        }else if(k == 1) {
            cout << -1 << '\n';
        }else {
            cout << (cnt + k - 2) / (k - 1) << '\n';
        }
    }
}