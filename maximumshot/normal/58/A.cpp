#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <algorithm>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector

typedef long long LL;
typedef unsigned long long ull;
typedef long double LD;

const LL inf = 1000000000;
const LL inf64 = inf * inf;
const double pi = acos(-1.0);

LL Abs(LL x) {return (x >= 0?x : -x);}

using namespace std;

bool solve()
{
    string check = "hello";

    int pos = 0;

    string a;

    cin >> a;

    for(int i(0);i < (int)a.size() && pos < (int)check.size();i++)
        if(check[pos] == a[i]) pos++;

    if(pos == (int)check.size()) cout << "YES\n";
    else cout << "NO\n";

    return true;
}
    
int main()
{
    //while(solve());   
    solve();

    return 0;
}