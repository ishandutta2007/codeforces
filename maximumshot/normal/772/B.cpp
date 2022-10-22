#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 1e3 + 5;
int const ITER = 70;

inline double Sqr(double x) {
    return x * x;
}

inline bool checkCircles(double x1, double y1, double x2, double y2, double R) {
    return 4.0 * R * R < Sqr(x1 - x2) + Sqr(y1 - y2);
}

inline bool checkCircleLine(double x, double y, double r, double A, double B, double C) {
    return abs(A * x + B * y + C) > sqrt(Sqr(A) + Sqr(B)) * 2.0 * r;
}

inline void getLine(double x1, double y1, double x2, double y2, double & A, double & B, double & C) {
    A = y2 - y1;
    B = x1 - x2;
    C = x1 * (y1 - y2) + y1 * (x2 - x1);
}

int x[N];
int y[N];
int n;

bool check(double r) {
    double A, B, C;
    for(int i = 0;i < n;i++) {
        for(int j = i + 1;j < n;j++) {
            if(!checkCircles(x[i], y[i], x[j], y[j], r)) {
                return false;
            }
        }
        for(int k, j = 0;j < n;j++) {
            k = (j + 1) % n;
            if(j == i || k == i) continue;
            getLine(x[j], y[j], x[k], y[k], A, B, C);
            if(!checkCircleLine(x[i], y[i], r, A, B, C)) {
                return false;
            }
        }
        int j = ((i - 1) % n + n) % n;
        int k = (i + 1) % n;
        getLine(x[j], y[j], x[k], y[k], A, B, C);
        if(!checkCircleLine(x[i], y[i], r, A, B, C)) {
            return false;
        }
    }
    return true;
}

int main() {

    scanf("%d", &n);

    for(int i = 0;i < n;i++) {
        scanf("%d %d", &x[i], &y[i]);
    }

    double bl = 0.0;
    double br = 2e9 + 100;
    double bm;

    for(int iter = 0;iter < ITER;iter++) {
        bm = (bl + br) * 0.5;
        if(check(bm)) bl = bm;
        else br = bm;
    }

    cout.precision(10);
    cout << fixed << bl << "\n";

    return 0;
}