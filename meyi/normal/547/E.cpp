#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz){memset(arr,0,sizeof(T)*(siz+1));}
int cnt[maxn<<1],inf=255,mx,n,rk[maxn<<2],s[maxn<<1],sa[maxn<<1],tmp[maxn<<2];
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
int ht[maxn<<1];
inline void calc_ht(){
	for(ri i=1,h=0;i<=n;++i){
		if(h)--h;
		ri j=sa[rk[i]-1];
		while(s[i+h]==s[j+h])++h;
		ht[rk[i]]=h;
	}
}
int lg,lg2[maxn<<1],st[(int)log2(maxn<<1)+1][maxn<<1];
inline void build_st(){
	for(ri i=1;i<=n;++i)lg2[i]=lg2[i-1]+((2<<lg2[i-1])==i),st[0][i]=ht[i];
	lg=lg2[n];
	for(ri i=1;i<=lg;++i)
		for(ri j=1;j+(1<<i)-1<=n;++j)
			st[i][j]=min(st[i-1][j],st[i-1][j+(1<<(i-1))]);
}
inline int query(int l,int r){
	ri k=lg2[r-l+1];
	return min(st[k][l],st[k][r-(1<<k)+1]);
}
int m;
namespace SGT{
	struct segment_tree{
		int ls,rs,sum;
	}t[(maxn<<1)*20];
	int cnt;
	int insert(int p,int l,int r,int k){
		t[++cnt]=t[p];
		p=cnt;
		++t[p].sum;
		if(l==r)return p;
		ri mid=l+r>>1;
		if(k<=mid)t[p].ls=insert(t[p].ls,l,mid,k);
		else t[p].rs=insert(t[p].rs,mid+1,r,k);
		return p;
	}
	int query(int p1,int p2,int l,int r,int k){
		if(l==r)return t[p2].sum-t[p1].sum;
		ri mid=l+r>>1;
		if(k<=mid)return query(t[p1].ls,t[p2].ls,l,mid,k);
		else return t[t[p2].ls].sum-t[t[p1].ls].sum+query(t[p1].rs,t[p2].rs,mid+1,r,k);
	}
	int rt[maxn<<1];
	inline int query(int l,int r,int ql,int qr){
		return query(rt[l-1],rt[r],0,m,qr)-query(rt[l-1],rt[r],0,m,ql-1);
	}
}
using SGT::rt;
using SGT::insert;
using SGT::query;
int id[maxn<<1],len[maxn],pos[maxn],q,qL[maxn],qR[maxn];
char t[maxn];
int main(){
	scanf("%d%d",&m,&q);
	for(ri i=1;i<=m;++i){
		scanf("%s",t+1);
		len[i]=strlen(t+1);
		pos[i]=n+1;
		for(ri j=1;j<=len[i];++j)s[++n]=t[j],id[n]=i,t[j]=0;
		s[++n]=++inf;
	}
	suffix_sort();
	for(ri i=1;i<=n;++i)rt[i]=insert(rt[i-1],0,m,id[sa[i]]);
	calc_ht();
	build_st();
	for(ri i=1,l,r;i<=m;++i){
		l=1,r=rk[pos[i]]-1;
		qL[i]=rk[pos[i]];
		while(l<=r){
			ri mid=l+r>>1;
			if(query(mid+1,rk[pos[i]])>=len[i])qL[i]=mid,r=mid-1;
			else l=mid+1;
		}
		l=rk[pos[i]]+1,r=n;
		qR[i]=rk[pos[i]];
		while(l<=r){
			ri mid=l+r>>1;
			if(query(rk[pos[i]]+1,mid)>=len[i])qR[i]=mid,l=mid+1;
			else r=mid-1;
		}
	}
	while(q--){
		ri k,l,r;
		scanf("%d%d%d",&l,&r,&k);
		printf("%d\n",query(qL[k],qR[k],l,r));
	}
	return 0;
}