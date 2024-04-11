#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#define F(i,a,b) for(register int i=a,i##end=b;i<=i##end;++i)
#define UF(i,a,b) for(register int i=a,i##end=b;i>=i##end;--i)
#define ll long long
#define re register
#define ri register int
using namespace std;
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
set<int>s1,s2;
int m;
#define n 100000
bool t1[100002],t2[100002];
#define mid (l+r>>1)
#define lc (pos<<1)
#define rc (pos<<1|1)
struct segment_tree{
    ll sum[400002];
    int mx[400002],se[400002],len[400002],cnt[400002],tag[400002];
    inline void build(int pos,int l,int r){
        len[pos]=r-l+1;
        mx[pos]=tag[pos]=1000000000;
        se[pos]=-1000000000;
        if(l!=r)build(lc,l,mid),build(rc,mid+1,r);
    }
    segment_tree(){
        build(1,1,n);
    }
    inline void pushup(int pos){
        sum[pos]=sum[lc]+sum[rc];
        mx[pos]=max(mx[lc],mx[rc]);
        if(mx[lc]>mx[rc])cnt[pos]=cnt[lc],se[pos]=max(se[lc],mx[rc]);
        else if(mx[lc]<mx[rc])cnt[pos]=cnt[rc],se[pos]=max(se[rc],mx[lc]);
        else cnt[pos]=cnt[lc]+cnt[rc],se[pos]=max(se[lc],se[rc]);
    }
    inline void update(int pos,int v){
        if(mx[pos]>v){
            tag[pos]=v;
            sum[pos]-=1ll*(mx[pos]-v)*cnt[pos];
            mx[pos]=v;
        }
    }
    inline void pushdown(int pos){
        if(tag[pos]!=1000000000){
            update(lc,tag[pos]);
            update(rc,tag[pos]);
            tag[pos]=1000000000;
        }
    }
    inline void orz(int pos,int l,int r,int q){
        if(l==r){
            cnt[pos]=1;
            sum[pos]=mx[pos];
        }else{
            pushdown(pos);
            if(q<=mid)orz(lc,l,mid,q);
            else orz(rc,mid+1,r,q);
            pushup(pos);
        }
    }
    inline void modify(int pos,int l,int r,int ql,int qr,int v){
        if(ql>r||qr<l)return;
        if(ql<=l&&qr>=r&&v>se[pos]){
            update(pos,v);
        }else{
            pushdown(pos);
            modify(lc,l,mid,ql,qr,v);
            modify(rc,mid+1,r,ql,qr,v);
            pushup(pos);
        }
    }
    inline ll query(int pos,int l,int r,int ql,int qr){
        if(ql>r||qr<l)return 0;
        if(ql<=l&&qr>=r)return sum[pos];
        pushdown(pos);
        return query(lc,l,mid,ql,qr)+query(rc,mid+1,r,ql,qr);
    }
}X,Y;
int main(){
    F(i,1,n)s1.insert(i),s2.insert(i);
    cin>>m;
    int x,l,r;
    F(iakioi,1,m){
        if(read()==1){
            read(l,r,x);
            --r;
            if(x>0){
                while(1){
                    auto i=s1.lower_bound(l);
                    if(i!=s1.end()&&(*i)<=r){
                        t1[*i]=1;
                        if(t2[*i])X.orz(1,1,n,*i),Y.orz(1,1,n,*i);
                        s1.erase(i);
                    }else break;
                }
                X.modify(1,1,n,l,r,x);
            }else{
                x=-x;
                while(1){
                    auto i=s2.lower_bound(l);
                    if(i!=s2.end()&&(*i)<=r){
                        t2[*i]=1;
                        if(t1[*i])X.orz(1,1,n,*i),Y.orz(1,1,n,*i);
                        s2.erase(i);
                    }else break;
                }
                Y.modify(1,1,n,l,r,x);
            }
        }else{
            read(l,r);
            --r;
            write(X.query(1,1,n,l,r)+Y.query(1,1,n,l,r),'\n');
        }
    }
    return 0;
}