#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define vec vector

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 1e5 + 5;
int const ITER = 200;
double const eps = 1e-6;

int n;
int p;
int a[N];
int b[N];

bool check(double t) {
    double tot = t * p;
    for(int i = 0;i < n;i++) {
        tot -= max(0.0, a[i] * t - b[i]);
    }
    return tot > -eps;
}

int main() {

    scanf("%d %d", &n, &p);

    ll tot_sum = 0;
    
    for(int i = 0;i < n;i++) {
        scanf("%d %d", &a[i], &b[i]);
        tot_sum += a[i];
    }
    
    if(tot_sum <= p) {
        cout << "-1\n";
        return 0;
    }

    double bl = 0.0;
    double br = 1e13;
    double bm;

    int OK = 0;

    for(int iter = 0;iter < ITER;iter++) {
        bm = (bl + br) * 0.5;
        if(check(bm)) {
            bl = bm;
        }else {
            br = bm;
            OK = 1;
        }
    }

    if(!OK) {
        cout << "-1\n";
    }else {
        printf("%.10lf\n", bl);
    }

    return 0;
}