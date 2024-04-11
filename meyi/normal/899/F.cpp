#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=2e5+10;
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
inline char gc(){
	char ch;
	while(!isalnum(ch=getchar()));
	return ch;
}
struct flusher{~flusher(){fwrite(obuf,o-obuf,1,stdout);}}autoflush;
int c[maxn],lg,m,n;
bool del[maxn];
set<int>pos[128];
char s[maxn];
#define lowbit(k) (k&-k)
inline void erase(int k){
	del[k]=true;
	for(;k<=n;k+=lowbit(k))--c[k];
}
inline int query(int k){
	ri ret=0;
	for(;k;k^=lowbit(k))ret+=c[k];
	return ret;
}
inline int half(int k){
	ri now=0,sum=0;
	for(ri i=lg;~i&&sum<k;--i){
		ri nxt=now|(1<<i);
		if(nxt<=n&&(sum+c[nxt]<k||(sum+c[nxt]==k&&!del[nxt])))now=nxt,sum+=c[nxt];
	}
	return now;
}
signed main(){
	lg=__lg(n=qr()),m=qr();
	for(ri i=1;i<=n;++i){
		++c[i];
		if(i+lowbit(i)<=n)c[i+lowbit(i)]+=c[i];
		pos[gc()].insert(i);
	}
	while(m--){
		ri l=qr(),r=qr();
		char ch=gc();
		auto it=pos[ch].lower_bound(half(l));
		vector<int>tmp;
		while(it!=pos[ch].end()&&query(*it)<=r)tmp.push_back(*it),it=pos[ch].erase(it);
		for(ri i:tmp)erase(i);
	}
	for(ri i=1;i<128;++i)
		for(ri j:pos[i])
			s[j]=i;
	for(ri i=1;i<=n;++i)
		if(s[i])
			putchar(s[i]);
	return 0;
}