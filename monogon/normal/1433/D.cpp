
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
        int n;
        cin >> n;
        vi a(n);
        int idx = -1;
        rep(i, 0, n) {
            cin >> a[i];
            if(a[i] != a[0]) idx = i;
        }
        if(idx == -1) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        rep(i, 1, n) {
            if(a[i] != a[0]) {
                cout << 1 << ' ' << i + 1 << '\n';
            }else {
                cout << idx + 1 << ' ' << i + 1 << '\n';
            }
        }
    }
}