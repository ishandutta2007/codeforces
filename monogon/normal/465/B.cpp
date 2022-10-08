
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
int n, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int o = 0, s = 0;
    rep(i, 0, n) {
        cin >> a[i];
        o += a[i];
        s += (a[i] == 1 && (i == 0 || a[i - 1] == 0));
    }
    cout << (o == 0 ? 0 : o + max(0, s - 1)) << '\n';
}