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
    set< int > s, x;
    vec< pair<char, int> > a(n);
    for(int i = 0;i < n;i++) {
        cin >> a[i].first >> a[i].second;
        if(a[i].first == '-' && s.count(a[i].second) == 0) {
            x.insert(a[i].second);
        }else if(a[i].first == '+') {
            s.insert(a[i].second);
        }
    }

    int ans = (int)x.size();
    s.clear();
    s = x;

    for(int i = 0;i < n;i++) {
        if(a[i].first == '+') {
            s.insert(a[i].second);
        }else {
            s.erase(a[i].second);
        }
        ans = max(ans, (int)s.size());
    }

    cout << ans << '\n';

    return true;
}   

int main() 
{
    //while(solve());
    solve();

    return 0;
}