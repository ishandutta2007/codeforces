
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

const int N = 1005;
int t, n, p[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        int mn = 0;
        rep(i, 0, n) {
            cin >> p[i];
        }
        rep(i, 1, n - 1) {
            if(p[mn] < p[i] && p[i] > p[i + 1]) {
                cout << "YES\n";
                cout << mn+1 << ' ' << i+1 << ' ' << i+2 << '\n';
                goto endtest;
            }
            if(p[i] < p[mn]) mn = i;
        }
        cout << "NO\n";
        endtest:;
    }
}