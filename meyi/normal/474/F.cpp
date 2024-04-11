#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=1e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
static char pbuf[1000000],*p1=pbuf,*p2=pbuf,obuf[1000000],*o=obuf;
#define getchar() p1==p2&&(p2=(p1=pbuf)+fread(pbuf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define putchar(x) (o-obuf<1000000)?(*o++=(x)):(fwrite(obuf,o-obuf,1,stdout),o=obuf,*o++=(x))
inline int qr(){
	ri in=0;char ch;
	while(!isdigit(ch=getchar()));
	do in=(in<<1)+(in<<3)+(ch^48);while(isdigit(ch=getchar()));
	return in;
}
template<class T>
void qw(T out){
	if(out>9)qw(out/10);
	putchar(out%10|48);
}
struct flusher{~flusher(){fwrite(obuf,o-obuf,1,stdout);}}autoflush;
int a[maxn],lg,lg2[maxn],n;
typedef pair<int,int> pii;
#define fi first
#define se second
pii st[__lg(maxn)+1][maxn];
inline int gcd(int a,int b){
	ri t=__builtin_ctz(a|b);
	a>>=__builtin_ctz(a);
	b>>=__builtin_ctz(b);
	while(b){
		while(!(b&1))b>>=1;
		if(a>b)a^=b^=a^=b;
		b-=a;
	}
	return a<<t;
}
inline pii operator+(const pii &x,const pii &y){return {gcd(x.fi,y.fi),min(x.se,y.se)};}
inline void build_st(){
	for(ri i=1;i<=n;++i)lg2[i]=lg2[i-1]+((2<<lg2[i-1])==i),st[0][i]={a[i],a[i]};
	lg=lg2[n];
	for(ri i=1;i<=lg;++i)
		for(ri j=1;j+(1<<i)-1<=n;++j)
			st[i][j]=st[i-1][j]+st[i-1][j+(1<<(i-1))];
}
inline pii query_st(int l,int r){
	ri k=lg2[r-l+1];
	return st[k][l]+st[k][r-(1<<k)+1];
}
struct custom_hash{
    static uint64_t splitmix64(uint64_t x){
        x+=0x9e3779b97f4a7c15;
        x=(x^(x>>30))*0xbf58476d1ce4e5b9;
        x=(x^(x>>27))*0x94d049bb133111eb;
        return x^(x>>31);
    }
    inline size_t operator()(uint64_t x)const{
        static const uint64_t FIXED_RANDOM=chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x+FIXED_RANDOM);
    }
};
unordered_map<int,vector<int>,custom_hash>pos;
inline int query(int p,int l,int r){
	auto it=pos.find(p);
	return upper_bound(it->se.begin(),it->se.end(),r)-lower_bound(it->se.begin(),it->se.end(),l);
}
int q;
signed main(){
	n=qr();
	for(ri i=1;i<=n;++i)pos[a[i]=qr()].push_back(i);
	build_st();
	q=qr();
	while(q--){
		ri l=qr(),r=qr();
		pii tmp=query_st(l,r);
		qw(r-l+1-(tmp.fi!=tmp.se?0:query(tmp.se,l,r))),putchar(10);
	}
	return 0;
}