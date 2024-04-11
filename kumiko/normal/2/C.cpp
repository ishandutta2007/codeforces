#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <cctype>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <set>
#include <map>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+5;
const double eps = 1e-5;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
void fre() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}
 
struct circle {
    double x, y, r;
}c[3];
double ansx, ansy;
double err;
double angle[3];
double step;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
 
double cal_dis(circle a, circle b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
 
double cal_err(circle a) {
    for (int i = 0; i < 3; ++i) {
        angle[i] = cal_dis(a, c[i]) / c[i].r;
    }
    double err = 0;
    for (int i = 0; i < 3; ++i) {
        err += (angle[i] - angle[(i + 1) % 3]) * (angle[i] - angle[(i + 1) % 3]);
    }
    return err;
}
 
int main() {
    //fre();
    ansx = 0; ansy = 0;
    for (int i = 0; i < 3; ++i) {
        scanf("%lf%lf%lf", &c[i].x, &c[i].y, &c[i].r);
        ansx += c[i].x;
        ansy += c[i].y;
    }
    ansx /= 3; ansy /= 3;
    err = cal_err((circle){ansx, ansy, 0});
    step = 1;
 
    for (int t = 1; t <= maxn; ++t) {
        bool tag = 0;
        double x, y;
        for (int i = 0; i < 4; ++i) {
            double nx = ansx + dx[i] * step;
            double ny = ansy + dy[i] * step;
            double error = cal_err((circle{nx, ny, 0}));
            if (error < err) {
                err = error;
                x = nx;
                y = ny;
                tag = 1;
            }
        }
        if (!tag) {
            step /= 2;
        }
        else {
            ansx = x;
            ansy = y;
        }
    }
 
    if (err < eps) {
        printf("%0.5lf %0.5lf", ansx, ansy);
    }
    return 0;
}