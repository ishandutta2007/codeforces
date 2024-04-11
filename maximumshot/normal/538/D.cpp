#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector
#define deb(x) cerr << #x << " = " << x << '\n';

typedef unsigned long long ull;
typedef long double LD;
typedef long long LL;

const LL inf = 1000000000ll;
const LL inf64 = inf * inf;
const LL base = inf + 7;
const LL MOD = inf + 9;
const double pi = acos(-1.0);

using namespace std;

bool solve()
{
    int n;

    scanf("%d", &n);

    vec< vec<char> > mat(n, vec<char>(n, ' '));
    vec< vec<bool> > can(2 * n - 1, vec<bool>(2 * n - 1, 1));
    vec< vec<bool> > is(n, vec<bool>(n, 0));

    for(int i(0);i < n;i++) {
        for(int j(0);j < n;j++) {
            char c;
            scanf(" %c", &c);
            mat[i][j] = c;
        }
    }

    for(int i(0);i < n;i++) {
        for(int j(0);j < n;j++) {
            if(mat[i][j] != 'o') continue;

            for(int k1(0);k1 < n;k1++) {
                for(int k2(0);k2 < n;k2++) {
                    if(mat[k1][k2] != '.') continue;
                    int di, dj;
                    di = k1 - i;
                    dj = k2 - j;
                    can[di + n - 1][dj + n - 1] = 0;
                }
            }
        }
    }

    for(int i(0);i < n;i++) {
        for(int j(0);j < n;j++) {
            if(mat[i][j] != 'o') continue;

            for(int k1(0);k1 < 2 * n - 1;k1++) {
                for(int k2(0);k2 < 2 * n - 1;k2++) {
                    if(can[k1][k2]) {
                        int di, dj;
                        di = k1 - n + 1;
                        dj = k2 - n + 1;
                        int toi, toj;
                        toi = i + di;
                        toj = j + dj;

                        if(0 <= toi && toi < n)
                            if(0 <= toj && toj < n)
                                is[toi][toj] = 1;
                    }
                }
            }
        }
    }

    for(int i(0);i < n;i++) {
        for(int j(0);j < n;j++) {
            if(mat[i][j] != 'x') continue;
            if(!is[i][j]) {
                puts("NO");
                return true;
            }
        }
    }

    puts("YES");

    for(int i(0);i < 2 * n - 1;i++) {
        for(int j(0);j < 2 * n - 1;j++) {
            if(i == n - 1 && j == n - 1) printf("o");
            else printf(can[i][j]?"x" : ".");
        }
        printf("\n");
    }

    return true;
}   

int main() 
{
    //while(solve());
    solve();

    return 0;
}