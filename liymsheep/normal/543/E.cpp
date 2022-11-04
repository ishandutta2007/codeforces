// {{{ by shik
#include <bits/stdc++.h>
#include <unistd.h>
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x),end(x)
#define REP(i,n) for ( int i=0; i<int(n); i++ )
#define REP1(i,a,b) for ( int i=(a); i<=int(b); i++ )
#define FOR(it,c) for ( auto it=(c).begin(); it!=(c).end(); it++ )
#define MP make_pair
#define PB push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;

#ifdef SHIK
template<typename T>
void _dump( const char* s, T&& head ) { cerr<<s<<"="<<head<<endl; }

template<typename T, typename... Args>
void _dump( const char* s, T&& head, Args&&... tail ) {
    int c=0;
    while ( *s!=',' || c!=0 ) {
        if ( *s=='(' || *s=='[' || *s=='{' ) c++;
        if ( *s==')' || *s==']' || *s=='}' ) c--;
        cerr<<*s++;
    }
    cerr<<"="<<head<<", ";
    _dump(s+1,tail...);
}

#define dump(...) do { \
    fprintf(stderr, "%s:%d - ", __PRETTY_FUNCTION__, __LINE__); \
    _dump(#__VA_ARGS__, __VA_ARGS__); \
} while (0);

template<typename Iter>
ostream& _out( ostream &s, Iter b, Iter e ) {
    s<<"[";
    for ( auto it=b; it!=e; it++ ) s<<(it==b?"":" ")<<*it;
    s<<"]";
    return s;
}

template<typename A, typename B>
ostream& operator <<( ostream &s, const pair<A,B> &p ) { return s<<"("<<p.first<<","<<p.second<<")"; }
template<typename T>
ostream& operator <<( ostream &s, const vector<T> &c ) { return _out(s,ALL(c)); }
template<typename T>
ostream& operator <<( ostream &s, const set<T> &c ) { return _out(s,ALL(c)); }
template<typename A, typename B>
ostream& operator <<( ostream &s, const map<A,B> &c ) { return _out(s,ALL(c)); }
#else
#define dump(...)
#endif

void RI() {}

template<typename... T>
void RI( int& head, T&... tail ) {
    scanf("%d",&head);
    RI(tail...);
}
// }}}

const int N=2e5+10;

struct Seg {
    uint64_t lc:23, rc:23, mx:18;
} mem[40 * N];

int get_mx(int id, int l, int r) {
    return l == r ? id : mem[id].mx;
}

int c_max(Seg *t, int l, int m, int r) {
    return max(get_mx(t->lc, l, m), get_mx(t->rc, m + 1, r));
}

int n_seg;

int ins(int id, int l, int r, int ql, int qr) {
    if (l == r) return id + 1;
    Seg *t = &mem[++n_seg];
    *t = mem[id];
    if (ql <= l && r <= qr) {
        t->mx++;
    } else {
        int m = (l + r) / 2;
        int add = t->mx - c_max(t, l, m, r);
        if (ql <= m) t->lc = ins(t->lc, l, m, ql, qr);
        if (qr > m) t->rc = ins(t->rc, m + 1, r, ql, qr);
        t->mx = c_max(t, l, m, r) + add;
    }
    return t - mem;
}
int get_max(int id, int l, int r, int ql, int qr) {
    if (l == r) return id;
    Seg *t = &mem[id];
    if (ql <= l && r <= qr) {
        return t->mx;
    } else {
        int m = (l + r) / 2;
        int ret = 0;
        if (ql <= m) ret = max(ret, get_max(t->lc, l, m, ql, qr));
        if (qr > m) ret = max(ret, get_max(t->rc, m + 1, r, ql, qr));
        return ret + (t->mx - c_max(t, l, m, r));
    }
}

int n,m,seg[N];
PII a[N];
int main() {
    RI(n,m);
    REP1(i,1,n) RI(a[i].first);
    REP1(i,1,n) a[i].second=i;
    sort(a+1,a+n+1);
    for ( int i=n; i>=1; i-- ) {
        int r=min(n-m+1,a[i].second);
        int l=max(1,a[i].second-m+1);
        seg[i]=ins(seg[i+1],1,n-m+1,l,r);
    }
    int s,ans=0;
    RI(s);
    while ( s-- ) {
        int l,r,x;
        RI(l,r,x);
        x^=ans;
        int idx=lower_bound(a+1,a+n+1,MP(x,0))-a;
        ans=m-get_max(seg[idx],1,n-m+1,l,r);
        printf("%d\n",ans);
    }
    return 0;
}