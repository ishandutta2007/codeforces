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
#include <list>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector
#define deb(x) cerr << #x << " = " << x << '\n';

typedef unsigned long long ull;
typedef long double LD;
typedef long long LL;

const LL inf = 1000000000ll;
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
    string a, b, c;
    
    cin >> a >> b >> c;
    
    vec< int > Ca(26, 0);
 
    for(int i(0);i < (int)a.size();i++) {
        Ca[a[i] - 'a']++;
    }
  
    vec< int > Cb(26, 0), Cc(26, 0);
 
    for(int i(0);i < (int)b.size();i++) {
        Cb[b[i] - 'a']++;
    }
 
    for(int i(0);i < (int)c.size();i++) {
        Cc[c[i] - 'a']++;
    }
 
    int cb, cc;

    int ans = 0, ansb = 0, ansc = 0;

    for(int i(0);i < (int)a.size() + 10;i++) {
        cb = i;
        bool ok = 1;
        for(int j(0);j < 26;j++) {
            if(Cb[j] && (Ca[j] / Cb[j]) < cb) ok = 0;
        }
        if(!ok) break;
        vec< int > Ta = Ca;
        cc = inf;
        for(int j(0);j < 26;j++) {
            Ta[j] -= cb * Cb[j];
            int tc = inf;
            if(Cc[j]) {
                tc = Ta[j] / Cc[j];
            }
            cc = min(cc, tc);
        }
        if(cc == inf) cc = 0;
        if(cb + cc > ans) {
            ans = cb + cc;
            ansb = cb;
            ansc = cc;
        }
    }

    //cout << ans << ' ' << ansb << ' ' << ansc << '\n';

    for(int i(0);i < 26;i++) {
        Ca[i] -= ansb * Cb[i];
        Ca[i] -= ansc * Cc[i];
        for(int j(0);j < Ca[i];j++) {
            cout << char(i + 'a');
        }
    }

    for(int i(0);i < ansb;i++) cout << b;
    for(int i(0);i < ansc;i++) cout << c;

    return true;
}   

int main()  
{
    //while(solve());   
    solve();

    return 0;
}