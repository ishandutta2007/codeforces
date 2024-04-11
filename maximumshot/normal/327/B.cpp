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
    vec<bool> prime(10000001, true);

    prime[0] = prime[1] = 0;

    for(LL i(2);i * i <= 10000000;i++) {
        for(LL j(i * i);j <= 10000000 && prime[i];j += i) {
            prime[j] = 0;
        }
    }

    int c = 0, n;

    scanf("%d", &n);

    for(int i(2);i <= 10000000 && c < n;i++) {
        if(prime[i]) {
            printf("%d ", i);
            c++;
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