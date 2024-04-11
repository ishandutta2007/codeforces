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

const int block_size = 450;

int n, t;
vec< int > a, c;
vec< ll > ans;
ll now = 0;

inline void upd(int value, int k) {
    now += value * (k * 2ll * c[value] + 1);
    c[value] += k;
}

bool cmp(const tuple< int, int, int> & t1, const tuple< int, int, int > & t2) {
    int l1, r1, l2, r2;
    tie(l1, r1, ignore) = t1;
    tie(l2, r2, ignore) = t2;
    return ((l1 - 1) / block_size != (l2 - 1) / block_size?(l1 - 1) / block_size < (l2 - 1) / block_size : 
        r1 < r2);
}

bool solve()
{
    scanf("%d %d", &n, &t);
    a.resize(n + 1);
    ans.resize(t + 1);
    c.resize(1e6 + 10);
    for(int i = 1;i <= n;i++) scanf("%d", &a[i]); 
    vec< tuple< int, int, int > > q;
    for(int l, r, i = 1;i <= t;i++) {
        scanf("%d %d", &l, &r);
        q.push_back(mt(l, r, i));   
    }

    sort(ALL(q), cmp);

    for(int l, r, id, ql = 1, qr = 0, i = 0;i < t;i++) {
        tie(l, r, id) = q[i];
        while(ql < l) upd(a[ql], -1), ql++;
        while(ql > l) upd(a[ql - 1],  1), ql--;
        while(qr < r) upd(a[qr + 1],  1), qr++;
        while(qr > r) upd(a[qr], -1), qr--;
        ans[id] = now;
    }

    for(int i = 1;i <= t;i++) {
        printf("%I64d\n", ans[i]);
    }

    puts("");

    return true;
} 

int main() {
    
    //while(solve());
    solve();    

    return 0;
}