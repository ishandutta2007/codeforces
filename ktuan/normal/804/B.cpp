#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

#define Rep(i,n) for(int i=0;i<(n);++i)
#define Repd(i,n) for(int i=((int)(n))-1;i>=0;--i)
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Ford(i,a,b) for(int i=(a);i>=(b);--i)
#define Foreach(i,c) for(typeof(c.begin()) it=c.begin();it!=c.end();++it)
#define fi first
#define se second
#define pb push_back
#define MP make_pair

typedef pair<int,int> PII;
typedef vector<int> VI;

#define debug cout << "Here " << __LINE__ << endl;
template <typename T> ostream& operator<<(ostream &os, vector<T> v) { Rep(i, v.size()) os << v[i] << " "; os << endl; return os; }
template <typename T1, typename T2> ostream& operator<<(ostream &os, pair<T1, T2> p) { os << "(" << p.fi << ", " << p.se << ")"; return os; }

const int mod = 1000000000 + 7;

long long p2(long long x) {
    if (x == 0) return 1;
    else {
        long long r = p2(x / 2);
        if (x % 2 == 0) return (r * r) % mod;
        else return ((r * r) % mod * 2) % mod;
    }
}

int main() {
    cout.sync_with_stdio(false);
    string s;
    cin >> s;
    int n = s.length();
    long long ca = 0;
    long long res = 0;
    Rep(i, n) {
        if (s[i] == 'a') ++ca;
        if (s[i] == 'b') {
            res = res + p2(ca) - 1 + mod;
            res = res % mod;
        }
    }   
    cout << res << endl;
    return 0;
}