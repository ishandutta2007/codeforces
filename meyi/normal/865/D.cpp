#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=3e5+10;
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
ll sum;
typedef pair<int,bool> pib;
#define fi first
#define se second
priority_queue<pib>q;
int main(){
	n=qr();
	for(ri i=1,x;i<=n;++i){
		x=qr();
		if(q.size()&&x>=-q.top().fi){
			if(q.top().se)q.emplace(q.top().fi,0),sum+=q.top().fi;
			q.pop();
			q.emplace(-x,1);
		}
		else q.emplace(-x,0),sum-=x;
	}
	while(q.size())sum-=q.top().fi,q.pop();
	printf("%lld",sum);
	return 0;
}