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
const LL base = inf + 7;
const LL MOD = inf + 9;
const double pi = acos(-1.0);

using namespace std;

bool solve()
{
    string s;

    cin >> s;

    int n = (int)s.size();

    string tmp = "CODEFORCES";

    if(n <= (int)tmp.size()) {puts("NO"); return true;}

    if(s.substr(0, (int)tmp.size()) == tmp) {
        puts("YES");
        return true;
    }

    if(s.substr(n - tmp.size()) == tmp) {
        puts("YES");
        return true;
    }

    for(int i(0);i < (int)tmp.size();i++) {
        if(s[i] != tmp[i]) break;
        
        // i + 1
        bool flag = 1;
        for(int q(9), j(n - 1);q > i;q--, j--) {
            flag &= (tmp[q] == s[j]);
        }
        if(flag) {
            puts("YES");
            return true;
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