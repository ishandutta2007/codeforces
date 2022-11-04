#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

int n, k, a[4002][4002] = {0}, x;
int mem[805][4002];
int mej[805][4002];

int dp (int i, int l, int r, int k) {
    int &est = mem[k][i] = 1000000000;
    int &ind = mej[k][i];
    
    for (int h = l; h <= min(r, i); h++) {
        int act = mem[k-1][h-1]
                + a[i][i]
                - a[i][h-1]
                - a[h-1][i]
                + a[h-1][h-1];

        if (act < est) {
            est = act;
            ind = h;
        }
    }

    return est;
}

void obtRes (int i, int j, int l, int r, int k) {
    if (i > j)
        return;

    int m = (i + j) / 2;

    dp (m, l, r, k);
    obtRes (i, m-1, l, mej[k][m], k);
    obtRes (m+1, j, mej[k][m], r, k);
}

int main () {
    //ios_base::sync_with_stdio(0); cin.tie(0);

    scanf("%d %d", &n, &k);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            while((x = getchar()) < '0' || x > '9');
            x -= '0';

            a[i][j] = x
                    + a[i][j-1]
                    + a[i-1][j]
                    - a[i-1][j-1];
        }
    }

    for (int i = 1; i <= n; i++)
        mem[1][i] = a[i][i];

    for (int j = 2; j <= k; j++)
        obtRes(1, n, 1, n, j);

    printf("%d\n", mem[k][n] / 2);

    return 0;
}