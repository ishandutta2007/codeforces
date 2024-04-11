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
#include <string>
#include <cstdlib>
using namespace std;

#define Rep(i,n) for(int i=0;i<(n);++i)
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Ford(i,a,b) for(int i=(a);i>=(b);--i)
#define fi first
#define se second
#define pb push_back
#define MP make_pair

typedef pair<int,int> PII;
typedef vector<int> VI;

const int CANN = 80;

struct Add {
    int x;
    int l, r;
    long long c;    
    Add() {}
    Add(int x, int l, int r, long long c) : x(x), l(l), r(r), c(c) {}
    bool operator<(Add a)const {
        return x < a.x;
    }
};

struct Need {
    int x, pos, id;
    Need() {}
    Need(int x, int pos, int id) : x(x), pos(pos), id(id) {}
    bool operator<(Need n) const {
        return x < n.x;
    }
};  

int n, m;
int a[200020];
int T[200020];
int ne[200020];
map<int,int> start;
map<int,int> ma;
PII range[200020];
long long res[200020];

int ds[200020], nd;

Add add[8000050];
int na;

Need need[200020];

long long F[200020 * 4];

void cong(int n, int l, int r, int x, int y, long long v) {
    if(x <= l && r <= y) {
        F[n] += v;
        return;
    }
    int m = (l + r) / 2;
    if(x <= m) cong(2 * n, l, m, x, y, v);
    if(m < y) cong(2*n+1, m+1, r, x, y, v);
}

long long get(int n, int l, int r, int pos) {
    if(l == r) return F[n];
    else {
        int m = (l+r)/2;
        if(pos<=m) return F[n] + get(2*n,l,m,pos);
        else return F[n] + get(2*n+1,m+1,r,pos);    
    }  
}

int main() {
    scanf("%d%d", &n, &m);  
    Rep(i,n) scanf("%d", &a[i]);
    Rep(i,m) scanf("%d%d", &range[i].fi, &range[i].se), --range[i].fi, --range[i].se;
    Rep(i,m) need[i] = Need( range[i].fi, range[i].se, i);
    Rep(i,n) ma[a[i]]++;
   
    map<int,int> next;
    Ford(i,n-1,0) {
        if(!next.count(a[i])) ne[i] = n;
        else ne[i] = next[a[i]];
        next[a[i]] = i;
    }
    Rep(i,n) {
        if(!start.count(a[i])) start[a[i]] = i;
    }
    for(map<int,int>::iterator p=ma.begin();p!=ma.end();++p) {
        if(p->second >= CANN) {
            T[n] = 0;
            Ford(i,n-1,0) {
                T[i] = T[i+1];
                if(a[i] == p->first) ++T[i];    
            }
            Rep(i,m) {
                long long sl = T[range[i].fi] - T[range[i].se+1];
                res[i] += sl * sl * p->first;
            }
        }
        else {
            int id = start[p->first];
            nd = 0;
            while(id < n) {
                ds[nd++] = id;
                id = ne[id];
            }
            for(int i=0;i<nd;++i)
                for(int j=i;j<nd;++j) {
                    long long c = j - i + 1;
                    c *= c;
                    c *= p->first;
                    int ls = (i == 0 ? 0 : (ds[i-1]+1));
                    int le = ds[i];
                    int rs = ds[j];
                    int re = (j == (nd-1) ? (n-1) : (ds[j+1]-1));
                    // cout << "add " << ls << " " << rs << " " << re << " " << c << endl;
                    add[na++] = Add( ls, rs, re, c);
                    add[na++] = Add( le + 1, rs, re, -c);
                }
        }
    }
   
    sort( add, add + na);
    sort( need, need + m);
    int sa = 0, sn = 0;
   
    for(int x=0;x<n;++x) {
        while(sa < na && add[sa].x <= x) {
            cong(1, 0, n-1, add[sa].l, add[sa].r, add[sa].c);
//          cout << "cong " << add[sa].l << " " << add[sa].r << " " << add[sa].c << endl;
            ++sa;
        }
        while(sn < m && need[sn].x <= x) {
            if(need[sn].x == x) {
                res[need[sn].id] += get( 1, 0, n-1, need[sn].pos);
            }
            ++sn;
        }
    }
    Rep(i,m) {
        printf("%I64d\n", res[i]);  
    }
    return 0;
}