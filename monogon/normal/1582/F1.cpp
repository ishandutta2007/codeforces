
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
    int n;
    cin >> n;
    vi minval(512, INT_MAX);
    minval[0] = -1;
    rep(i, 0, n) {
        int a;
        cin >> a;
        rep(x, 0, 512) {
            if(minval[x] < a) {
                minval[x ^ a] = min(minval[x ^ a], a);
            }
        }
    }
    vi ve;
    rep(i, 0, 512) if(minval[i] < INT_MAX) ve.push_back(i);
    cout << sz(ve) << '\n';
    for(int x : ve) cout << x << ' ';
    cout << '\n';
}