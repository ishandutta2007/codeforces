#include<bits/stdc++.h>
#define int long long
using namespace std;
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;
typedef unsigned long long ull;
typedef bitset<509> bset;
typedef pair<bset,bset> v2;

long long read() {
    long long res=0, w=1; char c=getchar();
    while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
    while(isdigit(c)) {res=res*10+c-48, c=getchar();}
    return res*w;
}

const int N=5e5+9;
set<int>s;
int n,a[N],b[N],w[N],m,q;
void print() {
    for(auto it=s.begin();it!=s.end();++it) {
        cout<<*it<<" "<<w[*it]<<endl;
    }
    puts("");
}
void merge(int x,int y) {
    auto itx=--s.upper_bound(x), ity=--s.upper_bound(y);
    if(w[*itx]==w[*ity]) s.erase(*ity);
}
void split(int x,int y) {
    w[y]=w[x];
    s.insert(y);
}
void flips(int x) {
    auto it=--s.upper_bound(x);
    auto sit=it;
    if(x!=*sit) split(*sit,x);
    it=--s.upper_bound(x);
    sit=it; ++sit;
    if(x+1!=*sit) split(x,x+1);
    w[x]=w[*it]^1;
    merge(x,x+1), merge(x-1,x);
}
int get(int x) {
    auto it=--s.upper_bound(x);
    return w[*it];
}
int nxt(int x) {
    auto it=--s.upper_bound(x);
    ++it;
    return *it;
}
int pre(int x) {
    auto it=--s.upper_bound(x);
    return (*it)-1;
}
int qry() {
    auto it=s.end(); --it;
    while(it!=s.begin()&&w[*it]!=1) --it;
    if(w[*it]!=1) throw "???";
    else return (*++it)-1;
}
void pls(int x) {
    if(get(x)==0) {
        flips(x);
    } else {
        int p=nxt(x);
        auto it=--s.upper_bound(x), sit=it; ++sit;
        if((*it)!=x) split(*it,x);
        w[x]^=1;
        merge(x,*sit), merge(x-1,x);
        flips(p);
    }
}
void mns(int x) {
    if(get(x)==1) {
        flips(x);
    } else {
        int p=nxt(x);
        auto it=--s.upper_bound(x), sit=it; ++sit;
        if((*it)!=x) split(*it,x);
        w[x]^=1;
        merge(x,*sit), merge(x-1,x);
        flips(p);
    }
}

signed main() {
    n=read(), q=read(); m=500000;
    rep(i,1,n) a[i]=read(), b[a[i]]++;
    rep(i,1,m) b[i+1]+=b[i]/2, b[i]%=2;
    w[0]=2, w[500001]=2; b[0]=2, b[500001]=2;
    int lst=0;
    s.insert(0);
    rep(i,1,m) {
        if(b[i]!=b[i+1]) {
            w[lst+1]=b[i];
            s.insert(lst+1);
            lst=i;
        }
    }
    s.insert(500001);
    rep(i,1,q) {
        int x=read(), y=read();
        pls(y);
        mns(a[x]);
        a[x]=y;
        printf("%lld\n",qry());
    }
    return 0;
}