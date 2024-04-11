#include<bits/stdc++.h>
using namespace std;
#include<bits/extc++.h>
using namespace __gnu_pbds;
#define ri int
typedef long long ll;
const int maxn=1<<20;
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
struct flusher{~flusher(){fwrite(obuf,o-obuf,1,stdout);}}autoflush;
typedef pair<int,int> pii;
#define fi first
#define se second
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
    inline size_t operator()(const pii &x)const{
        static const uint64_t FIXED_RANDOM=chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(1145141ull*x.fi+x.se+FIXED_RANDOM);
    }
};
gp_hash_table<pii,bool,custom_hash>p;
inline bool calc(int x,int y){
	ckmax(y,0);
	if(x<y)return 0;
	auto it=p.find({x,y});
	if(it!=p.end())return it->second;
	bool &ret=p[{x,y}];
	for(ri i=x;i>=y;i=(i-1)&x){
		ret^=1;
		if(i==y)break;
	}
	return ret;
}
int a[maxn|10],k,n;
bool ans[maxn];
int main(){
	n=qr(),k=qr();
	for(ri i=1;i<=n;++i)a[i]=qr();
	for(ri i=1;i<=n;++i){
		ri l=i,pos=a[l],r=i;
		if(calc((n-1)-(r-l)-(l>1)-(r<n),k-(l>1)-(r<n)))ans[pos]^=1;
		while(r<n){
			++r;
			ri lim=0;
			if(a[r]<=20)lim=1<<20-a[r];
			if(pos>=lim)break;
			pos<<=a[r];
			if(calc((n-1)-(r-l)-(l>1)-(r<n),k-(l>1)-(r<n)))ans[pos]^=1;
		}
	}
	ri pos=0;
	for(ri i=0;i<maxn;++i)
		if(ans[i])
			pos=i;
	for(ri i=pos;~i;--i)putchar(ans[i]|48);
	return 0;
}