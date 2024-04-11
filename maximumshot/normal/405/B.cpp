// by maximumSHOT
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
#include <stdio.h>
 
using namespace std;
 
#define ALL(x) (x).begin(), (x).end()
#define vec vector
#define mp make_pair
#define close() puts("Ok!\n"); return true;
 
typedef long long LL;
typedef long double LD;
 
const LL inf = 1000000000ll;
const LL inf64 = inf * inf;
const LL base = inf + 7;
 
LL Abs(LL x) {return (x >= 0?x : -x);}

bool solve()
{
    int n;

    cin >> n;

    string a;

    cin >> a;

    int ans = 0;

    if(find(ALL(a), 'L') == a.end() && find(ALL(a), 'R') == a.end()) {cout << n << '\n'; return true;}

    for(int i(0);i < n;i++)
    {
        if(a[i] != '.') continue;
        int l, r;
        l = r = 0;
        for(int j(i - 1);j >= 0 && a[j] == '.';j--) l++;
        for(int j(i + 1);j <  n && a[j] == '.';j++)  r++;
    
        if(i + r + 1 < n && l == i && a[i + r + 1] == 'R') ans++;
        else if(i - l - 1 >= 0 && i + r == n - 1 && a[i - l - 1] == 'L') ans++;
        else if(i - l - 1 >= 0 && i +r + 1 < n && a[i - l - 1] == 'L' && a[i + r + 1] == 'R') ans++;
        else if(i - l - 1 >= 0 && i + r + 1 < n && l == r && a[i - l - 1] == 'R' && a[i + r + 1] == 'L') ans++;
    }

    cout << ans << '\n';

    return true;
}
 
int main()
{
    //while(solve());
    solve();
 
    return 0;
}