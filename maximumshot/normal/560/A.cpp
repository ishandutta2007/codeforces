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
#include <list>
#include <cstring>

//#include <conio.h>

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
const double pi = acos(-1.0);

using namespace std;

bool solve()
{      
    int n;
    bool ok = 1;
    scanf("%d", &n);

    for(int i = 0;i < n;i++) {
        int x;
        scanf("%d", &x);
        if(x == 1) ok = 0;
    }

    puts(ok?"1":"-1");

    return true;
}   

int main() 
{
    //while(solve());
    solve();

    return 0;
}