#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

int N;
double a[102];
double b[102];

const double INF = 1e9;
double f(int x) { if (b[x] == 1) return INF; return (1 - b[x] * a[x]) / (1 - b[x]); }

int main(void) {
    cin >> N;
    int cur = 0;
    ff(i, 1, N) { cin >> a[i]; a[i] = 1 - a[i] / 100; }
    ff(i, 1, N) b[i] = 1;
    double d = 0, e;
    int t;
    ff(rep, 1, 500000) {
        d += 1; e = 1;
        ff(i, 1, N) e *= (1 - b[i]);
        d -= e;
        t = 1;
        ff(i, 2, N) if (f(i) > f(t)) t = i;
        b[t] *= a[t];
        //???
    }
    cout << setprecision(15) << fixed << d << endl;
    return 0;
}