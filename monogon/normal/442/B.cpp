
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

const int N = 105;
int n;
double a[N];
const double EPS = 1e-9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    cout << fixed << setprecision(10);
    rep(i, 0, n) {
        cin >> a[i];
        if(a[i] >= 1 - EPS) {
            cout << 1 << '\n';
            return 0;
        }
    }
    sort(a, a + n, greater<>());
    double ans = 0;
    double prod = 1, sum = 0;
    rep(i, 0, n) {
        prod *= (1 - a[i]);
        sum += a[i] / (1 - a[i]);
        ans = max(ans, prod * sum);
    }
    cout << ans << '\n';
}