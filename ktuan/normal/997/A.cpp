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
#define Fit(i,c) for(decltype(c.begin()) i=c.begin();i!=c.end();++i)
#define Fid(i,c) for(decltype(c.rbegin()) i=c.rbegin();i!=c.rend();++i)
#define fi first
#define se second
#define pb push_back
#define MP make_pair

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;

#define debug cout << "Here " << __LINE__ << endl;
template <typename T1, typename T2> ostream& operator<<(ostream &os, pair<T1, T2> p) { os << "(" << p.fi << ", " << p.se << ")"; return os; }
template <typename T> ostream& operator<<(ostream &os, vector<T> v) { Rep(i, v.size()) os << v[i] << " "; os << endl; return os; }
void verify(bool condition) { if (!condition) cerr << "WRONG WRONG" << endl; }

int main() {
    int n;
    LL x, y;
    string s;
    cin >> n >> x >> y >> s;
    LL c0 = 0;
    Rep(i, n) if (s[i] == '0' && (i == 0 || s[i - 1] == '1')) ++c0;
    if (c0 == 0) cout << 0 << endl;
    else if (c0 * y > y + (c0 - 1) * x) cout << y + (c0 - 1) * x << endl;
    else cout << c0 * y << endl;
    return 0;
}