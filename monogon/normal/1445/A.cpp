
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
        int n, x;
        cin >> n >> x;
        vi a(n), b(n);
        rep(i, 0, n) cin >> a[i];
        rep(i, 0, n) cin >> b[i];
        sort(all(a));
        sort(a.rbegin(), a.rend());
        bool flag = true;
        rep(i, 0, n) {
            if(a[i] + b[i] > x) {
                flag = false;
                break;
            }
        }
        cout << (flag ? "Yes" : "No") << '\n';
    }
}