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

    int n, k;

    cin >> n >> k;

    vec< pair<int, int> > a(n);
    for(int i = 0;i < n;i++) cin >> a[i].first, a[i].second = i + 1;

    sort(a.rbegin(), a.rend());
    
    cout << a[k - 1].first << '\n';
    for(int i = 0;i < k;i++) cout << a[i].second << ' ';
    cout << '\n';

    return true;
}   

int main() 
{
    //while(solve());
    solve();

    return 0;
}