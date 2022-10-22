#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 6e4 + 5;
int const ITER = 100;

int x[N];
int v[N];
int n;

double f(double x0) {
    double res = 0.0;
    for(int i = 0;i < n;i++) {
        res = max(res, abs(x0 - x[i]) / v[i] );
    }
    return res;
}

int main() {

    scanf("%d", &n);

    for(int i = 0;i < n;i++) {
        scanf("%d", &x[i]);
    }

    for(int i = 0;i < n;i++) {
        scanf("%d", &v[i]);
    }

    double bl = 0.0;
    double br = 1e9;
    double bm1;
    double bm2;

    for(int iter = 0;iter < ITER;iter++) {
        bm1 = bl + (br - bl) / 3.0;
        bm2 = br - (br - bl) / 3.0;
        if(f(bm1) < f(bm2)) br = bm2;
        else bl = bm1;
    }

    cout.precision(10);
    cout << fixed << f((bl + br) / 2.0) << "\n";

    return 0;
}