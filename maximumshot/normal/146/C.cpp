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

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define vec vector
#define mp make_pair
#define close() puts("Ok!\n"); return true;

typedef long long LL;
typedef long double LD;

const LL inf = 1000000000ll;
const LL inf64 = inf * inf;

const LL N = 100100;

LL getmask(LL x)
{
    vec<LL> a;

    while(x)
    {
        if(x % 10 == 4 || x % 10 == 7) a.push_back(x % 10);
        x /= 10;
    }

    reverse(ALL(a));

    LL ans = 0;

    for(int i(0);i < (int)a.size();i++) ans = ans * 10 + a[i];

    return ans;
}

bool solve()
{
    string a, b;

    cin >> a >> b;

    LL c1, c2;

    c1 = c2 = 0;

    for(int i(0);i < (int)a.size();i++)
    {
        if(a[i] == b[i]) continue;
        if(a[i] == '4') c1++;
        else c2++;
    }
    
    cout << max(c1, c2);

    return true;
}

int main()
{
    //while(solve());
    solve();

    return 0;
}