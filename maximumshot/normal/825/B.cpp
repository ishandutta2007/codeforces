#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 10;

char mat[N][N];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    for(int i = 0;i < N;i++) {
        for(int j = 0;j < N;j++) {
            scanf(" %c", &mat[i][j]);
        }
    }

    for(int i = 0;i < N;i++) {
        for(int j = 0;j < N;j++) {
            if(mat[i][j] != '.') continue;
            int cl = 0;
            int cr = 0;
            int cu = 0;
            int cd = 0;
            int clu = 0;
            int cld = 0;
            int cru = 0;
            int crd = 0;

            for(int q = j - 1;q >= 0 && mat[i][q] == 'X';q--) cl++;
            for(int q = j + 1;q < N && mat[i][q] == 'X';q++) cr++;
            for(int q = i - 1;q >= 0 && mat[q][j] == 'X';q--) cu++;
            for(int q = i + 1;q < N && mat[q][j] == 'X';q++) cd++;
            for(int q = 1;i - q >= 0 && j - q >= 0 && mat[i - q][j - q] == 'X';q++) clu++;
            for(int q = 1;i - q >= 0 && j + q < N && mat[i - q][j + q] == 'X';q++) cru++;
            for(int q = 1;i + q < N && j - q >= 0 && mat[i + q][j - q] == 'X';q++) cld++;
            for(int q = 1;i + q < N && j + q < N && mat[i + q][j + q] == 'X';q++) crd++;
            if(cl + cr >= 4 || cu + cd >= 4 || clu + crd >= 4 || cru + cld >= 4) {
                puts("YES");
                return 0;
            }
        }
    }

    puts("NO");

    return 0;
}