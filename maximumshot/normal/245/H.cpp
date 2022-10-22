#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <algorithm>
#include <queue>

#include <conio.h>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector

typedef long long LL;
typedef unsigned long long ull;
typedef long double LD;

const LL inf = 1000000000ll;
const LL inf64 = inf * inf;
const LL base = (1ll << 62);    
const double pi = acos(-1.0);

using namespace std;

int Abs (int x) {return (x >= 0?x : -x);}

const LL p = 157;

LL pw[5050];
int ans[5050][5050];

void init()
{
    pw[0] = 1;

    for(int i(1);i < 5050;i++) pw[i] = pw[i - 1] * p;
}

bool solve()
{   
    init(); 
    string a;
    for(int i(0);i < 5050;i++) for(int j(0);j < 5050;j++) ans[i][j] = 0;

    cin >> a;

    a = '#' + a;

    int n = (int)a.size() - 1;
    LL l, r;

    for(int i(1);i <= n;i++)
    {
        l = r = 0;

        for(int j(i);j <= n;j++)
        {
            ans[i][j] = ans[i][j - 1];

            l += a[j] * pw[j - i];
            r = a[j] + p * r;

            if(l == r) ans[i][j]++;
        }
    }

    for(int i(1);i <= n;i++)
        for(int j(i - 1);j >= 1;j--)
            ans[j][i] += ans[j + 1][i];
    
    int q;

    scanf("%d", &q);

    while(q--)
    {
        scanf("%d %d", &l, &r);
        printf("%d\n", ans[l][r]);
    }

    return true;
}

int main()
{
    //while(solve());   
    solve();

    return 0;
}