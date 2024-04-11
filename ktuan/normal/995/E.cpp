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

int p;

int PP(int x, int n) {
    if (n == 0) return 1;
    else {
        LL z = PP(x, n / 2);
        if (n % 2 == 0) return (z * z) % p;
        else return (z * z) % p * x % p;
    }
}

void bfs(int v, VI &res, map<int,int> &before) {
    int maxd = 18;
    int maxOffset = 1;
    VI q;
    q.pb(v);
    map<int, int> ma;
    ma[v] = 0;
    for(int i = 0; i < q.size(); ++i) {
        int curv = q[i];
        int d = ma[curv];
        if (d >= maxd) continue;
        int nextv = PP(curv, p - 2);
        if (ma.find(nextv) == ma.end()) {
            ma[nextv] = d + 1;
            before[nextv] = curv;
            q.pb(nextv);
        }
        For(x, -maxOffset, maxOffset) if (x != 0) {
            int nextv = (curv + x + p) % p;
            if (ma.find(nextv) == ma.end()) {
                ma[nextv] = d + 1;
                before[nextv] = curv;
                q.pb(nextv);
            }
        }
    }    
    sort(q.begin(), q.end());
    Rep(i, q.size()) res.pb(q[i]);   
}

VI trace(int u, int v, map<int,int> &before) {
    VI res;
    while (u != v) {
        int bu = before[u];
        if ((bu + 1) % p == u) res.pb(1);
        else if ((bu + p - 1) % p == u) res.pb(2);
        else res.pb(3);
        u = bu;
    }
    reverse(res.begin(), res.end());
    return res;
}

void check(VI &res, int u, int v) {
    Rep(i, res.size()) {
        if (res[i] == 1) u = (u + 1) % p;
        else if (res[i] == 2) u = (u + p - 1) % p;
        else u = PP(u, p - 2);
    }
    if (u == v) cout << "Correct" << endl;
}

int main() {
    // p = 1000000009;
    // int x = time(0);
    // cout << x << endl;
    // srand(x);
    // int u = rand() % p;
    // int v = rand() % p;    
    int u, v;
    cin >> u >> v >> p;
    map<int, int> bu, bv;
    VI vu;
    bfs(u, vu, bu);
    VI vv;
    bfs(v, vv, bv);
    // cout << vu.size() << endl;
    // Rep(i, vu.size()) cout << vu[i] <<" "; cout << endl;
    Rep(i, vv.size()) {
        int tv = vv[i];
        int id = lower_bound(vu.begin(), vu.end(), tv) - vu.begin();
        if (id < vu.size() && vu[id] >= tv && vu[id] - tv < 150) {
            // verify(vu[id] >= tv);
            // cout << "Found" << endl;
            
            int tu = vu[id];
            VI p1 = trace(tu, u, bu);
            VI p2 = trace(tv, v, bv);
            reverse(p2.begin(), p2.end());
            VI res;
            Rep(i, p1.size()) res.pb(p1[i]);
            Rep(i, vu[id] - tv) res.pb(2);
            Rep(i, p2.size()) {
                if (p2[i] == 3) res.pb(p2[i]);
                else res.pb(3 - p2[i]);
            } 
            
            cout << res.size() << endl;
            Rep(i, res.size()) cout << res[i] << " ";
            cout << endl;
            
            // check(res, u, v);
            break;
        }
    }
    return 0;
}