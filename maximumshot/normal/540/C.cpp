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

int n, m;
vec<string> mat;
vec< vec<bool> > used;
int r1, c1, r2, c2;

void dfs(int i, int j) {
    if(i < 0 || i >= n || j < 0 || j >= m) return;
    if(used[i][j]) return;
    used[i][j] = 1;
    if((i != r1 || j != c1) && mat[i][j] == 'X') return;
    dfs(i - 1, j);
    dfs(i, j - 1);
    dfs(i + 1, j);
    dfs(i, j + 1);
}

bool solve()
{
    scanf("%d %d", &n, &m);

    mat.resize(n);

    for(int i(0);i < n;i++) cin >> mat[i];

    used.resize(n, vec<bool>(m, 0));

    scanf("%d%d%d%d", &r1, &c1, &r2, &c2);

    r1--, c1--;
    r2--, c2--;

    dfs(r1, c1);

    if(!used[r2][c2]) {
        puts("NO");
    }else if(mat[r2][c2] == 'X' && (r1 != r2 || c1 != c2)) {
        puts("YES");
    }else {
        int c = 0;
        if(r2 > 0 && mat[r2 - 1][c2] == '.') c++;
        if(c2 > 0 && mat[r2][c2 - 1] == '.') c++;
        if(r2 + 1 < n && mat[r2 + 1][c2] == '.') c++;
        if(c2 + 1 < m && mat[r2][c2 + 1] == '.') c++;
        if(abs(r1 - r2) == 1 && abs(c1 - c2) == 0 || 
        abs(r1 - r2) == 0 && abs(c1 - c2) == 1) c++;
        puts(c > 1 || (c == 1 && r1 == r2 && c1 == c2)?"YES" : "NO");
    }

    return true;
}   

int main() 
{
    //while(solve());
    solve();

    return 0;
}