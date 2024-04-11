
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

const int N = 105, K = 55;
int t, n, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        rep(i, 0, n) {
            cin >> a[i];
        }
        string s(K, 'a');
        rep(i, 0, n) {
            cout << s << '\n';
            rep(j, a[i], K) {
                s[j] = 'a' + 'b' - s[j];
            }
        }
        cout << s << '\n';
    }
}