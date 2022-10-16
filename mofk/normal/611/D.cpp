#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

const int mod = 1000000007;
int N;
char a[5005];
int f[5005][5005];
int s[5005][5005];
int b[5005][5005];

int main(void) {
    scanf("%d%s", &N, a + 1);
    int l, r, t;
    ff(i, 1, N - 1) ff(j, i + 1, N) if (a[i] != a[j]) {
        t = (a[i] < a[j]) ? -1 : 1;
        b[i][j] = t;
        l = i - 1; r = j - 1;
        while (l && r > i && a[l] == a[r]) { b[l][r] = t; --l; --r; }
    }
    /*ff(i, 1, N - 1) ff(j, i + 1, N) if (j + j - i - 1 <= N) {
        ff(k, 0, j - i - 1) cout << a[k+i]; cout << " ";
        ff(k, 0, j - i - 1) cout << a[k+j]; cout << " ";
        cout << b[i][j] << "\n";
    }*/
    ff(i, 1, N) {
        ff(j, 1, i - 1) {
            if (a[i-j+1] == '0') continue;
            f[i][j] = s[i-j][j-1];
            if ((i - j - j + 1 > 0) && b[i-j-j+1][i-j+1] == -1) { f[i][j] += f[i-j][j]; if (f[i][j] >= mod) f[i][j] -= mod; }
        }
        f[i][i] = 1;
        ff(j, 1, N) { s[i][j] = s[i][j-1] + f[i][j]; if (s[i][j] >= mod) s[i][j] -= mod; }
    }
    cout << s[N][N] << endl;
    return 0;
}