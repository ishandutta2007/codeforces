#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=4e5+10;
template<class T>inline void ckmax(T &x,const T &y){if(x<y)x=y;}
namespace SGT{
	struct node{
		int ls,rs,sum;
	}t[maxn*20];
	int cur;
	int insert(int p,int l,int r,int k,int v){
		t[++cur]=t[p];
		p=cur;
		t[p].sum+=v;
		if(l==r)return p;
		ri mid=l+r>>1;
		if(k<=mid)t[p].ls=insert(t[p].ls,l,mid,k,v);
		else t[p].rs=insert(t[p].rs,mid+1,r,k,v);
		return p;
	}
	int query(int p1,int p2,int l,int r,int k){
		if(l==r)return t[p2].sum-t[p1].sum;
		ri mid=l+r>>1;
		if(k<=mid)return query(t[p1].ls,t[p2].ls,l,mid,k);
		else return t[t[p2].ls].sum-t[t[p1].ls].sum+query(t[p1].rs,t[p2].rs,mid+1,r,k);
	}
	int n,rt[maxn];
	inline int query(int l,int r,int ql,int qr){
		return query(rt[l-1],rt[r],0,n,qr)-query(rt[l-1],rt[r],0,n,ql-1);
	}
}
using SGT::n;
using SGT::rt;
int cnt[maxn],mx,rk[maxn],sa[maxn],tmp[maxn];
char s[maxn];
inline void base_sort(){
	memset(cnt,0,sizeof(int)*(mx+1));
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
inline int matchl(int l,int r,int len,char ch){
	ri ret=-1;
	while(l<=r){
		ri mid=l+r>>1;
		if(s[sa[mid]+len-1]==ch)ret=mid,r=mid-1;
		else if(s[sa[mid]+len-1]>ch)r=mid-1;
		else l=mid+1;
	}
	return ret;
}
inline int matchr(int l,int r,int len,char ch){
	ri ret=-1;
	while(l<=r){
		ri mid=l+r>>1;
		if(s[sa[mid]+len-1]==ch)ret=mid,l=mid+1;
		else r=mid-1;
	}
	return ret;
}
int m,len[maxn],pos[maxn],q,ql,qL[maxn],qr,qR[maxn];
char t[maxn];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	suffix_sort();
	for(ri i=1;i<=n;++i)rt[i]=SGT::insert(rt[i-1],0,n,sa[i],1);
	scanf("%d",&q);
	while(q--){
		scanf("%d%d%s",&ql,&qr,t+1);
		m=strlen(t+1);
		ri ans1=-1,ans2=-1,L=1,R=n;
		for(ri i=0;i<=min(m,qr-ql);++i){
			if(i){
				L=matchl(L,R,i,t[i]);
				if(L==-1)break;
				R=matchr(L,R,i,t[i]);
			}
			for(ri j=max(t[i+1]+1,(int)'a');j<='z';++j){
				ri tmp1=matchl(L,R,i+1,j);
				if(tmp1!=-1){
					ri tmp2=matchr(tmp1,R,i+1,j);
					if(SGT::query(tmp1,tmp2,ql,qr-i)){
						ans1=i,ans2=j;
						break;
					}
				}
			}
		}
		if(ans1==-1||ans2==-1)puts("-1");
		else{
			for(ri i=1;i<=ans1;++i)putchar(t[i]);
			putchar(ans2),putchar(10);
		}
		for(ri i=1;i<=m;++i)t[i]=0;
	}
	return 0;
}