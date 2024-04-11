
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

const int N = 5e5 + 5;
int n;
ll x[N][2], y[N][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    cout << "YES\n";
    rep(i, 0, n) {
        cin >> x[i][0] >> y[i][0] >> x[i][1] >> y[i][1];
        cout << 1 + ((x[i][0] & 1) + ((y[i][0] & 1) * 2)) << '\n';
    }
}