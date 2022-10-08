
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
    int n, q;
    cin >> n >> q;
    vi a(n + 1);
    int cnt1 = 0;
    rep(i, 1, n + 1) {
        cin >> a[i];
        cnt1 += (a[i] == 1);
    }
    while(q--) {
        int ty, k;
        cin >> ty >> k;
        if(ty == 1) {
            a[k] = 1 - a[k];
            if(a[k] == 1) cnt1++;
            else cnt1--;
        }else if(cnt1 >= k) {
            cout << 1 << '\n';
        }else {
            cout << 0 << '\n';
        }
    }
}