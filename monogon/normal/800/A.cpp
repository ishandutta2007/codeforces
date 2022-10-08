
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

const int N = 1e5 + 5;
int n;
ll p, a[N], b[N];
const long double EPS = 1e-6;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> p;
    ll sum = 0;
    rep(i, 0, n) {
        cin >> a[i] >> b[i];
        sum += a[i];
    }
    if(sum <= p) {
        cout << "-1\n";
        return 0;
    }
    long double L = 0, R = 1e16;
    while(R - L > EPS) {
        long double m = L + (R - L) / 2;
        long double sum = 0;
        rep(i, 0, n) {
            sum += max((long double) 0.0, (m * a[i] - b[i]) / p);
        }
        if(sum < m) {
            L = m;
        }else {
            R = m;
        }
    }
    cout << fixed << setprecision(6);
    cout << L << '\n';
}