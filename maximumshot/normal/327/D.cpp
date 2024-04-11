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

#include <conio.h>

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

template<typename T, typename P>
const ostream & operator << (ostream & os, const pair<T, P> & a) {
    os.precision(10);
    os << fixed;
    os << a.first;
    os << ' ';
    os << a.second;
    os << '\n';
    return os;
}

int n, m;
vec< vec<bool> > a, used;
vec< pair<char, pair<int, int> > > ans;

vec< string > mat;

void dfs(int x, int y) {
    ans.push_back(mp('B', mp(x, y)));
    used[x][y] = 1;
    for(int dx = -1;dx <= 1;dx++) {
        for(int dy = -1; dy <= 1;dy++) {
            if(dx != 0 && dy != 0) continue;
            int tox, toy;
            tox = x + dx;
            toy = y + dy;
            if(tox < 0 || tox >= n || toy < 0 || toy >= m) continue;
            if(used[tox][toy]) continue;
            if(!a[tox][toy]) continue;
            dfs(tox, toy);
            ans.push_back(mp('D', mp(tox, toy)));
            ans.push_back(mp('R', mp(tox, toy)));
        }
    }
}

bool check() {
    for(int i(0);i < (int)ans.size();i++) {
        char c;
        int x, y;
        c = ans[i].first;
        x = ans[i].second.first;
        y = ans[i].second.second;
        if(!a[x][y]) return 0;
        if(c == 'D') {
            if(mat[x][y] == '.') return 0;
            mat[x][y] = '.';
        }else {
            if(mat[x][y] != '.') return 0;
            mat[x][y] = c;
        }
    }

    return 1;
}

bool solve()
{
    scanf("%d %d", &n, &m);
    
    a.resize(n, vec<bool>(m, 1));
    used.resize(n, vec<bool>(m, 0));

    for(int i(0);i < n;i++) {
        string tmp = "";
        for(int j(0);j < m;j++) {
            char c;
            scanf(" %c", &c);
            tmp += c;
            if(c == '#') a[i][j] = 0;
            else a[i][j] = 1;
        }
        mat.push_back(tmp);
    }

    for(int i(0);i < n;i++) {
        for(int j(0);j < m;j++) {
            if(used[i][j]) continue;
            if(!a[i][j]) continue;
            dfs(i, j);
        }
    }

    printf("%d\n", (int)ans.size());

    for(int i(0);i < (int)ans.size();i++) {
        char c;
        int x, y;
        c = ans[i].first;
        x = ans[i].second.first;
        y = ans[i].second.second;
        printf("%c %d %d\n", c, x + 1, y + 1);
    }

    return true;
}   

int main() 
{
    //while(solve());
    solve();
    
    return 0;
}