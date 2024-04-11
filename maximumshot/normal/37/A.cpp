#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <algorithm>
#include <queue>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector

typedef long long LL;
typedef unsigned long long ull;
typedef long double LD;

const LL inf = 1000000000ll;
const LL inf64 = inf * inf;
const LL base = inf + 7;    
const double pi = acos(-1.0);

using namespace std;

int Abs(int x) {return (x >= 0?x : -x);}

bool solve()
{
    int n;

    cin >> n;
    
    map<int, int> C;
    set<int> s;

    for(int x, i(0);i < n;i++)
    {
        cin >> x;
        C[x]++;
        s.insert(x);
    }

    int ans = 1;

    for(set<int>::iterator i = s.begin();i != s.end();i++) ans = max(ans, C[*i]);

    cout << ans << ' ' << (int)s.size() << '\n';

    return true;
}

int main()
{
    //while(solve());   
    solve();

    return 0;
}