#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple 

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const ll inf = 1000000000ll;
const ll inf64 = inf * inf;
const ll base = inf + 7;
const ld pi = acos(-1.0);

const int delt = 100100;

bool solve()
{
    int n;

    scanf("%d", &n);

    vec< tuple< int, int, int> > a(n);
    // {y - x, x, y}

    for(int x, y, i = 0;i < n;i++) {
        scanf("%d %d", &x, &y);
        a[i] = mt(y - x, x, y);
    }

    vec< vec< int > > w(delt * 2);
    vec< pair< int, int > > ans(n);

    for(int x, i = 0;i < n;i++) {
        scanf("%d", &x);
        w[x + delt].push_back(i);
    }

    sort(ALL(a));

    for(int i = 0;i < n;i++) {
        int j = i, need_value;
        tie(need_value, ignore, ignore) = a[i];
        while(j < n) {
            int value;
            tie(value, ignore, ignore) = a[j];
            if(value != need_value) break;
            else j++;
        }
        j--;
        // [i .. j]
        if((int)w[need_value + delt].size() != j - i + 1) {
            puts("NO");
            return true;
        }
        for(int it = 0;it < (int)w[need_value + delt].size();it++) {
            int id = w[need_value + delt][it];
            int x, y;
            tie(ignore, x, y) = a[i + it];
            ans[id] = mp(x, y);
        }
        i = j;
    }

    vec< vec< pair< int, int> > > X(delt * 2), Y(delt * 2);

    for(int i = 0;i < n;i++) {
        X[ans[i].first].push_back(mp(ans[i].second, i));
        Y[ans[i].second].push_back(mp(ans[i].first, i));
    }

    for(int i = 0;i < (int)X.size();i++) {
        sort(ALL(X[i]));
        for(int j = 0;j + 1 < (int)X[i].size();j++) {
            if(X[i][j + 1].second < X[i][j].second) {
                puts("NO");
                return true;
            }
        }
    }

    for(int i = 0;i < (int)Y.size();i++) {
        sort(ALL(Y[i]));
        for(int j = 0;j + 1 < (int)Y[i].size();j++) {
            if(Y[i][j + 1].second < Y[i][j].second) {
                puts("NO");
                return true;
            }
        }
    }
    puts("YES");

    for(int i = 0;i < n;i++) printf("%d %d\n", ans[i].first, ans[i].second);

    return true;
} 

int main() {
    
    //while(solve());
    solve();    

    return 0;
}