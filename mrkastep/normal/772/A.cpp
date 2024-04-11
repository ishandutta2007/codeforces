#include <bits/stdc++.h>

typedef long long int ll;
typedef unsigned long long ull;

using namespace std;

const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
const double eps = 1e6;
const ll LONGINF = 4e18;

int a[100100], b[100100];

void solve() {
    int n;
    int p;
    cin >> n >> p;
    ll sa = 0, sb = 0;
    for(int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        sa += a[i];
        sb += b[i];
    }
    if(sa <= p) {
        puts("-1");
        return;
    }
    double l = 0, r = 1e11;
    for(int k = 0; k < 200; ++k) {
        double t = (r + l) / 2;
        double s = 0;
        for(int i = 0; i < n; ++i) {
            if(a[i] <= b[i] / t)
                continue;
            s += a[i] - b[i] / t;
        }
        if(s <= p)
            l = t;
        else
            r = t;
    }
    printf("%.10lf\n", l);
}


int main() {
#pragma comment(linker, "/STACK:268435456")
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve();

    return 0;
}