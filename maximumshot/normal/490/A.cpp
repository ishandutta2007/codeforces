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
#include <stdio.h>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector

typedef long long LL;
typedef long double LD;

const LL inf = 1000000000;
const LL inf64 = inf * inf;
const double pi = acos(-1.0);
const LL base = 1000000007;

using namespace std;

bool solve()
{
    int n, x;

    cin >> n;

    vec<int> a[3];

    for(int i(0);i < n;i++)
    {
        cin >> x;
        a[x - 1].push_back(i + 1);
    }

    int s1, s2, s3;

    s1 = (int)a[0].size();
    s2 = (int)a[1].size();
    s3 = (int)a[2].size();

    int ans = min(min(s1, s2), s3);
    
    cout << ans << '\n';

    for(int i(0);i < ans;i++)
        cout << a[0][i] << ' ' << a[1][i] << ' ' << a[2][i] << '\n';
    
    return true;
}

int main()
{
    //while(solve());
    solve();

    return 0;
}