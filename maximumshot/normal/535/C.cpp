#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector
#define deb(x) cerr << #x << " = " << x << '\n';

typedef unsigned long long ull;
typedef long double LD;
typedef long long LL;

const LL inf = 1000000000ll;
const LL inf64 = inf * inf;
const LL base = inf + 7;
const LL MOD = inf + 9;
const double pi = acos(-1.0);

using namespace std;

LL l, t, m;
LL A, B;

LL get(LL id) {
    return (A + (id - 1) * B);
}

bool check(LL x) {
    // [l .. x]

    int len = x - l + 1;

    if(len <= m) {
        return (get(x) <= t);
    }

    if(get(x) > t) return 0;

    LL sum = (get(l) + get(x)) * (LL)len / 2;

    if(sum <= t * m) return 1;
    else return 0;
}

void make() {
    scanf("%I64d %I64d %I64d", &l, &t, &m);

    LL tl, tr, tm;
    tl = l, tr = inf;

    while(tr - tl > 1) {
        tm = (tl + tr) >> 1;
        if(check(tm)) tl = tm;
        else tr = tm - 1;
    }  

    if(check(tr)) printf("%I64d\n", tr);
    else if(check(tl)) printf("%I64d\n", tl);
    else puts("-1");
}

bool solve()
{
    scanf("%I64d %I64d", &A, &B);

    int n;

    scanf("%d", &n);

    while(n--) {
        make(); 
    }

    return true;
}   

int main() 
{
    //while(solve());
    solve();

    return 0;
}