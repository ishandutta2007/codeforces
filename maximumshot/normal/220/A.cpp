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
    int n, c = 0;

    scanf("%d", &n);

    vec<int> a(n), b(n);

    for(int i(0);i < n;i++) scanf("%d", &a[i]);
    b = a;
    
    sort(ALL(b));

    for(int i(0);i < n;i++) c += (a[i] != b[i]);

    puts(c <= 2?"YES" : "NO");

    return true;
}

int main()
{
    //while(solve());   
    solve();

    return 0;
}