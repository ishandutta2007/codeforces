// by maximumSHOT
#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <string>
#include <fstream>
#include <stdio.h>
#include <stack>
 
using namespace std;
 
#define ALL(x) (x).begin(), (x).end()
#define vec vector
#define mp make_pair
#define close() puts("NO"); return true;
 
typedef long long LL;
typedef long double LD;
typedef pair<int, int> pii;
 
const LL inf = 1000000000ll;
const LL inf64 = inf * inf;
const LL base = inf + 7;
const double pi = acos(-1.0); 

LL Abs(LL x) {return (x >= 0?x : -x);}

bool solve()
{
    int n;

    cin >> n;

    LL ans = 0;

    vec< vec<LL> > mat(n + 1, vec<LL>(n + 1));

    for(int i(1);i <= n;i++) mat[1][i] = mat[i][1] = 1;

    for(int i(2);i <= n;i++) for(int j(2);j <= n;j++) mat[i][j] = mat[i - 1][j] + mat[i][j - 1];
    
    cout << mat[n][n] << '\n';

    return true;
}

int main()
{
    //while(solve());
    solve();
 
    return 0;
}