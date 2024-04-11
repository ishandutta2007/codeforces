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
int a[maxn],lst=1,n;
struct cmp{inline bool operator()(int x,int y)const{return a[x]!=a[y]?a[x]<a[y]:x<y;}};
set<int,cmp>s1;
set<int>s2;
int main(){
	n=qr();
	for(ri i=1;i<=n;++i){
		a[i]=qr();
		if(a[i]!=a[lst])s1.insert(lst),s2.insert(lst),lst=i;
	}
	s1.insert(lst),s2.insert(lst);
	while(s1.size()>1){
		ri l=*s1.begin();s1.erase(s1.begin());
		auto nxt=s2.erase(s2.find(l));
		ri r=(nxt==s2.end()?n:*nxt-1);
		if((r-l+1)&1)return puts("NO"),0;
		ri val=INT_MAX;
		if(nxt!=s2.end())ckmin(val,a[*nxt]);
		if(nxt!=s2.begin())ckmin(val,a[*prev(nxt)]);
		a[l]=val;
		if(nxt!=s2.end()&&a[l]==a[*nxt])s1.erase(*nxt),nxt=s2.erase(nxt);
		if(nxt!=s2.begin()&&a[l]==a[*prev(nxt)]);
		else s1.insert(l),s2.insert(l);
	}
	puts("YES");
	return 0;
}