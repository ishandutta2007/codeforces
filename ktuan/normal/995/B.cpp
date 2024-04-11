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
#define fi first
#define se second
#define pb push_back
#define MP make_pair

typedef pair<int,int> PII;
typedef vector<int> VI;

#define debug cout << "Here " << __LINE__ << endl;
template <typename T1, typename T2> ostream& operator<<(ostream &os, pair<T1, T2> p) { os << "(" << p.fi << ", " << p.se << ")"; return os; }
template <typename T> ostream& operator<<(ostream &os, vector<T> v) { Rep(i, v.size()) os << v[i] << " "; os << endl; return os; }
void verify(bool condition) { if (!condition) cerr << "WRONG WRONG" << endl; }

int n, a[202];

int main() {
    cin >> n;
    Rep(i, 2*n) cin >> a[i];
    int res = 0;
    For(v1, 1, n) For(v2, v1+1, n) {
        VI p1, p2;
        Rep(i, 2*n) {
            if (a[i] == v1) p1.pb(i);
            if (a[i] == v2) p2.pb(i);
        }
        if (p1[0] > p2[0]) {
            VI t = p1; p1 = p2; p2 = t;
        }
        if (p2[0] < p1[1]) {
            if (p2[1] < p1[1]) res += 2;
            else res += 1;
        }
    }
    cout << res << endl;
    return 0;
}