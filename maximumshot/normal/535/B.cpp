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

    // 0 : 4
    // 1 : 7
    
    vec<LL> tmp;

    for(int i(0);i <= (1 << 11);i++) {
        LL x = 0;
        for(int j(0);j <= 10;j++) {
            if((1 << j) & i) {
                x = x * 10 + 7;
            }else {
                x = x * 10 + 4;
            }
            tmp.push_back(x);
        }
    }

    sort(ALL(tmp));
    tmp.resize(unique(ALL(tmp)) - tmp.begin());

    for(int i(0);i < (int)tmp.size();i++) {
        if(tmp[i] == n) {
            printf("%d\n", i + 1);
            return true;
        }
    }

    return true;
}   

int main() 
{
    //while(solve());
    solve();
    
    return 0;
}