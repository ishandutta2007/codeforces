#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

void mnm(int& a, int b) { if (a > b) a = b; }
int N;
int a[502];
int f[502][502];

int main(void) {
    cin >> N;
    ff(i, 1, N) cin >> a[i];
    ff(i, 1, N) f[i][i] = 1;
    ff(i, 1, N - 1) f[i][i+1] = 1 + (a[i] != a[i+1]);
    ff(d, 2, N - 1) ff(i, 1, N - d) {
        f[i][i+d] = d + 1;
        ff(k, i, i + d) if (a[i] == a[k]) {
            if (k - i >= 2) mnm(f[i][i+d], f[i+1][k-1] + f[k+1][i+d]);
            else mnm(f[i][i+d], 1 + f[k+1][i+d]);
        }
    }
    cout << f[1][N] << endl;
    return 0;
}