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
	ri in=0;register char ch;
	while(!isdigit(ch=getchar()));
	do in=(in<<1)+(in<<3)+(ch^48);while(isdigit(ch=getchar()));
	return in;
}
template<class T>
void qw(T out){
	if(out>9)qw(out/10),putchar(out%10|48);
	else putchar(out|48);
}
struct flusher{~flusher(){fwrite(obuf,o-obuf,1,stdout);}}autoflush;
multiset<int>ans;
int m,n;
set<int>s;
inline void insert(int x){
	auto it=s.insert(x).first,nxt=next(it);
	if(nxt!=s.end())ans.insert(*nxt-x+1);
	if(it!=s.begin()){
		auto pre=prev(it);
		ans.insert(x-*pre+1);
		if(nxt!=s.end())ans.erase(ans.find(*nxt-*pre+1));
	}
}
inline void erase(int x){
	auto nxt=s.erase(s.find(x));
	if(nxt!=s.end())ans.erase(ans.find(*nxt-x+1));
	if(nxt!=s.begin()){
		auto pre=prev(nxt);
		ans.erase(ans.find(x-*pre+1));
		if(nxt!=s.end())ans.insert(*nxt-*pre+1);
	}
}
inline int calc(){
	if(ans.empty())return 0;
	return *s.rbegin()-*s.begin()+1-*ans.rbegin();
}
int main(){
	n=qr(),m=qr();
	for(ri i=1;i<=n;++i)insert(qr());
	qw(calc()),putchar(10);
	while(m--){
		if(qr())insert(qr());
		else erase(qr());
		qw(calc()),putchar(10);
	}
	return 0;
}