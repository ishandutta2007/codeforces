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

bool solve()
{
    int n;
    LL x;

    cin >> n;

    vec<LL> a[2];
    LL sum[2] = {0};

    bool last;

    for(int i(0);i < n;i++)
    {
        cin >> x;
        a[x < 0].push_back((x > 0?x : -x));
        sum[x < 0] += (x > 0?x : -x);
        if(i == n - 1) last = (x < 0);
    }

    if(sum[0] > sum[1]) {cout << "first\n";return true;}
    if(sum[0] < sum[1]) {cout << "second\n";return true;}
    
    if((int)a[0].size() == (int)a[1].size())
    {
        for(int i(0);i < (int)a[0].size();i++)
        {
            if(a[0][i] > a[1][i]) {cout << "first\n";return true;}
            if(a[0][i] < a[1][i]) {cout << "second\n";return true;}
        }
        if(last) cout << "second\n";
        else cout << "first\n";
    }else
    {
        for(int i(0);i < (int)min(a[0].size(), a[1].size());i++)
        {
            if(a[0][i] > a[1][i]) {cout << "first\n";return true;}
            if(a[0][i] < a[1][i]) {cout << "second\n";return true;}
        }
        if(a[0].size() > a[1].size()) cout << "first\n";
        else cout << "second\n";
    }

    return true;
}

int main()
{
    //while(solve());
    solve();

    return 0;
}