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
#include <stack>
 
using namespace std;
 
#define ALL(x) (x).begin(), (x).end()
#define vec vector
#define mp make_pair
#define close() puts("NO"); return true;
 
typedef long long LL;
typedef long double LD;
typedef pair<int, int> pii;
 
const LL inf = 1000000000ll;
const LL inf64 = inf * inf;
const LL base = inf + 7;
const double pi = acos(-1.0); 

LL Abs(LL x) {return (x >= 0?x : -x);}

bool solve()
{
    string s;

    cin >> s;

    map<char, int> C;
    C['I'] = C['E'] = C['A'] = C['O'] = C['U'] = C['Y'] = 1;

    int n = (int)s.size();

    vec<int> a(n + 1), sum(n + 1, 0);

    for(int i(0);i < n;i++) a[i + 1] = C[s[i]]; 
    for(int i(1);i <= n;i++) sum[i] = sum[i - 1] + a[i];

    LD ans = 0.0;
    LD sm = sum[n];

    for(int i(1);i <= n;i++)
    {
        ans += sm / LD(i);
        sm += sum[n - i] - sum[i];
    }

    cout.precision(25);

    cout << ans << '\n';

    return true;
}

int main()
{
    //while(solve());
    solve();
 
    return 0;
}