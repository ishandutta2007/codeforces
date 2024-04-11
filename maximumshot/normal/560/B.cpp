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

int a1, b1;
int a2, b2, a3, b3;

bool check() {
    if(a2 > a1 || b2 > b1) return 0;
    int x, y;
    x = b1 - b2;
    y = a1;
    bool ok = 0;
    if(b3 <= x && a3 <= y) ok = 1;
    x = b1;
    y = a1 - a2;
    if(b3 <= x && a3 <= y) ok = 1;
    return ok;
}

bool solve()
{      
    cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;

    bool ok = 0;

    for(int i = 0;i < 2;i++) {
        for(int j = 0;j < 2;j++) {
            ok |= check();
            swap(a3, b3);
        }
        swap(a2, b2);
    }

    puts(ok?"YES" : "NO");

    return true;
}   

int main() 
{
    //while(solve());
    solve();

    return 0;
}