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
    int r, s, p;

    scanf("%d %d %d", &r, &s, &p);
    
    const int N = 110;
    double dp[N][N][N];

    for(int i(0);i < N;i++) {
        for(int j(0);j < N;j++) {
            for(int z(0);z < N;z++){
                dp[i][j][z] = 0.0;
            }
        }
    }

    dp[r][s][p] = 1.0;

    for(int i(r);i >= 0;i--) {
        for(int j(s);j >= 0;j--) {
            for(int z(p);z >= 0;z--) {
                int c = !i + !j + !z;
                if(c >= 2) continue;
                double cur = dp[i][j][z];
                double A, B, C;
                A = i * j;
                B = j * z;
                C = z * i;
                double all = A + B + C;
                if(i) dp[i - 1][j][z] += cur * C / all;
                if(j) dp[i][j - 1][z] += cur * A / all;
                if(z) dp[i][j][z - 1] += cur * B / all;
            }
        }
    }

    double A, B, C;
    A = B = C = 0;

    for(int i(1);i <= r;i++) A += dp[i][0][0];
    for(int i(1);i <= s;i++) B += dp[0][i][0];
    for(int i(1);i <= p;i++) C += dp[0][0][i];

    cout.precision(10);
    cout << fixed;

    cout << A << ' ' << B << ' ' << C << '\n';

    return true;
}   

int main() 
{
    //while(solve());
    solve();

    return 0;
}