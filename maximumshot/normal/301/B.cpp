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
const LL base = inf + 7;
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
    os << ' ';
    return os;
}

int n, d;
vec<int> a;
vec< pair<int, int> > crd;

bool check(LL x) {
    vec<LL> mx(n + 1, -1);
    queue<int> q;
    mx[1] = x;
    q.push(1);
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for(int i(2);i <= n;i++) {
            if(v == i) continue;
            LL dist = abs(crd[i].first - crd[v].first) + abs(crd[i].second - crd[v].second);
            dist *= d;
            if(dist > mx[v]) continue;
            LL tmp = mx[v] - dist + a[i];
            if(tmp > mx[i]) {
                mx[i] = tmp;
                q.push(i);
            }
        }
    }

    return (mx[n] >= 0);
}

bool solve()
{
    scanf("%d %d", &n, &d);

    a.resize(n + 1);
    for(int i(2);i <= n - 1;i++) {
        scanf("%d", &a[i]);
    }

    crd.resize(n + 1);

    for(int i(1);i <= n;i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        crd[i] = mp(x, y);
    }

    LL left, right, mid;

    left = 0, right = inf;

    while(right - left > 1) {
        mid = (left + right) >> 1;
        if(check(mid)) right = mid;
        else left = mid + 1;
    }

    printf("%d\n", check(left)?left : right);

    return true;
}   

int main() 
{
    //while(solve());
    solve();
    
    return 0;
}