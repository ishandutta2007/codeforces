
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
int t, n, p[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        vi ve;
        rep(i, 0, n) {
            cin >> p[i];
        }
        rep(i, 0, n) {
            if(i == 0 || i == n - 1 || (p[i] > p[i - 1]) != (p[i + 1] > p[i])) {
                ve.push_back(p[i]);
            }
        }
        cout << sz(ve) << '\n';
        for(int x : ve) {
            cout << x << ' ';
        }
        cout << '\n';
    }
}