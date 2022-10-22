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
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());
int a[maxn],ans,L[maxn],n,R[maxn],st[maxn],tp;
ll id[maxn],pre[maxn],sum[maxn];
inline bool in(int l,int k,int r){return l<=k&&k<=r;}
void solve(int p,int l,int r){
	if(!p||l>r)return;
	if(p-l<r-p){
		for(ri i=l;i<=p;++i)
			if(in(p,i+a[p]-1,r)&&(pre[i+a[p]-1]^pre[i-1])==sum[a[p]])
				++ans;
	}
	else{
		for(ri i=r;i>=p;--i)
			if(in(l,i-a[p]+1,p)&&(pre[i]^pre[i-a[p]])==sum[a[p]])
				++ans;
	}
	solve(L[p],l,p-1),solve(R[p],p+1,r);
}
int main(){
	n=qr();
	for(ri i=1;i<=n;++i){
		a[i]=qr();
		id[i]=rnd();
		while(tp&&a[i]>a[st[tp]])L[i]=st[tp--];
		if(tp)R[st[tp]]=i;
		st[++tp]=i;
	}
	for(ri i=1;i<=n;++i)pre[i]=pre[i-1]^id[a[i]],sum[i]=sum[i-1]^id[i];
	solve(st[1],1,n);
	printf("%d",ans);
	return 0;
}