
#define _USE_MATH_DEFINES

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

// polygon with n sides and length 2r
// triangle R + r, R + r, 2r
// angle 2pi / n
// sin(pi / n) = r / (R + r)
// R + r = r / sin(pi / n)
// R = r(-11 + 1 / sin(pi / n))

int n, r;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> r;
    cout << fixed << setprecision(8);
    cout << 1.0 * r / (-1 + 1.0 / sin(M_PI / n)) << '\n';
}