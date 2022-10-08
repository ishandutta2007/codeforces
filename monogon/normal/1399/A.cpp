
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
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vi a(n);
        rep(i, 0, n) {
            cin >> a[i];
        }
        sort(all(a));
        a.erase(unique(all(a)), a.end());
        n = sz(a);
        bool flag = true;
        rep(i, 0, n) {
            if(a[i] != a[0] + i) {
                flag = false;
            }
        }
        cout << (flag ? "YES" : "NO") << '\n';
    }
}