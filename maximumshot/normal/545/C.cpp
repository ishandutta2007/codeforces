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
const LL base = inf * 1000ll + 17;
const LL MOD = inf + 9;
const double pi = acos(-1.0);

using namespace std;

template<typename T, typename P>
const ostream & operator << (ostream & os, const pair<T, P> & a) {
    os.precision(10);
    os << fixed;
    os << a.first;
    os << ' ';
    os << a.second;
    os << '\n';
    return os;
}

bool solve()
{
    int n;

    scanf("%d", &n);

    if(n == 1) {
        puts("1");
        return true;
    }

    vec< pair<int, int> > a(n);

    for(int x, h, i(0);i < n;i++) {
        scanf("%d %d", &x, &h);
        a[i] = mp(x, h);
    }

    int ans = 1, last = a[0].first;

    for(int i(1);i < n - 1;i++) {
        if(a[i].first - a[i].second > last) {
            ans++;
            last = a[i].first;
        }else if(a[i].first + a[i].second < a[i + 1].first) {
            ans++;
            last = a[i].first + a[i].second;
        }else {
            last = a[i].first;
        }
    }

    ans++;

    printf("%d\n", ans);

    return true;
}   

int main() 
{
    //while(solve());
    solve();

    return 0;
}