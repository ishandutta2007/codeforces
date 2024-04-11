#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back
#define y1 fmdkmaewof

typedef long long ll;
using namespace std;
typedef vector <int> vi;

const double eps = 1e-9;
int N;
int x1, y1, x2, y2;
int rx, ry, vx, vy;
pair <int, int> Min, Max;

bool cmp(pair <int, int> a, pair <int, int> b) { return 1ll * a.first * b.second < 1ll * a.second * b.first; }

void work(int l, int r, int v) {
    if (v == 0) {
        if (l >= 0 || r <= 0) {
            cout << -1 << endl;
            exit(0);
        }
        return;
    }
    if (v < 0) l = -l, r = -r, v = -v, swap(l, r);
    pair <int, int> L = make_pair(l, v), R = make_pair(r, v);
    if (cmp(Min, L)) Min = L;
    if (cmp(R, Max)) Max = R;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    cin >> x1 >> y1 >> x2 >> y2;
    Min = make_pair(0, 1);
    Max = make_pair(1, 0);
    ff(i, 1, N) {
        cin >> rx >> ry >> vx >> vy;
        work(x1 - rx, x2 - rx, vx);
        work(y1 - ry, y2 - ry, vy);
    }
    if (!cmp(Min, Max)) return cout << -1 << endl, 0;
    cout << setprecision(15) << fixed << ((double)Min.first / Min.second + eps) << endl;
    return 0;
}