#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=2e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
int cnt[maxn],l[maxn],mx,n,pre[maxn],r[maxn],rk[maxn],sa[maxn],st[maxn],tmp[maxn],tp;
char ban[maxn],s[maxn];
inline void base_sort(){
	clear(cnt,mx);
	for(ri i=1;i<=n;++i)++cnt[rk[i]];
	for(ri i=1;i<=mx;++i)cnt[i]+=cnt[i-1];
	for(ri i=n;i;--i)sa[cnt[rk[tmp[i]]]--]=tmp[i];
}
inline void suffix_sort(){
	for(ri i=1;i<=n;++i)ckmax(mx,rk[i]=s[i]),tmp[i]=i;
	base_sort();
	for(ri len=1,dif=0;dif<n;len<<=1,mx=dif){
		ri p=0;
		for(ri i=n-len+1;i<=n;++i)tmp[++p]=i;
		for(ri i=1;i<=n;++i)
			if(sa[i]>len)
				tmp[++p]=sa[i]-len;
		base_sort();
		swap(rk,tmp);
		rk[sa[1]]=dif=1;
		for(ri i=2;i<=n;++i){
			if(tmp[sa[i-1]]!=tmp[sa[i]]||tmp[sa[i-1]+len]!=tmp[sa[i]+len])++dif;
			rk[sa[i]]=dif;
		}
	}
}
int ht[maxn];
inline void calc_ht(){
	for(ri i=1,h=0;i<=n;++i){
		if(h)--h;
		ri j=sa[rk[i]-1];
		while(s[i+h]==s[j+h])++h;
		ht[rk[i]]=h;
	}
}
ll ans;
signed main(){
	scanf("%d%s%s",&n,s+1,ban+1);
	for(ri i=n;i;--i)
		if(ban[i]=='0'){
			ans=i;
			break;
		}
	reverse(s+1,s+n+1),reverse(ban+1,ban+n+1);
	suffix_sort();
	for(ri i=1;i<=n;++i)pre[i]=pre[i-1]+(ban[sa[i]]^48);
	calc_ht();
	st[tp=0]=1;
	for(ri i=2;i<=n;++i){
		while(tp&&ht[i]<=ht[st[tp]])--tp;
		l[i]=st[tp];
		st[++tp]=i;
	}
	st[tp=0]=n+1;
	for(ri i=n;i>1;--i){
		while(tp&&ht[i]<=ht[st[tp]])--tp;
		r[i]=st[tp];
		st[++tp]=i;
	}
	for(ri i=2;i<=n;++i)ckmax(ans,1ll*ht[i]*(r[i]-l[i]-(pre[r[i]-1]-pre[l[i]-1])));
	printf("%lld",ans);
	return 0;
}