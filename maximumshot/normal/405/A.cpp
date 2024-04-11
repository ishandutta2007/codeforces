#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <set>
#include <string>
#include <string>
#include <map>
#include <fstream>
#include <algorithm>

using namespace std;

typedef long long LL;
typedef long double LD;


#define ALL(x) (x).begin(), (x).end()
#define mp make_pair 
#define vec vector

const LL inf = 1000000000ll;
const LL inf64 = inf * inf;

bool solve()
{
    int n;

    cin >> n;

    vec<int> a(n);

    for(int i(0);i < n;i++) cin >> a[i];

    sort(ALL(a));

    for(int i(0);i < n;i++) cout << a[i] << ' ';

    return true;
}

int main()
{
    //while(solve());
    solve();    

    return 0;
}