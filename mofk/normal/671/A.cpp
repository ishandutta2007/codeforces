#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

double dist(ll a, ll b, ll c, ll d) { return hypot(a - b, c - d); }

ll ax, ay, bx, by, tx, ty;
int N;
ll x[100005], y[100005];
double f[100005][2][2];
double d[100005];

void mm(double &a, double b) { if (a > b) a = b; }

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> ax >> ay >> bx >> by >> tx >> ty;
    cin >> N;
    ff(i, 1, N) cin >> x[i] >> y[i], d[i] = dist(x[i], tx, y[i], ty);
    ff(i, 1, N) ff(j, 0, 1) ff(k, 0, 1) f[i][j][k] = 1e17;
    f[1][0][0] = 2 * d[1];
    f[1][1][0] = dist(x[1], ax, y[1], ay) + d[1];
    f[1][0][1] = dist(x[1], bx, y[1], by) + d[1];
    ff(i, 1, N - 1) ff(j, 0, 1) ff(k, 0, 1) {
        mm(f[i+1][j][k], f[i][j][k] + 2 * d[i+1]);
        if (j == 0) mm(f[i+1][1][k], f[i][j][k] + d[i+1] + dist(x[i+1], ax, y[i+1], ay));
        if (k == 0) mm(f[i+1][j][1], f[i][j][k] + d[i+1] + dist(x[i+1], bx, y[i+1], by));
    }
    cout << setprecision(12) << fixed << min(min(f[N][0][1], f[N][1][0]), f[N][1][1]) << endl;
    return 0;
}