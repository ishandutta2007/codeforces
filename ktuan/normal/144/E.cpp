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
#define Fid(i,c) for(decltype(c.begin()) i=c.rbegin();i!=c.rend();++i)
#define fi first
#define se second
#define pb push_back
#define MP make_pair

typedef pair<int,int> PII;
typedef vector<int> VI;

#define debug cout << "Here " << __LINE__ << endl;
template <typename T> ostream& operator<<(ostream &os, vector<T> v) { Rep(i, v.size()) os << v[i] << " "; os << endl; return os; }
template <typename T1, typename T2> ostream& operator<<(ostream &os, pair<T1, T2> p) { os << "(" << p.fi << ", " << p.se << ")"; return os; }
void verify(bool condition) { if (!condition) cerr << "WRONG WRONG" << endl; }

#define MAXN 100010

struct Item {
    int fi, se, id;  
};

int n, m;
Item a[MAXN];

bool cmp(Item a, Item b) {
    if (a.fi == b.fi) {
        if (a.se == b.se) return a.id < b.id;
        else return a.se < b.se;
    }
    else return a.fi < b.fi;
}

bool operator < (Item a, Item b) {
    if (a.se == b.se) {
        return a.id < b.id;
    }
    else return a.se < b.se;
}

int main() {
    scanf("%d%d", &n, &m);
    Rep(i, m) {
        scanf("%d%d", &a[i].fi, &a[i].se);
    }
    Rep(i, m) a[i].id = i;
    Rep(i, m) {
        Item &p = a[i];
        int u = n + 1 - p.se;
        int v = p.fi;
        p.fi = u;
        p.se = v;
    }
    sort(a, a + m, cmp);
    // Rep(i, m) cerr << a[i].fi << " " << a[i].se << endl;
    VI res;
    int sa = 0;
    set<Item> se;
    For(i, 1, n) {
        while (sa < m && a[sa].fi <= i) {
            se.insert(a[sa]);
            ++sa;
        }
        while (se.size() > 0 && se.begin()->se < i) {
            se.erase(se.begin());
        }
        if (se.size() > 0) {
            res.pb(se.begin()->id);
            se.erase(se.begin());
        }
    }
    printf("%d\n", (int)(res.size()));
    Fit(i, res) printf("%d ", (*i) + 1);
    return 0;
}