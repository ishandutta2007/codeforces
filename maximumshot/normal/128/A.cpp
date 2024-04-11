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

string read() {
    char buffer[10];
    gets(buffer);
    return buffer;
}

bool solve()
{
    vec< string > mat(8), mat2;

    for(int i(0);i < 8;i++) {
        mat[i] = read();
    }

    queue< pair<int, int> > q;
    queue<int> dist;

    vec< vec<bool> > used(8, vec<bool>(8, 0));
    vec< vec< vec<bool> > > will(80, vec< vec<bool> >(8, vec<bool>(8, 0)));

    for(int i(0);i < 8;i++) {
        for(int j(0);j < 8;j++) {
            if(mat[i][j] != 'S') continue;
            for(int k(i);k < 8;k++) {
                will[k - i][k][j] = 1;
            }
        }
    }

    used[7][0] = 1;

    q.push(mp(7, 0));
    dist.push(0);

    while(!q.empty()) {
        int vi, vj, d;
        vi = q.front().first;
        vj = q.front().second;
        d = dist.front();
        q.pop();
        dist.pop();

        //cout << vi << ' ' << vj << ' ' << d << " : "; 

        if(vi == 0 && vj == 7) break;

        for(int di(-1);di <= 1;di++) {
            for(int dj(-1);dj <= 1;dj++) {
                int toi = vi + di, toj = vj + dj;
                if(toi < 0 || toi > 7 || toj < 0 || toj > 7) continue;

                if(will[d][toi][toj]) continue;
                if(will[d + 1][toi][toj]) continue;

                if(di == 0 && dj == 0 && d + 1 >= 10) continue;
                if(toi != vi && toj != vj && used[toi][toj]) continue;
                
                q.push(mp(toi, toj));
                dist.push(d + 1);
                used[toi][toj] = 1;
            }
        }

    }

    puts(used[0][7]?"WIN" : "LOSE");

    return true;
}   

int main() 
{
    //while(solve());
    solve();
    
    return 0;
}