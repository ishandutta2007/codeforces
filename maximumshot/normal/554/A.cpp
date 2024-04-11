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
    set< string > s;    

    string a;
    cin >> a;

    for(char z = 'a';z <= 'z';z++) s.insert(z + a), s.insert(a + z);

    for(int i = 0;i + 1 < (int)a.size();i++) {
        string x, y;
        x = y = "";
        for(int j = 0;j <= i;j++) x += a[j];
        for(int j = i + 1;j < (int)a.size();j++) y += a[j];
        for(char z = 'a';z <= 'z';z++) s.insert(x + z + y);
    }

    cout << (int)s.size() << '\n';

    return true;
}   

int main() 
{
    //while(solve());
    solve();

    return 0;
}