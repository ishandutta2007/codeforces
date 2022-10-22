#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
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
int lg,st[18][maxn];
inline void build_st(){
	lg=log2(n);
	for(ri i=1;i<=n;++i)st[0][i]=ht[i];
	for(ri i=1;i<=lg;++i)
		for(ri j=1;j+(1<<(i-1))<=n;++j)
			st[i][j]=min(st[i-1][j],st[i-1][j+(1<<(i-1))]);
}
inline int query(int l,int r){
	assert(l>1);
	ri k=log2(r-l+1);
	return min(st[k][l],st[k][r-(1<<k)+1]);
}
struct segment_tree{
	int l,r,mn,mx,tag;
	ll sum;
}t[maxn<<2];
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
inline void push_up(int p){
	t[p].mn=min(t[ls(p)].mn,t[rs(p)].mn);
	t[p].mx=max(t[ls(p)].mx,t[rs(p)].mx);
	t[p].sum=t[ls(p)].sum+t[rs(p)].sum;
}
inline void build_tree(int p,int l,int r){
	t[p].l=l,t[p].r=r,t[p].tag=-1;
	if(l==r){
		t[p].mn=t[p].mx=t[p].sum=0;
		return;
	}
	ri mid=l+r>>1;
	build_tree(ls(p),l,mid);
	build_tree(rs(p),mid+1,r);
	push_up(p);
}
inline void add_tag(int p,int v){
	t[p].mn=t[p].mx=t[p].tag=v;
	t[p].sum=1ll*(t[p].r-t[p].l+1)*v;
	return;
}
inline void push_down(int p){
	if(!~t[p].tag)return;
	add_tag(ls(p),t[p].tag);
	add_tag(rs(p),t[p].tag);
	t[p].tag=-1;
}
inline void add(int p,int k,int v){
	if(t[p].l>k||k>t[p].r)return;
	if(t[p].l==k&&k==t[p].r){
		t[p].mn=t[p].mx=t[p].sum=v;
		return;
	}
	//push_down(p);
	add(ls(p),k,v);
	add(rs(p),k,v);
	push_up(p);
}
inline void modify(int p,int l,int r,int v){
	if(t[p].l>r||l>t[p].r||t[p].mx<=v)return;
	if(t[p].mn>v){add_tag(p,v);return;}
	push_down(p);
	modify(ls(p),l,r,v);
	modify(rs(p),l,r,v);
	push_up(p);
}
int a[maxn],al,b[maxn],bl,num,q,vis[maxn];
int main(){
	scanf("%d%d%s",&n,&q,s+1);
	suffix_sort();
	calc_ht();
	build_st();
	for(ri t_case=1;t_case<=q;++t_case){
		scanf("%d%d",&al,&bl);
		for(ri i=1;i<=al;++i){
			scanf("%d",a+i);
			if(vis[a[i]]!=t_case)vis[a[i]]=t_case,cnt[a[i]]=0;
			++cnt[a[i]];
			a[i]=rk[a[i]];
		}
		sort(a+1,a+al+1);
		ll ans=0;
		for(ri i=1;i<=bl;++i){
			scanf("%d",b+i);
			if(vis[b[i]]==t_case)ans+=1ll*cnt[b[i]]*(n-b[i]+1);
			b[i]=rk[b[i]];
		}
		sort(b+1,b+bl+1);
		build_tree(1,1,al);
		for(ri i=1,j=1;i<=bl;++i){
			while(j<=al&&a[j]<b[i])add(1,j,query(a[j]+1,b[i])),++j;
			ans+=t[1].sum;
			if(i<bl)modify(1,1,j-1,query(b[i]+1,b[i+1]));
		}
		build_tree(1,1,al);
		for(ri i=bl,j=al;i;--i){
			while(j&&a[j]>b[i])add(1,j,query(b[i]+1,a[j])),--j;
			ans+=t[1].sum;
			if(i>1)modify(1,j+1,al,query(b[i-1]+1,b[i]));
		}
		printf("%lld\n",ans);
	}
	return 0;
}