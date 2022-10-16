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

const int MAX = 1e5 + 5, INF = 1e9;

int a, b;

void init(void) {
    cin >> a >> b;
}

void process(void) {
    if (a < b) { cout << -1 << endl; return; }
    double res = 1e10;
    double k1 = floor(((double)a / b - 1) / 2);
    res = min(res, ((double)a - b) / k1 / 2);
    double k2 = floor(((double)a / b + 1) / 2);
    res = min(res, ((double)a + b) / k2 / 2);
    cout << setprecision(12) << fixed << res << endl;
}

int main(void) {
    init();
    process();
    return 0;
}