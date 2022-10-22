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
    int k, n;
    string a;

    cin >> k >> a;
    
    n = (int)a.size();

    vec<string> ans;

    vec<bool> used(26, 0);

    for(int i(0);i < n;i++) {
        if(i == 0) {
            used[a[i] - 'a'] = 1;
            ans.push_back(string(1, a[i]));
        }else {
            if(used[a[i] - 'a']) {
                ans.back() += a[i];
            }else {
                used[a[i] - 'a'] = 1;
                if((int)ans.size() < k) {
                    ans.push_back(string(1, a[i]));
                }else {
                    ans.back() += a[i];
                }
            }
        }
    }

    if((int)ans.size() < k) {
        puts("NO");
    }else {
        puts("YES");
        for(auto i : ans) cout << i << '\n'; 
    }


    return true;
}   

int main() 
{
    //while(solve());
    solve();
    
    return 0;
}