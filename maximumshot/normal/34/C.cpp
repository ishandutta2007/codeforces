#include <iostream>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <queue>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector

typedef long long LL;
typedef long double LD;
typedef unsigned long long ull;

const LL inf = 1000000000ll;
const LL inf64 = inf * inf;
const double pi = acos(-1.0);
const LL base = inf + 7;

using namespace std;

bool solve()
{
    string a, ans;
    int cur = 0;

    cin >> a;
    a += ',';

    vec< bool > used(1010, 0);

    for(int i(0);i < (int)a.size();i++)
    {
        if(a[i] == ',') used[cur] = 1, cur = 0;
        else cur = cur * 10 + a[i] - '0';
    }

    int l, r, f;
    l = r = f = 0;

    used[1002] = 1;

    for(int i(1);i <= 1002;i++)
    {
        if(!used[i]) continue;
        if(l == 0) l = r = i;   
        else
        {
            if(i == r + 1) r++; 
            else if(l == r)
            {
                if(f) cout << ',';
                else f = 1;
                cout << l;
                l = r = i;
            }else
            {
                if(f) cout << ',';
                else f = 1;
                cout << l << '-' << r;
                l = r = i;
            }
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