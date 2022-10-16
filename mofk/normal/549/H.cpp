#include <bits/stdc++.h>
#define ff(i,a,b) for(int i = (a), _b = (b); i <= _b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
using namespace std;
typedef pair <int, int> ii;
typedef vector <ii> vii;
typedef vector <int> vi;

const int MAX=1e5+5, INF=1e9;

int a, b, c, d;

void init(void) {
    cin >> a >> b >> c >> d;
}

void process(void) {
    if (1ll * a * d == 1ll * b * c) {cout << "0.000000000000";return;}
    ll D = 1ll * a * d - 1ll * b * c;
    long double res = 1e18;
    if(0ll + a + b + c + d != 0) res = min (res, abs((long double) D / (0ll + a + b + c + d)));
    if(0ll + a - b + c - d != 0) res = min (res, abs((long double) D / (0ll + a - b + c - d)));
    if(0ll + a + b - c - d != 0) res = min (res, abs((long double) D / (0ll + a + b - c - d)));
    if(0ll + a - b - c + d != 0) res = min (res, abs((long double) D / (0ll + a - b - c + d)));
    cout << setprecision(12) << fixed << res;
}

int main(void) {
    init();
    process();
    return 0;
}