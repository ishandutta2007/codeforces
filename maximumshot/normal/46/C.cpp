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
const LL base = inf + 7;    
const double pi = acos(-1.0);

using namespace std;

int Abs (int x) {return (x >= 0?x : -x);}

bool solve()
{
    int n;
    string a;

    scanf("%d", &n);
    cin >> a;
    
    int h = count(ALL(a), 'H');

    vec<int> cnt(n);

    cnt[0] = (a[0] == 'T');
    for(int i(1);i < n;i++) cnt[i] = cnt[i - 1] + (a[i] == 'T');

    int ans = inf, tmp;

    for(int i(0);i < n;i++)
    {
        if(i + h <= n)
        {
            // [i .. i + h - 1]
            tmp = cnt[i + h - 1] - (i?cnt[i - 1] : 0);
        }else
        {
            // [0 .. h - n + i - 1] + [i .. n - 1]
            tmp = cnt[h - n + i - 1] + cnt[n - 1] - (i?cnt[i - 1] : 0);
        }
        ans = min(ans, tmp);
    }

    printf("%d\n", ans);

    return true;
}

int main()
{
    //while(solve());   
    solve();

    return 0;
}