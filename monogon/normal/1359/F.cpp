
#pragma GCC optimize ("Ofast")
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

const int N = 25005;
int n;
int px[N], py[N], dx[N], dy[N], s[N];
double D[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 0, n) {
        cin >> px[i] >> py[i] >> dx[i] >> dy[i] >> s[i];
        D[i] = s[i] / hypot(dx[i], dy[i]);
    }
    double ans = DBL_MAX;
    rep(i, 0, n) rep(j, i + 1, n) {
        int det = dx[i] * dy[j] - dx[j] * dy[i];
        int dpx = px[j] - px[i];
        int dpy = py[j] - py[i];
        if(det != 0) {
            double t1 = 1.0 * (dy[j] * dpx - dx[j] * dpy) / (D[i] * det);
            double t2 = 1.0 * (dy[i] * dpx - dx[i] * dpy) / (D[j] * det);
            if(t1 >= 0 && t2 >= 0) {
                ans = min(ans, max(t1, t2));
            }
        }else if((px[i] - px[j]) * dy[j] == dx[j] * (py[i] - py[j])) {
            int ss = 0;
            if(dpx * dx[i] > 0) ss += s[i];
            if(dpx * dx[j] < 0) ss += s[j];
            if(ss > 0) {
                ans = min(ans, 1.0 * hypot(dpx, dpy) / ss);
            }
        }
    }
    cout << fixed << setprecision(8);
    if(ans == DBL_MAX) {
        cout << "No show :(\n";
    }else {
        cout << ans << '\n';
    }
}