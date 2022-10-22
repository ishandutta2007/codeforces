#include <iostream>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <stdio.h>
#include <algorithm>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector

typedef long long LL;
typedef unsigned long long ull;

const LL inf = 1000000000;
const LL inf64 = inf * inf;
const double pi = acos(-1.0);
const LL base = inf + 7;

using namespace std;

LL binpow(LL n, LL m, LL p)
{
    if(m == 0) return (1 % p);
    
    LL q = binpow(n, m / 2, p);
    q = (q * q) % p;

    if(m % 2)
        return (q * n) % p;
    else
        return q;
}

bool solve()
{
    string s;
    cin >> s;
    int n = (int)s.size();

    LL a, b;

    cin >> a >> b;

    vec<LL> l(n), r(n);

    l[0] = (s[0] - '0') % a;

    for(int i(1);i < n;i++)
        l[i] = (l[i - 1] * 10 + (s[i] - '0')) % a;

    r[n - 1] = (s[n - 1] - '0') % b;

    LL mn = 10;

    for(int i(n - 2);i >= 0;i--)
    {
        r[i] = binpow(10, n - 1 - i, b) * (s[i] - '0') % b;
        r[i] = (r[i] + r[i + 1]) % b;
    }
    
    for(int i(0);i < n - 1;i++)
    {
        if(s[i + 1] == '0') continue;
        if(l[i] == 0 && r[i + 1] == 0)
        {
            cout << "YES\n";
            for(int j(0);j <= i;j++) cout << s[j];
            cout << '\n';
            for(int j(i + 1);j < n;j++) cout << s[j];
            return true;
        }
    }

    cout << "NO\n";

    return true;
}

int main()
{
    //while(solve());
    solve();

    return 0;
}