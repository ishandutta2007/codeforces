/*
    author:     MarX
    school:     UH
*/

//#include <bits/stdc++.h>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <string>
#include <set>
#include <map>

using namespace std;

typedef long long LL;
typedef pair<LL,LL> pii;
typedef vector<LL> vi;
#define oo 1000000000
#define MOD 1000007
#define MAX 350

LL s(LL x)
{
    LL v = 0;
    while (x > 0)
    {
        v += (LL)(x % 10);
        x /= 10;
    }
    return v;
}

LL pow(LL a, LL p)
{
    LL ans = a;
    while (--p)
        ans *= a;
    return ans;
}

vector<LL> sol;

int main()
{
    LL a,b,c; 
    cin >> a >> b >> c;

    for (LL i = 0; i <= 100; ++i)
    {
        LL v = b*pow(i,a) + c;
        if (0 < v && v < 1000000000 && s(v) == i)
            sol.push_back(v);
    }
    sort(sol.begin(),sol.end());
    cout << sol.size() << endl;
    for (LL i = 0; i < sol.size(); ++i)
    {
        cout << sol[i] << " ";/*
        if (i == sol.size() - 1)
            cout << endl;
        else
            cout << " ";*/
    }
}