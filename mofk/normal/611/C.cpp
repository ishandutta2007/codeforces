#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

int N, M, Q;
char a[505][505];
int s[505][505][2];

int cal(int x1, int y1, int x2, int y2, bool i) {
    return s[x2][y2][i] - s[x1-1][y2][i] - s[x2][y1-1][i] + s[x1-1][y1-1][i];
}

int main(void) {
    scanf("%d%d", &N, &M);
    ff(i, 1, N) scanf("%s", a[i] + 1);
    ff(i, 2, N) ff(j, 1, M) s[i][j][0] = s[i-1][j][0] + s[i][j-1][0] - s[i-1][j-1][0] + (a[i][j] == '.' && a[i-1][j] == '.');
    ff(i, 1, N) ff(j, 2, M) s[i][j][1] = s[i-1][j][1] + s[i][j-1][1] - s[i-1][j-1][1] + (a[i][j] == '.' && a[i][j-1] == '.');
    int x1, y1, x2, y2;
    scanf("%d", &Q);
    ff(i, 1, Q) {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        cout << cal(x1 + 1, y1, x2, y2, 0) + cal(x1, y1 + 1, x2, y2, 1) << "\n";
    }
    return 0;
}