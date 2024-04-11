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

#define debug cout << "Here " << __LINE__ << endl;
template <typename T1, typename T2> ostream& operator<<(ostream &os, pair<T1, T2> p) { os << "(" << p.fi << ", " << p.se << ")"; return os; }
template <typename T> ostream& operator<<(ostream &os, vector<T> v) { Rep(i, v.size()) os << v[i] << " "; os << endl; return os; }

string s;
int nxt[26];
int n;
int a[300010];
long long total[26 + 1];

int main() {
    cin >> s;
    n = s.length();
    Rep(i, n) a[i] = s[i] - 'a';
    Rep(i, 26) nxt[i] = n;
    Ford(i, n-1, 0) {
        nxt[a[i]] = i;
        VI v;
        Rep(j, 26) if (nxt[j] < n) v.pb(nxt[j]);
        sort(v.begin(), v.end());
        Rep(j, v.size()) {
            int st = v[j];
            int end = j + 1 < v.size() ? v[j + 1] : n;
            total[j + 1] += end - st;
        }
    }
    int res = 26;
    while (total[res] == 0) --res;
    cout << res << endl;
    For(i, 1, res) cout << total[i] << endl;
    return 0;
}