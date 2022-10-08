
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 105;
const double EPS = 1e-10;
int n;
double vb, vs, xu, yu;
double a[N], d[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> vb >> vs;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(i > 0) {
            d[i] = d[i - 1] + abs(a[i] - a[i - 1]);
        }
    }
    cin >> xu >> yu;
    double best = -1;
    int j = 1;
    for(int i = 1; i < n; i++) {
        double dist = d[i] / vb + hypot(xu - a[i], yu) / vs;
        if(best < 0 || dist < best - EPS || (abs(dist - best) < EPS && hypot(xu - a[i], yu) < hypot(xu - a[j], yu))) {
            best = dist;
            j = i;
        }
    }
    cout << (j + 1) << endl;
}