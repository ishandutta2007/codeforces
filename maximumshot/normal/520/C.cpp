#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <fstream>
#include <algorithm>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector

typedef long long LL;
typedef long double LD;

const LL inf = 1000000000ll;
const LL inf64 = inf * inf;
const LL base = inf + 7;

using namespace std;

LL binpow(LL n, LL m)
{
    if(m == 0) return 1ll;

    LL q = binpow(n, m / 2);

    q = (q * q) % base;
    
    if(m % 2) return (q * n) % base;
    else return q;
}


bool solve()
{   
    vec<int> a(26, 0);

    int n;
    string s;

    cin >> n >> s;

    for(int i(0);i < n;i++)
        a[s[i] - 'A']++;

    sort(ALL(a));

    LL ans = 0;

    for(int i(25);i >= 0;i--)
        ans += (a[i] == a.back());
    
    cout << binpow(ans, n) << '\n';

    return true;
}

int main()
{
    //while(solve());
    solve();

    return 0;
}