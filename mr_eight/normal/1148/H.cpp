//#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <algorithm>
#include <climits>
#include <functional>
#include <cstring>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <complex>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define itn int
#define nit int
#define ll long long
#define ms multiset
#define F(i,a,b) for(register int i=a,i##end=b;i<=i##end;++i)
#define UF(i,a,b) for(register int i=a,i##end=b;i>=i##end;--i)
#define re register
#define ri re int
#define il inline
#define pii pair<int,int>
#define cp complex<double>
//#pra gma G CC opti mize(3)
using namespace std;
using std::bitset;
//using namespace __gnu_pbds;
const double Pi=acos(-1);
namespace fastIO {
    template<class T>
    inline void read(T &x) {
        x=0;
        bool fu=0;
        char ch=0;
        while(ch>'9'||ch<'0') {
            ch=getchar();
            if(ch=='-')fu=1;
        }
        while(ch<='9'&&ch>='0') x=(x*10-48+ch),ch=getchar();
        if(fu)x=-x;
    }
    inline int read() {
        int x=0;
        bool fu=0;
        char ch=0;
        while(ch>'9'||ch<'0') {
            ch=getchar();
            if(ch=='-')fu=1;
        }
        while(ch<='9'&&ch>='0') x=(x*10-48+ch),ch=getchar();
        return fu?-x:x;
    }
    template<class T,class... Args>
    inline void read(T& t,Args&... args) {
        read(t);
        read(args...);
    }
    char _n_u_m_[40];
    template<class T>
    inline void write(T x ) {
        if(x==0){
            putchar('0');
            return;
        }
        T tmp = x > 0 ? x : -x ;
        if( x < 0 ) putchar('-') ;
        register int cnt = 0 ;
        while( tmp > 0 ) {
            _n_u_m_[ cnt ++ ] = tmp % 10 + '0' ;
            tmp /= 10 ;
        }
        while( cnt > 0 ) putchar(_n_u_m_[ -- cnt ]) ;
    }
    template<class T>
    inline void write(T x ,char ch) {
        write(x);
        putchar(ch);
    }
}
using namespace fastIO;
#define mid ((l+r)>>1)
int lc[40000002],rc[40000002],tag[40000002],cnt,n;
ll sum[40000002];
inline int cpy(int pos){
    ++cnt;
    lc[cnt]=lc[pos],rc[cnt]=rc[pos],tag[cnt]=tag[pos],sum[cnt]=sum[pos];
    return cnt;
}
inline void pushup(int pos,int l,int r){
    sum[pos]=sum[lc[pos]]+sum[rc[pos]]+1ll*tag[pos]*(r-l+1);
}
/*
inline int pushdown(int pos,int l,int r){
    pos=cpy(pos);
    lc[pos]=cpy(lc[pos]);
    rc[pos]=cpy(rc[pos]);
    tag[lc[pos]]+=tag[pos];
    tag[rc[pos]]+=tag[pos];
    sum[lc[pos]]+=1ll*tag[pos]*(mid-l+1);
    sum[rc[pos]]+=1ll*tag[pos]*(r-mid);
    tag[pos]=0;
    return pos;
}
*/
inline int puttag(int pos,int l,int r,int v){
    pos=cpy(pos);
    tag[pos]+=v;
    sum[pos]+=1ll*(r-l+1)*v;
    return pos;
}
inline int Add(int pos,int l,int r,int ql,int qr,int v){
    if(ql<=l&&qr>=r)return puttag(pos,l,r,v);
    pos=cpy(pos);
    if(ql<=mid)lc[pos]=Add(lc[pos],l,mid,ql,qr,v);
    if(qr>mid)rc[pos]=Add(rc[pos],mid+1,r,ql,qr,v);
    pushup(pos,l,r);
    return pos;
}
inline ll Query(int pos,int l,int r,int ql,int qr){
    if(ql<=l&&qr>=r)return sum[pos];
    ll rt=tag[pos]*(min(r,qr)-max(l,ql)+1ll);
    if(ql<=mid)rt+=Query(lc[pos],l,mid,ql,qr);
    if(qr>mid)rt+=Query(rc[pos],mid+1,r,ql,qr);
    return rt;
}
struct TT{
    vector<int>root,t,qwq,qaq;
    TT(){
        root.resize(1),t.resize(1);qwq.resize(1);qaq.resize(1);
        root[0]=t[0]=qaq[1]=0;qwq[1]=1;
    }
    inline void add(int l,int r,int v,int tt){
        if(l>r)return;
        t.push_back(tt);
        root.push_back(Add(root.back(),1,n,l,r,v));
    }
    inline ll query(int l,int r){
    	int p=upper_bound(t.begin(),t.end(),r+1)-1-t.begin();
        int rt=root[p];
        return Query(rt,1,n,l,r)+1ll*(r+1)*max(0,min(qaq[p],r)-max(qwq[p],l)+1);
    }
    inline void ins(int l,int r){
    	qwq.push_back(l);
    	qaq.push_back(r);
	}
}T[200002];
int l[200002],r[200002],lst[200002];
ll lstans;
namespace orz{
    int mmin[800002];
    inline void modify(int pos,int l,int r,int q,int v){
        if(l==r){
            mmin[pos]=v;
            return;
        }
        if(q<=mid)modify(pos<<1,l,mid,q,v);
        else modify(pos<<1|1,mid+1,r,q,v);
        mmin[pos]=min(mmin[pos<<1],mmin[pos<<1|1]);
    }
    inline int query(int pos,int l,int r,int mmax){
        if(l==r)return l;
        if(mmin[pos<<1]<=mmax)return query(pos<<1,l,mid,mmax);
        else return query(pos<<1|1,mid+1,r,mmax);
    }
}
int main(){
    cin>>n;
    F(i,0,n)l[i]=1;
    F(i,1,n){
        int a=(read()+lstans)%(n+1);lst[a]=i;orz::modify(1,0,n,a,i);
        T[0].add(i,i,-i,i);
        ++r[0];T[0].ins(l[0],r[0]);
        int tr=r[a],tl=l[a];
        if(r[a]>=l[a]){
            T[a].add(l[a],r[a],i,i);
            l[a]=i+1;r[a]=i;T[a].ins(l[a],r[a]);
            int now=tr,temp;
            while(lst[temp=orz::query(1,0,n,now-1)]>=tl){
                l[temp]=lst[temp]+1;
                r[temp]=now;
                T[temp].add(l[temp],r[temp],-i,i);
                T[temp].ins(l[temp],r[temp]);
                now=lst[temp];
            }
            T[temp].add(tl,now,-i,i);
            r[temp]=now;
            T[temp].ins(l[temp],r[temp]);
        }
        int L=(read()+lstans)%i+1;
        int R=(read()+lstans)%i+1;
        int k=(read()+lstans)%(n+1);
        if(L>R)swap(L,R);//cerr<<a<<" "<<L<<" "<<R<<" "<<k<<endl;
        //cerr<<min(r[1],R)<<" "<<max(r[2],l-1)<<" "<<T[1].query(2,2)<<endl<<r[2]<<" "<<r[1]<<" "<<r[0]<<endl;
        write(lstans=T[k].query(L,R),'\n');
    }
    return 0;
}
/*
5
0 0 0 1
0 1 0 5
5 2 1 0
5 2 1 0
2 4 3 3
*/