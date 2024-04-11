#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=2e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
static char pbuf[1000000],*p1=pbuf,*p2=pbuf;
#define getchar() p1==p2&&(p2=(p1=pbuf)+fread(pbuf,1,1000000,stdin),p1==p2)?EOF:*p1++
inline int qr(){
	ri in=0;char ch;
	while(!isdigit(ch=getchar()));
	do in=(in<<1)+(in<<3)+(ch^48);while(isdigit(ch=getchar()));
	return in;
}
int n;
ll ans;
priority_queue<ll>q;
int main(){
	n=qr();
	for(ri i=1;i<=n;++i)q.push(-qr());
	if(!(n&1)){
		ll x=-q.top();q.pop();x-=q.top();q.pop();
		ans+=x,q.push(-x);
	}
	while(q.size()>1){
		ll x=-q.top();q.pop();x-=q.top();q.pop();x-=q.top();q.pop();
		ans+=x,q.push(-x);
	}
	printf("%lld",ans);
	return 0;
}