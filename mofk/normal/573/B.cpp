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

int N;
int a[MAX];
int f[MAX], g[MAX];

void init(void) {
    cin >> N;
    ff(i, 1, N) cin >> a[i];
}

void process(void) {
    ff(i, 1, N + 1) f[i] = min(f[i-1], a[i] - i);
    g[N+1] = N + 1;
    fb(i, N, 0) g[i] = min(g[i+1], a[i] + i);
    int ans = 0;
    ff(i, 1, N) {
        int res = a[i];
        res = min(res, f[i-1] + i);
        res = min(res, g[i+1] - i);
        ans = max(ans, res);
    }
    cout << ans << endl;
}

int main(void) {
    init();
    process();
    return 0;
}