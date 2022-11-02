#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define px real()
#define py imag()
#define rep(i, n) for (int i=0, _##i=(n); i<_##i; ++i)
#define repi(i, n) for (__typeof((n).begin()) i=(n).begin(), _##i=n.end(); i != _##i; ++i)
#define sz(x) int((x).size())
#define print(x) cerr << #x << ": " << x << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<double> pnt;

const int MAXN = 1005;

int n, m, mat[MAXN][MAXN], mat2[MAXN][MAXN], mat3[MAXN][MAXN];
bool r;
char s[MAXN];

void rot() {
    memset(mat2, 0, sizeof(mat2));
    rep(i, n)
        rep(j, m)
            mat2[j][n-1-i] = mat[i][j];
    memcpy(mat, mat2, sizeof(mat2));
    swap(n, m);
    r = 1;
}

void go(int a, int b) {
    memcpy(mat3, mat, sizeof(mat));
    int c, d;
    for (int i=1; i<=4; i++)
        if (i != a && i != b) {
            c = i; break;
        }
    for (int i=1; i<=4; i++)
        if (i != a && i != b && i != c) d = i;

    int x[2][2] = {{a, b}, {c, d}};

    rep(i, n) {
        int c = 0;
        rep(j, m) {
            if (!mat[i][j]) continue;
            if (mat[i][j] != x[i&1][0] && mat[i][j] != x[i&1][1]) return;
            if (mat[i][j] == x[i&1][0]) c = j&1;
            else c = (j&1)^1;
        }
        rep(j, m) {
            if (!mat[i][j]) mat3[i][j] = x[i&1][c^(j&1)];
            else if (mat[i][j] != x[i&1][c^(j&1)]) return;
        }
    }

    memcpy(mat, mat3, sizeof(mat3));
    if (r) rot(), rot(), rot();

    rep(i, n) {
        rep(j, m) printf("%d", mat[i][j]);
        printf("\n");
    }
    exit(0);
}

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    scanf("%d %d\n", &n, &m);
    rep(i, n) {
        gets(s);
        rep(j, m)
            mat[i][j] = s[j]-'0';
    }

    rep(i, n)
        rep(j, m)
            if (mat[i][j])
                for (int dr=-1; dr<=1; dr++)
                    for (int dc=-1; dc<=1; dc++)
                        if (dr!=0 || dc!=0) {
                            int nr = i+dr, nc = j+dc;
                            if (nr>=0 && nr<n && nc>=0 && nc<m)
                                if (mat[nr][nc] == mat[i][j]) {
                                    cout << "0\n";
                                    return 0;
                                }
                        }

    for (int i=1; i<=4; i++)
        for (int j=i+1; j<=4; j++)
            go(i, j);

    rot();

    for (int i=1; i<=4; i++)
        for (int j=i+1; j<=4; j++)
            go(i, j);

    cout << "0\n";
    return 0;
}