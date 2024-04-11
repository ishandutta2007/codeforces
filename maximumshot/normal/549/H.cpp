#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef pair< int , int > pii;
typedef long long ll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

double const pi = acos(-1.0);
double const eps = 1e-12;

typedef long double ld;

#define double ld

double a, b, c, d;

bool check(double N) {

    vec< pair< double, double > > sq1, sq2;

    sq1 = {{a - N, b - N}, {a - N, b + N}, {a + N, b + N}, {a + N, b - N}};
    sq2 = {{c - N, d - N}, {c - N, d + N}, {c + N, d + N}, {c + N, d - N}};

    if(a - N <= 0 && 0 <= a + N && b - N <= 0 && 0 <= b + N) return 1;
    if(c - N <= 0 && 0 <= c + N && d - N <= 0 && 0 <= d + N) return 1;

    for(int iter = 0;iter < 2;iter++) {
        for (int i = 0; i < 4; i++) {
            double x, y;
            tie(x, y) = sq1[i];
            for (int j = 0; j < 4; j++) {
                int k = (j + 1) % 4;
                double x1, y1, x2, y2;
                tie(x1, y1) = sq2[j];
                tie(x2, y2) = sq2[k];
                double v1, v2;
                v1 = x1 * y - x * y1;
                v2 = x2 * y - x * y2;
                if (v1 <= 0 && v2 >= 0 || v1 >= 0 && v2 <= 0) return true;
            }
        }
        swap(sq1, sq2);
    }

    return 0;
}

bool solve() {

    cin >> a >> b >> c >> d;

    double bl, br, bm;
    bl = 0;
    br = inf;

    for(int iter = 0;iter < 10000;iter++) {
        bm = (bl + br) * 0.5;
        if(check(bm)) br = bm;
        else bl = bm;
    }

    cout << fixed << setprecision(20) << (bl + br) / 2 << '\n';

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}