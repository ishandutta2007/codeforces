#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e6+10,mod=998244353;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
static char pbuf[1000000],*p1=pbuf,*p2=pbuf,obuf[1000000],*o=obuf;
#define getchar() p1==p2&&(p2=(p1=pbuf)+fread(pbuf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define putchar(x) (o-obuf<1000000)?(*o++=(x)):(fwrite(obuf,o-obuf,1,stdout),o=obuf,*o++=(x))
inline int qr(){
	ri in=0;register char ch;
	while(!isdigit(ch=getchar()));
	do in=(in<<1)+(in<<3)+(ch^48);while(isdigit(ch=getchar()));
	return in;
}
inline int qrf(){
	ri in=0;register bool f=false;register char ch;
	while(!isdigit(ch=getchar()))f|=(ch=='-');
	do in=(in<<1)+(in<<3)+(ch^48);while(isdigit(ch=getchar()));
	return f?-in:in;
}
template<class T>
void qw(T out){
	if(out>9)qw(out/10);
	putchar(out%10|48);
}
inline char gc(){
	char ch;
	while(!isupper(ch=getchar()));
	return ch;
}
struct flusher{~flusher(){fwrite(obuf,o-obuf,1,stdout);}}autoflush;
struct modint{
	int val;
	inline modint(int val_=0):val(val_){}
	inline modint &operator=(int val_){return val=val_,*this;}
	inline modint &operator+=(const modint &k){return val=val+k.val>=mod?val+k.val-mod:val+k.val,*this;}
	inline modint &operator-=(const modint &k){return val=val-k.val<0?val-k.val+mod:val-k.val,*this;}
    inline modint &operator*=(const modint &k){return val=1ll*val*k.val%mod,*this;}
    inline modint &operator^=(int k){
        modint ret=1,tmp=*this;
        for(;k;k>>=1,tmp*=tmp)if(k&1)ret*=tmp;
        return val=ret.val,*this;
    }
    inline modint &operator/=(modint k){return *this*=(k^=mod-2);}
    inline modint &operator+=(int k){return val=val+k>=mod?val+k-mod:val+k,*this;}
    inline modint &operator-=(int k){return val=val<k?val-k+mod:val-k,*this;}
    inline modint &operator*=(int k){return val=1ll*val*k%mod,*this;}
    inline modint &operator/=(int k){return *this*=((modint(k))^=mod-2);}
    template<class T>friend modint operator+(modint a,T b){return a+=b;}
    template<class T>friend modint operator-(modint a,T b){return a-=b;}
    template<class T>friend modint operator*(modint a,T b){return a*=b;}
    template<class T>friend modint operator/(modint a,T b){return a/=b;}
    friend modint operator^(modint a,int b){return a^=b;}
    friend bool operator==(modint a,int b){return a.val==b;}
    friend bool operator!=(modint a,int b){return a.val!=b;}
    inline bool operator!(){return !val;}
    inline modint operator-(){return val?mod-val:0;}
    inline modint &operator++(int){return *this+=1;}
};
using mi=modint;
mi pw2[maxn];
struct node{
	int bad,cnt1[maxn][2],cnt2[maxn],tot;
	inline void insert(int id,bool clr){
		if(!cnt1[id][clr]&&cnt1[id][clr^1])++bad;
		++cnt1[id][clr];
		if(!cnt2[id])++tot;
		++cnt2[id];
	}
	inline void erase(int id,bool clr){
		if(cnt1[id][clr]==1&&cnt1[id][clr^1])--bad;
		--cnt1[id][clr];
		if(cnt2[id]==1)--tot;
		--cnt2[id];
	}
}col,row;
typedef pair<int,int> pii;
#define fi first
#define se second
unordered_map<ll,bool>p;
int cnt[2],m,n,q;
int main(){
	n=qr(),m=qr(),q=qr();
	pw2[0]=1;
	for(ri i=1,j=max(n,m);i<=j;++i)pw2[i]=pw2[i-1]+pw2[i-1];
	while(q--){
		ri x=qr(),y=qr(),op=qrf();
		if(~op){
			ll z=x*114514ll+y;
			auto it=p.find(z);
			if(it==p.end()||op!=it->se){
				bool tp=(x&1)^(y&1);
				if(it!=p.end()){
					col.erase(y,it->se^tp);
					row.erase(x,it->se^tp);
					--cnt[it->se^tp];
					it->se=op;
				}
				else p[z]=op;
				col.insert(y,op^tp);
				row.insert(x,op^tp);
				++cnt[op^tp];
			}
		}
		else{
			auto it=p.find(x*114514ll+y);
			if(it!=p.end()){
				bool tp=(x&1)^(y&1);
				col.erase(y,it->se^tp);
				row.erase(x,it->se^tp);
				--cnt[it->se^tp];
				p.erase(it);
			}
		}
		if(col.bad&&row.bad)putchar(48);
		else if(col.bad)qw(pw2[n-row.tot].val);
		else if(row.bad)qw(pw2[m-col.tot].val);
		else if(!(col.tot+row.tot))qw((pw2[m]+pw2[n]-2).val);
		else qw((pw2[m-col.tot]+pw2[n-row.tot]-(bool(cnt[0])^bool(cnt[1]))).val);
		putchar(10);
	}
	return 0;
}