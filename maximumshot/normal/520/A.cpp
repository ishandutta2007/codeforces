#include <iostream>
#include <stdio.h>
#include <cmath>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair 
#define vec vector

typedef long long LL;
typedef long double LD;

const LL inf = 1000000000ll;
const LL inf64 = inf * inf;

bool solve()
{
    vec<bool> used(26, 0);

    int n;
    string a;

    cin >> n >> a;

    for(int i(0);i < n;i++) used[a[i] >= 'a' && a[i] <= 'z'?a[i] - 'a' : a[i] - 'A'] = 1;

    puts(find(ALL(used), false) != used.end()?"NO" : "YES");

    return true;
}

int main()
{
    //while(solve());
    solve();

    return 0;
}