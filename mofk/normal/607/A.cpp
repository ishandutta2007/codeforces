#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back
#define fi first
#define se second

typedef long long ll;
using namespace std;
typedef vector <int> vi;
typedef pair <int, int> ii;

int N;
vector <ii> a;
int f[100001];

int main(void) {
    cin >> N;
    a.assign(N + 1, ii());
    a[0] = ii(-1000000000, -1000000000);
    ff(i, 1, N) cin >> a[i].fi >> a[i].se;
    sort(a.begin(), a.end());
    int res = N;
    ff(i, 1, N) {
        int x = lower_bound(a.begin(), a.end(), ii(a[i].fi - a[i].se, 0)) - a.begin() - 1;
        f[i] = f[x] + i - x - 1;
        res = min(res, f[i] + N - i);
    }
    cout << res << endl;
    return 0;
}