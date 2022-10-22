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

    int n;

    cin >> n;

    int q = 0;
    while((1 << q) < n) q++;

    cout << q << '\n';

    for(int j = 0;j < q;j++) {
        int c = 0;
        for(int i = 0;i < n;i++) {
            if((1 << j) & i) c++;
        }
        cout << c << ' ';
        for(int i = 0;i < n;i++) {
            if((1 << j) & i) cout << i + 1 << ' ';
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