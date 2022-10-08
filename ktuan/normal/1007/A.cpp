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

const int maxn = 100050;

int n;
int a[maxn];

int main() {
    cin >> n;
    Rep(i, n) cin >> a[i];
    sort(a, a + n);
    int j = 0;
    int res = 0;
    Rep(i, n) {
        while (j < n && a[j] <= a[i]) ++j;
        if (j < n) {
            ++res;
            ++j;
        }
    }
    cout << res << endl;
    return 0;
}