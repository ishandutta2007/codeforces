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
    int n, k;

    scanf("%d %d", &n, &k);

    vec< pair<int, int> > a, b;
    
    for(int i = 0;i < n;i++) {
        int c, t;
        scanf("%d %d", &c, &t);
        if(t == 1) a.push_back(mp(c, i + 1));
        else b.push_back(mp(c, i + 1));
    }

    sort(ALL(a));
    sort(ALL(b));

    reverse(ALL(a));
    reverse(ALL(b));

    vec< vec< pair< pair<int, int>, int> > > ans(k);

    int sa = (int)a.size();
    int sb = (int)b.size();

    int j = 0;

    for(int i = 0;i < sa;i++, j = min(j + 1, k - 1)) {
        int c = a[i].first;
        int id = a[i].second;
        ans[j].push_back(mp(mp(c, 1), id));
    }

    for(int i = 0;i < sb;i++, j = min(j + 1, k - 1)) {
        int c = b[i].first;
        int id = b[i].second;
        ans[j].push_back(mp(mp(c, 2), id));
    }

    LD val = 0.0;

    for(int i = 0;i < k;i++) {
        sort(ALL(ans[i]));
        bool have = 0;
        int mn = inf + 10;
        for(int j = 0;j < (int)ans[i].size();j++) {
            int type = ans[i][j].first.second;
            if(type == 1) have = 1;
            int c = ans[i][j].first.first;
            mn = min(mn, c);
            val += c;
        }
        if(have) val -= (LD)mn / 2;
    }

    cout.precision(1);
    cout << fixed;

    cout << val << '\n';

    for(int i = 0;i < k;i++) {
        cout << (int)ans[i].size() << " ";
        for(int j = 0;j < (int)ans[i].size();j++) {
            int id = ans[i][j].second;
            cout << id << ' ';
        }
        cout << '\n';
    }

    return true;
}  

int main() 
{
    //while(solve());
    solve();
    
    return 0;
}