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
#include <iomanip>

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
const double pi = acos(-1.0);

using namespace std;

bool solve()
{
    int n;
    cin >> n;

    vec< string > mat(n), tmp;
    for(int i = 0;i < n;i++) cin >> mat[i];
    tmp = mat;
    int ans = 0;

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            if(mat[i][j] == '0') {
                for(int q = 0;q < n;q++) {
                    mat[q][j] = (mat[q][j] == '0'?'1' : '0');
                }
            }
        }
        int c = 0;
        for(int q = 0;q < n;q++) {
            bool ok = 1;
            for(int j = 0;j < n;j++) {
                ok &= (mat[q][j] == '1');
            }
            c += ok;
        }
        ans = max(ans, c);
        mat = tmp;
    }

    cout << ans << '\n';

    return true;
}   

int main() 
{
    //while(solve());
    solve();

    return 0;
}