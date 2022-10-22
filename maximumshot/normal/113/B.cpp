// by maximumSHOT
#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <string>
#include <fstream>
#include <stdio.h>
 
using namespace std;
 
#define ALL(x) (x).begin(), (x).end()
#define vec vector
#define mp make_pair
#define close() puts("Ok!\n"); return true;
 
typedef long long LL;
typedef long double LD;
typedef pair<int, int> pii;
 
const LL inf = 1000000000ll;
const LL inf64 = inf * inf;
const LL base = inf + 7;
 
LL Abs(LL x) {return (x >= 0?x : -x);}

const LL p = 157;

LL w[2100];

bool solve()
{
    w[0] = 1ll;
    for(int i(1);i < 2100;i++) w[i] = w[i - 1] * p;

    string t, a, b;

    cin >> t >> a >> b;

    int n, m, k, len;

    n = (int)t.size();
    m = (int)a.size();
    k = (int)b.size();

    LL l, r, mb, ans = 0;

    l = r = 0;

    for(int i(0);i < m;i++) l += a[i] * w[i];
    for(int i(0);i < k;i++) r += b[i] * w[i];

    vec<LL> hash(n);

    hash[0] = t[0];
    for(int i(1);i < n;i++) hash[i] = hash[i - 1] + t[i] * w[i];

    vec<LL> s;

    for(int i(0);i < n - m + 1;i++)
    {
        mb = hash[i + m - 1] - (i?hash[i - 1] : 0);
        if(mb != l * w[i]) continue;
        for(int j(i + max(m, k) - 1);j < n;j++)
        {
            mb = hash[j] - (j - k + 1?hash[j - k] : 0);
            if(mb != r * w[j - k + 1]) continue;
            s.push_back(w[n - i] * (hash[j] - (i?hash[i - 1] : 0)));
        }
    }

    sort(ALL(s));

    ans = unique(ALL(s)) - s.begin();

    printf("%I64d\n", ans);

    return true;
}

int main()
{
    //while(solve());
    solve();
 
    return 0;
}