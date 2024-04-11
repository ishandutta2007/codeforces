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
#include <time.h>

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
const LL MOD = inf + 7;
const double pi = acos(-1.0);

using namespace std;

bool solve()
{
    int n;
    cin >> n;
    vec< int > a(n);
    for(int i = 0;i < n;i++) cin >> a[i];

    for(int i = 0;i < n;i++) {
        int mn = inf * 2 + 10;
        int mx = 0;
        if(i > 0) {
            mn = min(mn, a[i] - a[i - 1]);
            mx = max(mx, a[i] - a[0]);
        }
        if(i + 1 < n) {
            mn = min(mn, a[i + 1] - a[i]);
            mx = max(mx, a[n - 1] - a[i]);
        }
        cout << mn << ' ' << mx << '\n'; 
    }

    return true;
}   

int main() 
{
    //while(solve());
    solve();

    return 0;
}