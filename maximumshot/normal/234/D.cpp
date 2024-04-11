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
#include <iomanip>

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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int m, k;

    cin >> m >> k;

    vec< int > a(k);
    vec< bool > u(m + 1);
    for(int i = 0;i < k;i++) cin >> a[i], u[a[i]] = 1;

    int n;
    cin >> n;

    vec< vec< int > > act(n); 

    for(int x, i = 0;i < n;i++) {
        string s;
        cin >> s;
        cin >> x;
        act[i].resize(x);
        for(int j = 0;j < x;j++) cin >> act[i][j];
    }

    vec< int > l(n), r(n); 

    for(int i = 0;i < n;i++) {
        int zero = 0;
        int have = 0;
        for(int j = 0;j < (int)act[i].size();j++) {
            if(act[i][j] == 0) zero++;
            if(u[act[i][j]]) have++;
        }
            
        int ost = (int)act[i].size() - zero - have;
        int val = m - k - ost;
        int d = max(0, zero - val);
        // have + d .. min(k, have + zero)
        l[i] = have + d;
        r[i] = min(k, have + zero);
        //cout << i << " : [" << l[i] << " .. " << r[i] << "]\n";
    }

    for(int i = 0;i < n;i++) {
        bool ok = 1;
        for(int j = 0;j < n;j++) {
            if(i == j) continue;
            if(l[i] < r[j]) ok = 0;
        }
        if(ok) {
            puts("0");
            continue;
        }
        ok = 1;
        for(int j = 0;j < n;j++) {
            if(i == j) continue;
            if(r[i] < l[j]) ok = 0;
        }
        if(ok) puts("2");   
        else puts("1");
    }

    return true;
}   

int main() 
{
    //while(solve());
    solve();

    return 0;
}