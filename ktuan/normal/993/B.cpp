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
void verify(bool condition) { if (!condition) cerr << "WRONG WRONG" << endl; }

int m, n;
int a[55][2], b[55][2];

int common(int a[2], int b[2]) {
    int count = 0;
    int r = -1;
    Rep(i, 2) Rep(j, 2) if (a[i] == b[j]) {
        ++count;
        r = a[i];
    }
    // cerr << count << " " << r << endl;
    if (count == 1) return r;
    else return -1;
}

int CC(vector<bool> v) {
    int c = 0;
    Rep(i, v.size()) if (v[i]) c++;
    return c;
}

bool maybe[15];

int main() {
    cin >> m >> n;
    Rep(i, m) cin >> a[i][0] >> a[i][1];
    Rep(j, n) cin >> b[j][0] >> b[j][1];
    
    Rep(i, m) Rep(j, n) {
        int x = common(a[i], b[j]);
        if (x != -1) {
            maybe[x] = true;
        }
    }    
    int c = 0;
    int t = 0;
    Rep(i, 15) if (maybe[i]) { ++c; t = i; }
    if (c == 1) {
        cout << t << endl;
        return 0;
    }
    bool dontknow = false;
    Rep(i, m) {
        vector<bool> mark(15, false);
        Rep(j, n) {
            int x = common(a[i], b[j]);
            if (x != -1) mark[x] = true;
        }
        if (CC(mark) >= 2) {
            dontknow = true;
        }
    }
    Rep(j, n) {
        vector<bool> mark(15, false);
        Rep(i, m) {
            int x = common(a[i], b[j]);
            if (x != -1) mark[x] = true;
        }
        if (CC(mark) >= 2) {
            // cerr << mark << endl;
            dontknow = true;
        }
    }
    if (dontknow) cout << -1 << endl;
    else cout << 0 << endl;
    return 0;
}