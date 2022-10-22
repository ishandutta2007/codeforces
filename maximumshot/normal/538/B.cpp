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

#include <conio.h>

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

    vec<string> ans;

    while(1) {
        bool flag = 0;
        for(int i(0);i < (int)s.size();i++) {
            if(s[i] != '0') {
                flag = 1;
                break;
            }
        }

        if(!flag) break;

        string q;

        int pos = 0;
        for(int i(0);i < (int)s.size();i++) {
            if(s[i] != '0') {
                pos = i;
                break;
            }
        }

        q = s.substr(pos);

        for(int i(0);i < (int)q.size();i++) {
            if(q[i] > '1') q[i] = '1';
        }

        for(int i(0);i < (int)s.size();i++) {
            if(s[i] > '0') s[i]--;
        }

        ans.push_back(q);
    }

    cout << (int)ans.size() << '\n';

    for(int i(0);i < (int)ans.size();i++) {
        cout << ans[i] << ' ';
    }

    cout << '\n';

    return true;
}   

int main() 
{
    //while(solve());
    solve();
    
    return 0;
}