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
    int n;
    vec<int> a;

    cin >> n;
    
    a.resize(n);

    for(int i(0);i < n;i++) {
        cin >> a[i];
    }

    if(n == 1) {
        if(a[0]) puts("NO");
        else puts("YES\n0");
        return true;
    }

    if(a.back()) {
        puts("NO");
        return true;
    }

    if(a[n - 2]) {
        cout << "YES\n";
        for(int i(0);i < n;i++) {
            cout << a[i];
            if(i + 1 < n) {
                cout << "->";
            }
        }
    }else {
        int cnt = 0;
        int pos = n - 2;
        while(pos >= 0 && !a[pos]) pos--; pos++;
        cnt = n - pos - 1;
        if(cnt > 1) {
            cout << "YES\n";
            for(int i(0);i < n - 3;i++) {
                cout << a[i] << "->";
            } 
            cout << "(" << a[n - 3] << "->" << a[n - 2] << ")->0\n"; 
        }else {
            pos = -1;
            for(int i(n - 3);i >= 0;i--) {
                if(!a[i]) {
                    pos = i;
                    break;
                }
            }
            if(pos == -1) cout << "NO";
            else {
                cout << "YES\n";
                for(int i(0);i < pos;i++) {
                    cout << a[i] << "->";
                }
                cout << "(0->(";
                for(int i(pos + 1);a[i];i++) {
                    cout << a[i];
                    if(a[i + 1]) cout << "->";
                }
                cout << "->0))->0\n";
            }
        }
    }

    return true;
}   

int main() 
{
    //while(solve());
    solve();

    return 0;
}