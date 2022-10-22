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
#include <list>
#include <cstring>

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
    int n, m;
    cin >> n >> m;

    vec< vec< int > > mat(n, vec< int >(m));

    for(int i = 0;i < n;i++) for(int j = 0;j < m;j++) {
        cin >> mat[i][j];
        if(mat[i][j] == 0) continue;
        if(i == 0 || i == n - 1 || j == 0 || j == m - 1) {
            puts("2");
            return true;
        }
    }

    puts("4");

    return true;
}  

int main() 
{
    //while(solve());
    solve();
    
    return 0;
}