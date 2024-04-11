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
typedef long double LD;
typedef unsigned long long ull;

const LL inf = 1000000000;
const LL inf64 = inf * inf;
const double pi = acos(-1.0);
const LL base = inf + 7;

using namespace std;

bool solve()
{
    string a;

    cin >> a;

    int cnt = 0, n = (int)a.size(), cnt2 = 0, C;

    for(int i(0);i < n;i++)
    {
        if(a[i] == '(') cnt++;
        else if(a[i] == ')') cnt--;
        if(cnt < 0) {cout << -1 << '\n'; return true;}
    }

    LL Q;
    C = cnt;
    Q = cnt2 = count(ALL(a), '#');

    if(cnt2 > cnt) {cout << -1 << '\n'; return true;}

    cnt = 0, cnt2 = 0;

    for(int i(0);i < n;i++)
    {
        if(a[i] == '(') cnt2++;
        else if(a[i] == ')') cnt2--;
        else 
        {
            cnt += cnt2;
            cnt2 = 0;
        }
    }

    if(cnt < C) {cout << -1 << '\n'; return true;}

    vec<LL> ans(Q, 1);
    ans.back() += C - Q;

    cnt = 0, cnt2 = 0;

    for(int i(0);i < n;i++)
    {
        if(a[i] == '(') cnt++;
        else if(a[i] == ')') cnt--;
        else cnt -= ans[cnt2++];
        if(cnt < 0) {cout << -1 << '\n'; return true;}
    }

    for(int i(0);i < (int)ans.size();i++) cout << ans[i] << '\n';

    return true;
}

int main()
{
    //while(solve());
    solve();

    return 0;
}