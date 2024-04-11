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

const LL inf = 1000000000ll;
const LL inf64 = inf * inf;
const LL base = inf * 1000ll + 17;
const LL MOD = inf + 9;
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

    for(int i(0);i < n;i++) {
        if(s[i] == '0') { 
            puts("YES");
            cout << 0 << '\n';
            return true;
        }
    }

    for(int i(0);i < n;i++) {
        if(s[i] == '8') {
            puts("YES");
            cout << 8 << '\n';
            return true;
        }
    }   

    for(int i(0);i < n;i++) {
        for(int j(i + 1);j < n;j++) {
            for(int z(j + 1);z < n;z++) {
                int val1, val2, val3;
                val1 = s[i] - '0';
                val2 = s[j] - '0';
                val3 = s[z] - '0';
                if(!val1) continue;
                int x = val1 * 100 + val2 * 10 + val3;
                if(x % 8 == 0) {
                    puts("YES");
                    cout << x << '\n';
                    return true;
                }
            }
        }
    }

    for(int i(0);i < n;i++) {
        for(int j(i + 1);j < n;j++) {
            int val1, val2;
            val1 = s[i] - '0';
            val2 = s[j] - '0';
            if(!val1) continue;
            int x = val1 * 10 + val2;
            if(x % 8 == 0) {
                puts("YES");
                cout << x << '\n';
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