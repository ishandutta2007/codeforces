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

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector

typedef long long LL;
typedef unsigned long long ull;
typedef long double LD;

const LL inf = 1000000000;
const LL inf64 = inf * inf;
const LL base = inf + 7;    
const double pi = acos(-1.0);

using namespace std;

bool solve()
{
    string a, b = "aoyeui", c = "";

    cin >> a;

    for(int i(0);i < (int)a.size();i++) if(a[i] >= 'A' && a[i] <= 'Z') a[i] = a[i] - 'A' + 'a';

    for(int i(0);i < (int)a.size();i++) if(find(ALL(b), a[i]) == b.end()) c += a[i];

    for(int i(0);i < (int)c.size();i++) cout << '.' << c[i];

    return true;
}

int main()
{
    //while(solve());   
    solve();

    return 0;
}