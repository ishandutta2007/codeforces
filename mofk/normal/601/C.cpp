#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

const int MAX = 101;

int N, M;
int a[MAX];
double f[MAX][100001];
double s[MAX][100001];

int main(void) {
    cin >> N >> M;
    int S = 0;
    ff(i, 1, N) { cin >> a[i]; S += a[i]; }
    if (M == 1) return cout << setprecision(15) << fixed << 1 << endl, 0;
    f[0][0] = 1; ff(d, 0, N * M) s[0][d] = 1;
    ff(n, 1, N) ff(d, 1, N * M) {
        f[n][d] = (s[n-1][d-1] - (d <= M ? 0 : s[n-1][d-M-1]) - (d < a[n] ? 0 : f[n-1][d-a[n]])) / (M - 1);
        s[n][d] = s[n][d-1] + f[n][d];
    }
    cout << setprecision(15) << fixed << s[N][S-1] * (M - 1) + 1 << endl;
    return 0;
}