
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

int t, n;
double maxx = 0, maxy = 0;

bool check(double ang) {
    maxx = maxy = 0;
    rep(i, 0, 2 * n) {
        double x = cos(i * (M_PI / n) + ang);
        double y = sin(i * (M_PI / n) + ang);
        maxx = max(maxx, x);
        maxy = max(maxy, y);
    }
    return maxx < maxy;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    cout << fixed << setprecision(8);
    while(t--) {
        cin >> n;
        double L = 0, R = M_PI / n;
        while(R - L > 1e-10) {
            double M = L + (R - L) / 2;
            if(check(M)) {
                L = M;
            }else {
                R = M;
            }
        }
        double r = 0.5 / sin(M_PI / (2 * n));
        cout << maxx * 2 * r << endl;
    }
}