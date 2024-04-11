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

void print(const vec<int> & a) {
    printf("%d ", (int)a.size());
    for(int i(0);i < (int)a.size();i++) {
        printf("%d ", a[i]);
    }
    puts("");
}

bool solve()
{
    int n;

    scanf("%d", &n);

    vec<int> a1, a2, a3;

    for(int i(0);i < n;i++) {
        int x;
        scanf("%d", &x);
        if(x < 0) {
            if(a1.empty()) {
                a1.push_back(x);
            }else {
                a3.push_back(x);
            }
        }else if(x > 0) {
            if(a2.empty()) {
                a2.push_back(x);
            }else {
                a3.push_back(x);
            }
        }else {
            a3.push_back(x);
        }
    }

    if(a2.empty()) {
        sort(a3.rbegin(), a3.rend());
        a2.push_back(a3.back()); a3.pop_back();
        a2.push_back(a3.back()); a3.pop_back();
    }

    print(a1);
    print(a2);
    print(a3);

    return true;
}   

int main() 
{
    //while(solve());
    solve();

    return 0;
}