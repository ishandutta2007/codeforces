#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=1e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
int a[maxn],l[maxn],lst[maxn<<2],n,r[maxn];
bool vis[maxn];
void modify(int p,int l,int r,int k,int v){
	if(l==r){lst[p]=v;return;}
	ri mid=l+r>>1;
	k<=mid?modify(p<<1,l,mid,k,v):modify(p<<1|1,mid+1,r,k,v);
	lst[p]=min(lst[p<<1],lst[p<<1|1]);
}
int query(int p,int l,int r,int k){
	if(l==r)return lst[p];
	ri mid=l+r>>1;
	return k<=mid?query(p<<1,l,mid,k):query(p<<1|1,mid+1,r,k);
}
int query_(int p,int l,int r,int v){
	if(l==r)return lst[p]<v?l:0;
	ri mid=l+r>>1;
	return lst[p<<1]<v?query_(p<<1,l,mid,v):query_(p<<1|1,mid+1,r,v);
}
signed main(){
	scanf("%d",&n);
	for(ri i=1;i<=n;++i){
		scanf("%d",a+i);
		if(a[i]>1){
			if(!l[1])l[1]=i;
			r[1]=i,vis[1]=true;
		}
		modify(1,1,n+1,a[i],i);
		if(l[a[i]]){
			ri lst=r[a[i]];
			while(lst>=l[a[i]]){
				ri val=query_(1,1,n+1,lst),pos=query(1,1,n+1,val);
				l[val]=pos+1,r[val]=lst,vis[val]=true;
				lst=pos;
			}
			l[a[i]]=r[a[i]]=0;
		}
		if(a[i]==1){
			if(!l[2])l[2]=i;
			r[2]=i,vis[2]=true;
		}
	}
	for(ri ans=1;;++ans)
		if(!vis[ans])
			return printf("%d",ans),0;
	return 0;
}