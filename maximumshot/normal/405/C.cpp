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
    int n, tmp;

    scanf("%d", &n);

    int mat[1010][1010];

    for(int i(0);i < n;i++) for(int j(0);j < n;j++)scanf("%d", &mat[i][j]);

    int ans = 0;

    for(int i(0);i < n;i++)
        for(int j(0);j < n;j++)
            ans = (ans + (mat[i][j] * mat[j][i])) % 2; 
    
    int q, type, x;

    scanf("%d", &q);

    while(q--)
    {
        scanf("%d", &type);

        if(type == 3) printf("%d", ans);
        else
        {
            scanf("%d", &x);
            ans = !ans;
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