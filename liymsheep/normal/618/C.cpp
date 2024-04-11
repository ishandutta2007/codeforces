#include <functional>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <cctype>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stdio.h>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <assert.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define TR(i,x) for(__typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))

#include <unordered_set>
#include <unordered_map>

using namespace std;

#define PB push_back
#define MP make_pair

typedef map<int,int> MII;
typedef map<string,int> MSI;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<long double> VD;
typedef pair<int,int> PII;
typedef long long int64;
typedef long long LL;
typedef unsigned int UI;
typedef long double LD;
typedef unsigned long long ULL;

using namespace std;

struct pt {
    int id;
    LL x,y;
    pt(LL _x = 0,LL _y = 0) { x = _x; y = _y;}
    pt operator + (const pt &p) const { return pt(x+p.x,y+p.y);}
    pt operator - (const pt &p) const { return pt(x-p.x,y-p.y);}
    pt operator * (const LL p) const { return pt(p*x,p*y);}
    /*  */
    bool operator < (const pt &p) const
    {
        if (x != p.x) return x < p.x;
        return y < p.y;
    }
    void read() { 
        int u, v;
        scanf("%d%d", &u, &v);
        x = u;
        y = v;
    }
};

LL det(pt a,pt b) { return a.x*b.y - a.y*b.x;}
LL dot(pt a,pt b) { return a.x*b.x + a.y*b.y;}

bool cmp(const pt &a, const pt &b) {
    bool aup = (a.y > 0 || a.y == 0 && a.x > 0);
    bool bup = (b.y > 0 || b.y == 0 && b.x > 0);
    if (aup ^ bup) return bup;
    if (det(a, b) != 0) {
        return det(a, b) > 0;
    }
    return a.x * a.x + a.y * a.y < b.x * b.x + b.y * b.y;
}

int main() {
    int n;
    cin >> n;
    vector<pt> points(n);

    int idx = -1;
    REP(i, n) {
        points[i].read();
        points[i].id = i;
        if (idx == -1 || points[i] < points[idx]) {
            idx = i;
        }
    }

    vector<pt> others;
    REP(i, n) {
        if (i != idx) {
            pt sub = points[i] - points[idx];
            sub.id = i;
            others.PB(sub);
        }
    }
    sort(ALL(others), cmp);

    VI ans;
    ans.PB(idx);
    ans.PB(others[0].id);
    int i = 1;
    while (det(others[i], others[0]) == 0) {
        ++i;
    }
    ans.PB(others[i].id);
    SORT(ans);
    REP(i, ans.size()) {
        if (i) cout << " ";
        cout << ans[i] + 1;
    }
    cout << endl;
    return 0;
}