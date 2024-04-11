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

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector
#define deb(x) cerr << #x << " = " << x << '\n';

typedef unsigned long long ull;
typedef long double LD;
typedef long long LL;

const LL inf = 1000000000ll;
const LL inf64 = 1ll * inf * inf;
const LL base = inf + 7;
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

    cin >> n;

    vec< pair<int, int> > a(n);

    for(int x, i(0);i < n;i++) {
        cin >> x;
        a[i] = mp(x, i);
    }

    sort(ALL(a));
    reverse(ALL(a));

    vec< int > ans(n);

    int pos = 1;

    for(int i(0);i < n;i++) {
        if(i && a[i].first < a[i - 1].first) pos = i + 1;
        ans[a[i].second] = pos;
    }

    for(int i(0);i < n;i++) cout << ans[i] << ' ';
 
    return true;
}   

int main()  
{
    //while(solve());   
    solve();

    return 0;
}