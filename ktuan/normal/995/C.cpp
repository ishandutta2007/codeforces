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

PII operator+(PII a, PII b) {
    return PII(a.fi + b.fi, a.se + b.se);
}

PII operator-(PII a, PII b) {
    return PII(a.fi - b.fi, a.se - b.se);
}

double len(PII a) {
    return sqrt(a.fi * 1.0 * a.fi + a.se * 1.0 * a.se);
}

LL lenLL(PII a) {
    return a.fi * 1LL * a.fi + a.se * 1LL * a.se;
}

void check(PII a, PII b, PII c) {
    PII p[3] = {a, b, c};
    bool pass = false;
    Rep(bit, 8) {
        PII z(0, 0);
        Rep(i, 3) if ((bit & (1<<i)) != 0) z = z + p[i]; else z = z - p[i];
        if (len(z) <= 52) pass = true;
    }
    if (!pass) {
        cout << a << " " << b << " " << c << endl;
    }
}

struct Item {
    PII vec;
    int id;
};

bool operator < (Item a, Item b) {
    LL lena = lenLL(a.vec);
    LL lenb = lenLL(b.vec);
    if (lena == lenb) return a.id < b.id;
    else return lena > lenb;
}

int nid;
int top[220000];
int F[220000];
int root;

int calc(int i) {
    if (i == root) return 1;
    int &res = F[i];
    if (res != -1) return res;
    if (top[i] < 0) res = 1 - calc(-top[i]-1);
    else res = calc(top[i]);
    return res;
}

int main() {
    // vector<PII> v;
    // For(x, -50, 50) For(y, -50, 50) {
    //     double l = len(PII(x, y));
    //     if (49 <= l && l <= 51) {
    //         v.pb(PII(x, y));
    //     }
    // }
    // cout << v.size() << endl;
    // Rep(i, v.size()) Rep(j, v.size()) if (i < j) {
    //     For(k, j + 1, v.size() - 1) {
    //         check(v[i], v[j], v[k]);
    //     }
    // }
    // check(PII(-50, -5), PII(-50, 10), PII(-49, 0));
    int n;
    scanf("%d", &n);
    vector<Item> a(n);
    Rep(i, n) {
        scanf("%d%d", &a[i].vec.fi, &a[i].vec.se);
        a[i].id = i;
    }
    // sort(a.begin(), a.end());
    nid = n;
    set<Item> se;
    Rep(i, n) se.insert(a[i]);
    while (se.size() > 1) {
        Item p[3];
        int np = 2;
        p[0] = *se.begin();
        se.erase(se.begin());
        p[1] = *se.begin();
        se.erase(se.begin());
        if (se.size() > 0) {
            np = 3;
            p[2] = *se.begin();
            se.erase(se.begin());
        }
        
        double bestLength = 1e11;
        int bestBit = -1;
        PII bestVec;
        Rep(bit, (1 << np)) {
            PII thisVec(0,0);
            Rep(j, np) {
                if ((bit & (1 << j)) != 0) thisVec = thisVec + p[j].vec;
                else thisVec = thisVec - p[j].vec;
            }
            double thisLength = len(thisVec);
            if (bestLength > thisLength) {
                bestLength = thisLength;
                bestBit = bit;
                bestVec = thisVec;
            }
        }
        // verify(bestLength <= 1.5 * 1e6);
        
        Item newItem;
        newItem.vec = bestVec;
        newItem.id = nid;
        se.insert(newItem);
        Rep(j, np) {
            if ((bestBit & (1 << j)) != 0) top[p[j].id] = nid;
            else top[p[j].id] = -nid - 1;
        }
        ++nid;
    }
    root = se.begin()->id;
    memset(F, -1, sizeof(F));
    Rep(i, n) printf("%d ", calc(i) == 1 ? 1 : -1);
    
    // for (int i = 1; i < a.size(); i += 2) {
    //     PII p[3] = {currentVec, a[i].vec, PII(0,0)};
    //     if (i + 1 < a.size()) {
    //         p[2] = a[i + 1].vec;
    //     }
    //     double bestLength = 1e11;
    //     int bestBit = -1;
    //     Rep(bit, 8) if ((bit & 1) != 0) {
    //         PII thisVec(0,0);
    //         Rep(j, 3) {
    //             if ((bit & (1 << j)) != 0) thisVec = thisVec + p[j];
    //             else thisVec = thisVec - p[j];
    //         }
    //         double thisLength = len(thisVec);
    //         if (bestLength > thisLength) {
    //             bestLength = thisLength;
    //             bestBit = bit;
    //         }
    //     }
        
    // }
    return 0;
}