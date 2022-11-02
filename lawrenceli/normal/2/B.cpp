#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

#define print(x) cerr << #x << " is " << x << endl;

const int MAXN = 1005;
const int INF = 1e9;

int n, mat[MAXN][MAXN], mat2[MAXN][MAXN], mat5[MAXN][MAXN], ans = INF;
int dp2[MAXN][MAXN], dp5[MAXN][MAXN], cnt;
bool zero;
char str[2*MAXN];

int calc2(int i, int j) {
    if (i<0 || j<0) return INF;
    if (dp2[i][j] != -1) return dp2[i][j];
    return dp2[i][j] = mat2[i][j] + min(calc2(i-1, j), calc2(i, j-1));
}

int calc5(int i, int j) {
    if (i<0 || j<0) return INF;
    if (dp5[i][j] != -1) return dp5[i][j];
    return dp5[i][j] = mat5[i][j] + min(calc5(i-1, j), calc5(i, j-1));
}

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            scanf("%d", &mat[i][j]);
            if (mat[i][j] == 0) {
                ans = 1; zero = 1;
                mat2[i][j] = mat5[i][j] = INF;
            } else {
                for (int k=mat[i][j]; k%2 == 0; k /= 2) mat2[i][j]++;
                for (int k=mat[i][j]; k%5 == 0; k /= 5) mat5[i][j]++;
            }
            dp2[i][j] = dp5[i][j] = -1;
        }
    }
    dp2[0][0] = mat2[0][0];
    dp5[0][0] = mat5[0][0];
    ans = min(ans, min(calc2(n-1, n-1), calc5(n-1, n-1)));
    if (ans == 1 && zero == 1) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (mat[i][j] == 0) {
                    printf("1\n");
                    for (int k=0; k<j; k++) printf("R");
                    for (int k=0; k<n-1; k++) printf("D");
                    for (int k=j; k<n-1; k++) printf("R");
                    printf("\n");
                    return 0;
                }
            }
        }
    } else if (ans == dp2[n-1][n-1]) {
        int i = n-1, j = n-1;
        while (i != 0 || j != 0) {
            if (i>0 && dp2[i][j] == dp2[i-1][j] + mat2[i][j]) {
                str[cnt++] = 'D'; i--;
            } else {
                str[cnt++] = 'R'; j--;
            }
        }
        printf("%d\n", ans);
        for (int i=cnt-1; i>=0; i--) printf("%c", str[i]);
        printf("\n");
        return 0;
    } else {
        int i = n-1, j = n-1;
        while (i != 0 || j != 0) {
            if (i>0 && dp5[i][j] == dp5[i-1][j] + mat5[i][j]) {
                str[cnt++] = 'D'; i--;
            } else {
                str[cnt++] = 'R'; j--;
            }
        }
        printf("%d\n", ans);
        for (int i=cnt-1; i>=0; i--) printf("%c", str[i]);
        printf("\n");
        return 0;
    }
    return 0;
}