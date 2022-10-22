#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector

typedef long long LL;
typedef unsigned long long ull;
typedef long double LD;

const LL inf = 1000000000ll;
const LL inf64 = inf * inf;
const LL base = (1ll << 62);    
const double pi = acos(-1.0);

using namespace std;

LL Abs (LL x) {return (x >= 0ll?x : -x);}

bool solve()
{
    int m, t, r;
    
    cin >> m >> t >> r;

    bool used[4000];
    int cnt[4000];

    vec<int> w(m);

    for(int i(0);i < m;i++) cin >> w[i], w[i] += 1000;

    for(int i(0);i < 4000;i++) used[i] = 0, cnt[i] = 0;

    for(int i(0);i < m;i++)
    {
        int I = w[i]; 

        for(int j(0);j < r - cnt[I];j++) 
        {
            if(I - j < 0) break;
            if(used[I - j]) {cout << -1 << '\n'; return true;}
        }

        for(int q(r - cnt[I]), j(0);j < q;j++)
        {
            if(I - j < 0) break;
            used[I - j] = 1;
            for(int z(I - j), c(0);c < t;c++, z++) cnt[z]++;
        }

        if(cnt[I] < r) {cout << -1 << '\n'; return true;}
    }

    int ans = 0;

    for(int i(0);i < 4000;i++) ans += (int)used[i];

    cout << ans << '\n';

    return true;
}

int main()
{
    //while(solve());   
    solve();

    return 0;
}