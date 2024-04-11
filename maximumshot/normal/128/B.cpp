#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector
#define deb(x) cerr << #x << " = " << x << '\n';

typedef unsigned long long ull;
typedef long double LD;
typedef long long LL;

const LL inf = 1000000000ll;
const LL inf64 = inf * inf;
const LL base = inf + 7;
const LL MOD = inf + 9;
const double pi = acos(-1.0);

using namespace std;

template<typename T, typename P>
const ostream & operator << (ostream & os, const pair<T, P> & a) {
    os.precision(10);
    os << fixed;
    os << a.first;
    os << ' ';
    os << a.second;
    os << '\n';
    return os;
}

string read() {
    char buffer[100100];
    gets(buffer);
    return buffer;
}

vec< vec<int> > BuildSuffArray(string s) {

    vec< vec<int> > ans;

    s += char(0);
    int n = (int)s.size(), sz = max(300, n);

    vec<int> p, c, pn, cn, cnt(sz, 0);

    p = c = pn = cn = vec<int>(n);

    for(int i(0);i < n;i++) cnt[s[i]]++;
    for(int i(1);i < sz;i++) cnt[i] += cnt[i - 1];
    for(int i(n - 1);i >= 0;i--) p[--cnt[s[i]]] = i;

    int q = 0;

    c[p[0]] = 0;
    for(int i(1);i < n;i++) {
        if(s[p[i]] != s[p[i - 1]]) q++;
        c[p[i]] = q;
    }

    ans.push_back(c);

    for(int k(0);(1 << k) < n;k++) {
        cnt.assign(sz, 0);
        for(int i(0);i < n;i++) {
            pn[i] = (p[i] - (1 << k));
            pn[i] = (pn[i] % n + n) % n;
        }

        for(int i(0);i < n;i++) cnt[c[pn[i]]]++;
        for(int i(1);i < sz;i++) cnt[i] += cnt[i - 1];
        for(int i(n - 1);i >= 0;i--) p[--cnt[c[pn[i]]]] = pn[i];
        q = 0;
        cn[p[0]] = 0;
        for(int i(1);i < n;i++) {
            int l1, r1, l2, r2;
            l1 = p[i - 1], r1 = (l1 + (1 << k)) % n;
            l2 = p[i],     r2 = (l2 + (1 << k)) % n;
            if(c[l1] != c[l2] || c[r1] != c[r2]) q++;
            cn[p[i]] = q;
        }

        c = cn;
        ans.push_back(c);
    }

    return ans;
}

vec< vec<int> > c;
vec<int> lg;

struct seg {
    int l, r;

    seg() {
        l = r = 0;
    }

    seg(int ql, int qr) {
        l = ql, r = qr;
    }

    const seg & operator = (const seg & b) {
        l = b.l;
        r = b.r;

        return *this;
    }
};

bool operator < (const seg & a, const seg & b) {
    int len1, len2, lg1, lg2;
    
    len1 = a.r - a.l + 1;
    len2 = b.r - b.l + 1;

    lg1 = lg[len1];
    lg2 = lg[len2];

    int l1, r1, l2, r2;

    if(len1 == len2) {
        l1 = a.l, r1 = a.r;
        l2 = b.l, r2 = b.r;
        return (mp(c[lg1][l1], c[lg1][r1 - (1 << lg1) + 1]) > mp(c[lg1][l2], c[lg2][r2 - (1 << lg1) + 1]));
    }else if(len1 < len2) {
        l1 = a.l, r1 = a.r;
        l2 = b.l, r2 = l2 + len1 - 1;
        pair<int, int> p1, p2;
        p1 = mp(c[lg1][l1], c[lg1][r1 - (1 << lg1) + 1]);
        p2 = mp(c[lg1][l2], c[lg1][r2 - (1 << lg1) + 1]);

        if(p1 == p2) {
            return 0;
        }else {
            return (p1 > p2);
        }
    }else {
        l2 = b.l, r2 = b.r;
        l1 = a.l, r1 = l1 + len2 - 1;
        pair<int, int> p1, p2;
        p1 = mp(c[lg2][l1], c[lg2][r1 - (1 << lg2) + 1]);
        p2 = mp(c[lg2][l2], c[lg2][r2 - (1 << lg2) + 1]);

        if(p1 == p2) {
            return 1;
        }else {
            return (p1 > p2);
        }
    }
}

bool solve()
{
    string s;
    
    s = read();

    int n, k;
        
    scanf("%d", &k);

    n = (int)s.size();

    if(1ll * n * (1 + n) / 2 < k) {
        puts("No such line.");
        return true;
    }

    c = BuildSuffArray(s); 
    
    lg.resize(n + 1);
    int q = 0;
    while((1 << q) <= n) q++;
    q--;
    for(int i(n);i >= 1;i--) {
        if((1 << q) > i) q--;
        lg[i] = q;
    }

    priority_queue<seg> h;
    vec<seg> tmp;

    for(int i(0);i < n;i++) {
        h.push(seg(i, i));
    }

    for(int i(0);i < k - 1;i++) {
        //cout << i << " : ";
        int l, r;
        l = h.top().l;
        r = h.top().r;
        //cout << l << ' ' << r << '\n';
        h.pop();
        if(r + 1 < n) {
            r++;
            h.push(seg(l, r));
        }
    }

    int l, r;
    l = h.top().l;
    r = h.top().r;

    for(int i(l);i <= r;i++) {
        putchar(s[i]);
    }

    return true;
}   

int main() 
{
    //while(solve());
    solve();
    
    return 0;
}