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
    int n, k;

    scanf("%d %d", &n, &k);

    vec<int> a(2 * n);
    
    int s1, s2;
    s1 = s2 = 0;

    if(k != 0)
    {
        for(int i(1);i < 2 * n - k;i++) a[i - 1] = i;
        for(int i(2 * n - k - 1);i < 2 * n - 1;i++) a[i] = i + 2;
        a.pop_back();
        a.push_back(2 * n - k);
    }else for(int i(0);i < 2 * n;i++) a[i] = i + 1;

    for(int i(0);i < 2 * n;i += 2) s1 += Abs(a[i] - a[i + 1]), s2 += a[i] - a[i + 1];

    for(int i(0);i < 2 * n;i++) printf("%d ", a[i]);
    
    return true;
}

int main()
{
    //while(solve());   
    solve();

    return 0;
}