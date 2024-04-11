#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 405;

int n, m, r, c;
char a[N][N];
char b[N][N];
bitset< N > G[26][N];
bitset< N > R[N];

int main() {

    scanf("%d %d", &n, &m);
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            scanf(" %c", &a[i][j]);
        }
    }

    scanf("%d %d", &r, &c);
    for(int i = 0;i < r;i++) {
        for(int j = 0;j < c;j++) {
            scanf(" %c", &b[i][j]);
        }
    }

    for(char x = 'a';x <= 'z';x++) {
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                G[x - 'a'][i][j] = a[i][j] == x;
            }
        }
    }

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            R[i][j] = 1;
        }
    }

    for(int x = 0;x < r;x++) {
        for(int t, y = 0;y < c;y++) {
            if(b[x][y] == '?') continue;
            t = b[x][y] - 'a';
            for(int i = 0;i < n;i++) {
                R[i] &= ((G[t][(i+x)%n] >> (y % m)) | (G[t][(i+x)%n] << (((m-y)%m+m)%m)));
            }
        }
    }

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            printf("%d", int(R[i][j]));
        }
        printf("\n");
    }

    return 0;
}