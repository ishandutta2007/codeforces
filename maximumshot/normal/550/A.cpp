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

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector
#define deb(x) cerr << #x << " = " << x << '\n';

typedef unsigned long long ull;
typedef long double LD;
typedef long long LL;

const int inf = 1000000000ll;
const LL inf64 = 1ll * inf * inf;
const LL base = inf + 7;
const double pi = acos(-1.0);

using namespace std;

template<typename T, typename P>
const ostream & operator << (ostream & os, const pair<T, P> & a) {
    os.precision(10);
    os << fixed;
    os << a.first;
    os << ' ';
    os << a.second;
    os << '\n';
    return os;
}

bool solve() 
{
    string s;

    cin >> s;

    int n = (int)s.size();

    vec<int> a(n), b(n);

    for(int i(0);i < (int)s.size();i++) {
        if(s.substr(i, 2) == "AB") a[i]++;
        else if(s.substr(i, 2) == "BA") b[i]++;
    }

    for(int i(1);i < n;i++) {
        a[i] += a[i - 1];
        b[i] += b[i - 1];
    }

    for(int i(0);i < n;i++) {
        if(s.substr(i, 2) == "AB") {
            if(i - 2 >= 0 && b[i - 2]) {
                puts("YES");
                return true;
            }
        }

        if(s.substr(i, 2) == "BA") {
            if(i - 2 >= 0 && a[i - 2]) {
                puts("YES");
                return true;
            }
        }
    }

    puts("NO");

    return true;
}   

int main()  
{
    //while(solve());
    solve();

    return 0;
}