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

const int NMAX = 2e6;
bool prime[NMAX];

bool check(int x) {
    vec< int > a;
    while(x) a.push_back(x % 10), x /= 10;
    int sz = (int)a.size();
    for(int i = 0;i < sz;i++) {
        if(a[i] != a[sz - 1 - i]) return 0;
    }
    return 1;
}

bool solve()
{
    int p, q;
    cin >> p >> q;

    for(int i = 0;i < NMAX;i++) prime[i] = 1;
    prime[0] = prime[1] = 0; 

    for(int i = 2;i * i < NMAX;i++) {
        if(!prime[i]) continue;
        for(int j = i * i;j < NMAX;j += i) prime[j] = 0;
    }

    vec< int > c1(NMAX, 0), c2(NMAX, 0);
    for(int i = 1;i < NMAX;i++) {
        c1[i] = c1[i - 1] + prime[i];
        c2[i] = c2[i - 1] + check(i);
    }

    int ans = 0;

    /*for(int i = 0;i < 41;i++) cout << c1[i] << ' ';
    cout << '\n';
    for(int i = 0;i < 41;i++) cout << c2[i] << ' ';
    cout << '\n';*/

    /*for(int i = 0;i < 100;i++) cout << c1[i] << ' ';
    cout << '\n';*/

    for(int i = 0;i < NMAX;i++) {
        LL d1 = LL(q) * LL(c1[i]);
        LL d2 = LL(p) * LL(c2[i]);
        if(d1 <= d2) ans = max(ans, i);
    }

    if(ans == NMAX - 1) cout << "Palindromic tree is better than splay tree\n";
    else cout << ans << '\n';

    return true;
}   

int main() 
{
    //while(solve());
    solve();

    return 0;
}