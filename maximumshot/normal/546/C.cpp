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
    int n, k;
    LL x, y;

    cin >> n;

    queue<LL> a, b;

    cin >> k;

    for(int i(0);i < k;i++) {
        cin >> x;
        a.push(x);
    }

    cin >> k;

    for(int i(0);i < k;i++) {
        cin >> x;
        b.push(x);
    }

    int xod = 1;

    while(!a.empty() && !b.empty()) {
        if(xod > 1000000) {
            break;
        }

        x = a.front(); a.pop();
        y = b.front(); b.pop();

        if(x > y) {
            a.push(y);
            a.push(x);
        }else if(x < y) {
            b.push(x);
            b.push(y);
        }else {
            a.push(x);
            b.push(y);
        }

        xod++;
    }

    xod--;

    if(!a.empty() && !b.empty()) {
        puts("-1");
    }else {
        cout << xod << ' ';
        cout << (a.empty()?2 : 1) << '\n';
    }

    return true;
}   

int main() 
{
    //while(solve());
    solve();

    return 0;
}