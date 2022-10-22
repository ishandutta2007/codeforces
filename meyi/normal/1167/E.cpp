#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=1e6+10;
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
int a[maxn],cnt,m,n;
ll ans;
vector<int>pos[maxn];
set<int>s;
signed main(){
	n=qr(),m=qr();
	s.insert(0);
	for(ri i=1;i<=n;++i){
		a[i]=qr();
		cnt+=(a[i]<a[i-1]);
		pos[a[i]].push_back(i);
		s.insert(i);
	}
	a[n+1]=m+1;
	s.insert(n+1);
	for(ri i=0,j=1;i<m;++i){
		while(j<=i+1){
			for(ri k:pos[j]){
				auto it=s.erase(s.find(k));
				ri nxt=*it,pre=*prev(it);
				cnt-=(a[k]<a[pre])+(a[nxt]<a[k]);
				cnt+=(a[nxt]<a[pre]);
			}
			++j;
		}
		for(ri k:pos[i]){
			auto it=s.insert(k).first;
			ri nxt=*next(it),pre=*prev(it);
			cnt-=(a[nxt]<a[pre]);
			cnt+=(a[k]<a[pre])+(a[nxt]<a[k]);
		}
		while(j<=m&&cnt){
			for(ri k:pos[j]){
				auto it=s.erase(s.find(k));
				ri nxt=*it,pre=*prev(it);
				cnt-=(a[k]<a[pre])+(a[nxt]<a[k]);
				cnt+=(a[nxt]<a[pre]);
			}
			++j;
		}
		if(!cnt)ans+=m-j+2;
	}
	printf("%lld",ans);
	return 0;
}