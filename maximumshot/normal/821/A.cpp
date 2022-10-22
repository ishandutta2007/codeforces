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

int const N = 55;

int n;
int a[N][N];

int main() {

#ifdef maximumSHOT
    freopen("input.txt", "r", stdin);
#endif


    scanf("%d", &n);

    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for(int x = 1;x <= n;x++) {
        for(int y = 1;y <= n;y++) {
            if(a[x][y] == 1) continue;
            int ok = 0;
            for(int s = 1;s <= n;s++) {
                for(int t = 1;t <= n;t++) {
                    if(a[x][y] == a[x][s] + a[t][y]) {
                        ok = 1;
                        break;
                    }
                }
                if(ok) break;
            }
            if(!ok) {
                puts("No");
                return 0;
            }
        }
    }

    puts("Yes");

    return 0;
}