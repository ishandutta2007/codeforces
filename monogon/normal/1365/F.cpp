
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

const int N = 505;
int t, n;
ll a[N], b[N];
bool match[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        fill(match, match + n, false);
        rep(i, 0, n) cin >> a[i];
        rep(i, 0, n) cin >> b[i];
        rep(i, 0, (n + 1) / 2) {
            rep(j, 0, n) {
                if(!match[j] && !match[n - j - 1] && a[i] == b[j] && a[n - i - 1] == b[n - j - 1]) {
                    match[j] = match[n - j - 1] = true;
                    goto lab;
                }
            }
            cout << "No\n";
            goto endtest;
            lab:;
        }
        cout << "Yes\n";
        endtest:;
    }
}