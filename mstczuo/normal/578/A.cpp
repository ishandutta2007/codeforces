# include <iostream>
# include <cstdio>
# include <cstring>

using namespace std;

const double inf = 1e30;

double solve1(int x,int y) {
    if(x == y) return x;
    if(x < y) return inf;
    double t = (x - y) / 2.;
    int R = 0;
    for(int k = 30; k >= 0; --k) {
        if(t / (R + (1<<k)) >= y) {
            R += 1 << k;
        }
    }
    return R ? t / R : inf;
}

double solve2(int x,int y) {
    if(x <= y) return inf;
    double t = (x + y) / 2.;
    int R = 0;
    for(int k = 30; k >= 0; --k) {
        if(t / (R + (1<<k)) >= y) {
            R += 1 << k;
        }
    }
    return R ? t / R : inf;
}

int main() {
    int a, b;
    cin >> a >> b;
    double ans = min(solve1(a,b), solve2(a,b));
    if(ans == inf) cout << -1 << endl;
    else printf("%.10f\n", ans);
}