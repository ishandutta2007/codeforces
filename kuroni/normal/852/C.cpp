#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
const double PI = acos(-1);

int n, u, a[N], b[N];
vector<pair<double, int>> ve;

double area(double xa, double ya, double xb, double yb, double xc, double yc) {
    return abs((xb - xa) * (yc - ya) - (yb - ya) * (xc - xa));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    double ang = PI * (n - 2) / n;
    double dx = cos(ang), dy = sin(ang);
    for (int i = 0; i < n; i++) {
        int le = n - a[i], ri = a[(i + 1) % n];
        double xa = dx * le, ya = dy * le;
        double xc = n - dx * ri, yc = dy * ri;
        ve.push_back({area(xa, ya, 1, 0, xc, yc) - area(xa, ya, 0, 0, xc, yc), i});
    }
    sort(ve.begin(), ve.end());
    for (int i = 0; i < n; i++) {
        // cout << ve[i].first << " " << ve[i].second << '\n';
        b[ve[i].second] = i;
    }
    for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
}