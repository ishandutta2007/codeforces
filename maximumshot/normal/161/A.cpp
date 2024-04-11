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
    int n, m, x, y;

    scanf("%d %d %d %d", &n, &m, &x, &y);

    vec< pair<int, int> > a(n), b(m);

    for(int v, i = 0;i < n;i++) {
        scanf("%d", &v);
        a[i] = mp(v, i);
    }

    for(int v, i = 0;i < m;i++) {
        scanf("%d", &v);
        b[i] = mp(v, i);
    }

    vec< pair<int, int> > ans;

    sort(ALL(a));
    sort(ALL(b));
    
    int l = 0, r = 0;
    
    while(l < n && r < m) {
        if(a[l].first - x <= b[r].first && b[r].first <= a[l].first + y) {
            ans.push_back(mp(a[l].second, b[r].second));
            l++, r++;
        }else if(b[r].first < a[l].first - x) {
            r++;
        }else l++;
    }

    int sz = (int)ans.size();
    
    printf("%d\n", sz);
    for(auto i : ans) printf("%d %d\n", i.first + 1, i.second + 1); 

    return true;
}  

int main() 
{
    //while(solve());
    solve();
    
    return 0;
}