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
#include <list>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple 

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const ll inf = 1000000000ll;
const ll inf64 = inf * inf;
const ll base = inf + 7;
const ld pi = 3.1415926535897932384626433832795;

bool solve() {
    
    int n;

    scanf("%d", &n);
    
    vec< ll > v(n + 1), d(n + 1), p(n + 1); 

    for(int i = 1;i <= n;i++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        tie(v[i], d[i], p[i]) = mt(x, y, z);
    }

    vec< int > ans;
    vec< bool > inQueue(n + 1, 1);

    for(int i = 1;i <= n;i++) {
        inQueue[i] = 0;
        if(p[i] < 0) {
        }else {
            ans.push_back(i);
            ll delt = 0;
            for(int j = i + 1;j <= n && delt <= v[i];j++) {
                if(!inQueue[j]) continue;
                p[j] -= (v[i] - delt);
                delt++;
            }
            delt = 0;
            for(int j = i + 1;j <= n;j++) {
                if(!inQueue[j]) continue;
                p[j] -= delt;
                if(p[j] < 0) delt += d[j], inQueue[j] = 0;
            }
        }
    }

    int sz = (int)ans.size();

    printf("%d\n", sz);

    for(int i = 0;i < sz;i++) printf("%d ", ans[i]);
    puts("");

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}