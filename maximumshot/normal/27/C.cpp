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
typedef pair<int, int> pii;
 
const LL inf = 1000000000ll;
const LL inf64 = inf * inf;
const LL base = inf + 7;
 
LL Abs(LL x) {return (x >= 0?x : -x);}

bool solve()
{
    int n;

    scanf("%d", &n);

    vec<int> a, lmn, rmn, lmx, rmx;

    a = lmn = rmn = lmx = rmx = vec<int>(n + 1);

    for(int i(1);i <= n;i++) scanf("%d", &a[i]);

    lmn[1] = lmx[1] = 1; 

    for(int i(2);i <= n;i++)
    {
        if(a[i] > a[lmx[i - 1]]) lmx[i] = i;
        else lmx[i] = lmx[i - 1];
        if(a[i] < a[lmn[i - 1]]) lmn[i] = i;
        else lmn[i] = lmn[i - 1];
    }

    rmn[n] = rmx[n] = n;

    for(int i(n - 1);i >= 1;i--)
    {
        if(a[i] > a[rmx[i + 1]]) rmx[i] = i;
        else rmx[i] = rmx[i + 1];
        if(a[i] < a[rmn[i + 1]]) rmn[i] = i;
        else rmn[i] = rmn[i + 1];
    }

    for(int i(2);i < n;i++)
    {
        if(a[i] > a[lmn[i - 1]] && a[i] > a[rmn[i + 1]])
        {
            puts("3");
            printf("%d %d %d\n", lmn[i - 1], i, rmn[i + 1]);
            return true;
        }

        if(a[i] < a[lmx[i - 1]] && a[i] < a[rmx[i + 1]])
        {
            puts("3");
            printf("%d %d %d\n", lmx[i - 1], i, rmx[i + 1]);
            return true;
        }

    }

    puts("0");

    return true;
}

int main()
{
    //while(solve());
    solve();
 
    return 0;
}