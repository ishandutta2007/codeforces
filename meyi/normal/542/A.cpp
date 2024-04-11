#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=4e5+10;
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
ll ans;
int id[maxn],l[maxn],m,n,r[maxn],v[maxn],x,y;
typedef pair<int,int> pii;
#define fi first
#define se second
map<int,pii>p;
int main(){
	n=qr(),m=qr();
	for(ri i=1;i<=n;++i)id[i]=i,l[i]=qr(),r[i]=qr();
	for(ri i=n+1;i<=n+m;++i)id[i]=i,l[i]=qr(),r[i]=qr(),v[i]=qr();
	sort(id+1,id+n+m+1,[&](int x,int y){return l[x]!=l[y]?l[x]<l[y]:(x>n)<(y>n);});
	for(ri ii=1,j=INT_MIN,k=0;ii<=n+m;++ii){
		ri i=id[ii];
		if(i<=n){
			if(r[i]>j)j=r[i],k=i;
		}
		else if(j!=INT_MIN){
			ll tmp=1ll*(min(j,r[i])-l[i])*v[i];
			if(tmp>ans)ans=tmp,x=k,y=i-n;
		}
	}
	sort(id+1,id+n+m+1,[&](int x,int y){return r[x]!=r[y]?r[x]>r[y]:(x>n)<(y>n);});
	for(ri ii=1,j=INT_MAX,k=0;ii<=n+m;++ii){
		ri i=id[ii];
		if(i<=n){
			if(l[i]<j)j=l[i],k=i;
		}
		else if(j!=INT_MAX){
			ll tmp=1ll*(r[i]-max(j,l[i]))*v[i];
			if(tmp>ans)ans=tmp,x=k,y=i-n;
		}
	}
	sort(id+1,id+n+m+1,[&](int x,int y){return l[x]!=l[y]?l[x]>l[y]:(x>n)<(y>n);});
	for(ri ii=1;ii<=n+m;++ii){
		ri i=id[ii];
		if(i<=n){
			auto nxt=p.upper_bound(r[i]);
			if(nxt!=p.begin()){
				auto pre=prev(nxt);
				if(pre->se.fi>=r[i]-l[i])continue;
				if(pre->fi==r[i])nxt=pre;
			}
			while(nxt!=p.end()&&nxt->se.fi<=r[i]-l[i])nxt=p.erase(nxt);
			p[r[i]]={r[i]-l[i],i};
		}
		else{
			auto nxt=p.upper_bound(r[i]);
			if(nxt!=p.begin()){
				--nxt;
				ll tmp=1ll*nxt->se.fi*v[i];
				if(tmp>ans)ans=tmp,x=nxt->se.se,y=i-n;
			}
		}
	}
	printf("%lld",ans);
	if(ans)printf("\n%d %d",x,y);
	return 0;
}