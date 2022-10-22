#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e4+10;
template<class T>inline void clear(T *arr,int siz){memset(arr,0,sizeof(T)*(siz+1));}
int cnt[maxn],mx,n,rk[maxn],sa[maxn],tmp[maxn];
char s[maxn];
inline void base_sort(){
	clear(cnt,mx);
	for(ri i=1;i<=n;++i)++cnt[rk[i]];
	for(ri i=1;i<=mx;++i)cnt[i]+=cnt[i-1];
	for(ri i=n;i;--i)sa[cnt[rk[tmp[i]]]--]=tmp[i];
}
inline void suffix_sort(){
	mx=0;
	for(ri i=1;i<=n;++i)mx=max(mx,rk[i]=s[i]),tmp[i]=i;
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
int lg,lg2[maxn],st[(int)log2(maxn)+1][maxn];
inline void build_st(){
	for(ri i=1;i<=n;++i)lg2[i]=lg2[i-1]+((2<<lg2[i-1])==i),st[0][i]=ht[i];
	lg=lg2[n];
	for(ri i=1;i<=lg;++i)
		for(ri j=1;j+(1<<(i-1))<=n;++j)
			st[i][j]=min(st[i-1][j],st[i-1][j+(1<<(i-1))]);
}
inline int query(int l,int r){
	ri k=lg2[r-l+1];
	return min(st[k][l],st[k][r-(1<<k)+1]);
}
int f[maxn],t_case;
signed main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%s",&n,s+1);
		suffix_sort();
		calc_ht();
		build_st();
		ri ans=0;
		for(ri i=1;i<=n;++i){
			for(ri j=0;j<i;++j)
				if(sa[j]<sa[i])
					ckmax(f[i],f[j]+n-sa[i]+1-query(j+1,i));
			ckmax(ans,f[i]);
		}
		printf("%d\n",ans);
		clear(f,n);
		clear(s,n);
		clear(rk,n);
		clear(sa,n);
		clear(tmp,n);
	}
	return 0;
}