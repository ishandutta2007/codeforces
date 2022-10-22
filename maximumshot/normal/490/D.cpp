#include <iostream>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <stdio.h>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector

typedef long long LL;

const LL inf = 1000000000;
const LL inf64 = inf * inf;
const double pi = acos(-1.0);

using namespace std;

map<LL, LL> factorize(LL x)
{
    vec<LL> ans;
    bool f = 1;

    while(f)
    {
        f = 0;

        for(LL i(2);i * i <= x;i++)
        {
            if(x % i == 0)
            {
                f = 1;
                ans.push_back(i);
                x /= i;
                break;
            }
        }
    }
    ans.push_back(x);

    map<LL, LL> C;

    for(int i(0);i < (int)ans.size();i++) C[ans[i]]++;
    
    return C;
}

bool solve()
{
    LL a1, a2, b1, b2;

    cin >> a1 >> b1 >> a2 >> b2;

    if(a1 * b1 == a2 * b2) {cout << 0 << '\n' << a1 << ' ' << b1 << '\n' << a2 << ' ' << b2 << '\n';return true;}

    map<LL, LL> c1, c2, all;

    c1 = factorize(a1 * b1);
    c2 = factorize(a2 * b2);

    for(map<LL, LL>::iterator i = c1.begin();i != c1.end();i++)
    {
        LL x, y;
        x = i->first;
        y = i->second;

        //cout << x << ' '; 

        if(x != 1 && x != 2 && x != 3 && y != c2[x]) {cout << -1 << '\n';return true;}
    }

    //cout << '\n';

    for(map<LL, LL>::iterator i = c2.begin();i != c2.end();i++)
    {
        LL x, y;
        x = i->first;
        y = i->second;

        //cout << x << ' ';

        if(x != 1 && x != 2 && x != 3 && y != c1[x]) {cout << -1 << '\n';return true;}
    }

    //cout << "\n\n";

    LL two, three;

    c1[2] += c1[3];
    c2[2] += c2[3];

    two = abs(c1[2] - c2[2]);
    three = abs(c1[3] - c2[3]);
    
    cout << two + three << '\n';

    if(c1[2] < c2[2]) c2[2] -= c1[2], c1[2] = 0;
    else c1[2] -= c2[2], c2[2] = 0;

    if(c1[3] < c2[3]) c2[3] -= c1[3], c1[3] = 0;
    else c1[3] -= c2[3], c2[3] = 0;

    while(c1[3])
    {
        if(a1 % 3 == 0) a1 = a1 * 2 / 3;
        else b1 = b1 * 2 / 3;
        c1[3]--;
    }

    while(c1[2])
    {
        if(a1 % 2 == 0) a1 /= 2;
        else b1 /= 2;
        c1[2]--;
    }

    while(c2[3])
    {
        if(a2 % 3 == 0) a2 = a2 * 2 / 3;
        else b2 = b2 * 2 / 3;
        c2[3]--;
    }

    while(c2[2])
    {
        if(a2 % 2 == 0) a2 /= 2;
        else b2 /= 2;
        c2[2]--;
    }

    cout << a1 << ' ' << b1 << '\n';
    cout << a2 << ' ' << b2 << '\n';

    return true;
}

int main()
{
    //while(solve());
    solve();

    return 0;
}