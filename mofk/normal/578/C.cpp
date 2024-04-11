#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
using namespace std;
typedef pair <int, int> ii;
typedef vector <ii> vii;
typedef vector <int> vi;

const int MAX = 2e5 + 5, INF = 1e9;

void mnm(double &a, double b) { if (a > b) a = b; }
void mxm(double &a, double b) { if (a < b) a = b; }

int N;
double a[MAX];
double l, r;

double f(double x) {
    vector <double> b(1, 0.0); ff(i, 1, N) b.pb(b.back() + a[i] - x);
    double res = 0.0;
    double mn = 0.0, mx = 0.0;
    ff(i, 1, N) {
        mxm(res, abs(b[i] - mn));
        mxm(res, abs(b[i] - mx));
        mnm(mn, b[i]);
        mxm(mx, b[i]);
    }
    return res;
}

void init(void) {
    cin >> N >> a[1]; l = r = a[1];
    ff(i, 2, N) { cin >> a[i]; mnm(l, a[i]); mxm(r, a[i]); }
}

void process(void) {
    ff(o, 1, 75) {
        double ml = (l + l + r) / 3, mr = (l + r + r) / 3;
        if (f(ml) < f(mr)) r = mr;
        else l = ml;
    }
    double res = min(f(l), f(r));
    cout << setprecision(10) << fixed << res << endl;
}

int main(void) {
    init();
    process();
    return 0;
}