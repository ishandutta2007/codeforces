#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

const int INF = 1000000789;
int N;
int a[505][505];
int p[505];
int pos[505];
ll ans[505];
int f[505][505];

int main(void) {
    cin >> N;
    ff(i, 1, N) ff(j, 1, N) cin >> a[i][j];
    ff(i, 1, N) { cin >> p[i]; pos[p[i]] = i; }
    ff(i, 1, N) ff(j, 1, N) f[i][j] = a[i][j];
    fb(k, N, 1) {
        ff(i, 1, N) ff(j, 1, N) f[i][j] = min(f[i][j], f[i][p[k]] + f[p[k]][j]);
        ff(i, 1, N) if (pos[i] >= k) ff(j, 1, N) if (pos[j] >= k) ans[k] += f[i][j];
    }
    ff(i, 1, N) cout << ans[i] << " ";
    return 0;
}