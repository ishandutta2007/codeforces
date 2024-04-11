#include<cstdio>
#include<algorithm>
#include<cstring>
#include<stack>
typedef long long ll;
using namespace std;
const int MAXN=2e5+5,MAXM=2e7;
int n,q,fu[MAXN],re[MAXN],tm[MAXN];
int p[MAXN];
inline bool cmp(int a,int b){
	return tm[a]<tm[b];
}
#define ls lc[k],l,mid
#define rs rc[k],mid+1,r
int cntp,rt[MAXN],lc[MAXM],rc[MAXM];
ll sum[MAXM][2];
inline void pushup(int k){
	sum[k][0]=sum[lc[k]][0]+sum[rc[k]][0];
	sum[k][1]=sum[lc[k]][1]+sum[rc[k]][1];
}
void Build(int &k,int l,int r){
	k=++cntp;
	if(l==r){
		sum[k][1]=re[l];
		return ;
	}
	int mid=l+r>>1;
	Build(ls);
	Build(rs);
	pushup(k);
	return ;
}
void Modify(int p,int &k,int l,int r,int x){
	k=++cntp;
	if(l==r){
		sum[k][0]=fu[l];
		return ;
	}
	int mid=l+r>>1;
	if(x<=mid) Modify(lc[p],ls,x),rc[k]=rc[p];
	else Modify(rc[p],rs,x),lc[k]=lc[p];
	pushup(k);
	return ;
}
int Query(int k,int l,int r,int x,int y,int t,ll &h){
	/*
	int f=x;
	while(f<=y){
		ll a=min((ll)fu[f],1ll*re[f]*t);
		if(h>=a) h-=a;
		else break;
		f++;
	}
	return f;
	*/
	if(x<=l&&r<=y){
		ll d=sum[k][1]*t+sum[k][0];
		if(d<=h){
			h-=d;
			return r+1;
		}
		if(l==r) return l;
		int mid=l+r>>1,res=Query(ls,x,y,t,h);
		if(res<=mid) return res;
		return Query(rs,x,y,t,h);
	}
	int mid=l+r>>1,res=0;
	if(x<=mid){
		res=Query(ls,x,y,t,h);
		if(res<=mid) return res;
	}
	if(mid<y) res=Query(rs,x,y,t,h);
	return res;
}
struct node{
	int l,r,t,h;
};
stack<node> stk;
ll ans;
int main(){
	//freopen("in2.txt","r",stdin);
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d%d",fu+i,re+i);
		p[i]=i;
		tm[i]=(fu[i]+re[i]-1)/re[i];
	}
	sort(p+1,p+n+1,cmp);
	Build(rt[0],1,n);
	for(int i=1; i<=n; i++){
		tm[i]=(fu[p[i]]+re[p[i]]-1)/re[p[i]];
		Modify(rt[i-1],rt[i],1,n,p[i]);
	}
	for(int i=n; i; i--)
		stk.push(node{i,i,0,fu[i]});
	scanf("%d",&q);
	while(q--){
		int t;
		ll h;
		scanf("%d%lld",&t,&h);
		while(!stk.empty()){
			node a=stk.top();
			stk.pop();
			if(~a.h){
				int x=a.l;
				a.h=min((ll)fu[x],1ll*re[x]*(t-a.t)+a.h);
				if(h<=a.h){
					a.h-=h;
					stk.push(node{x,x,t,a.h});
					if(x>1) stk.push(node{1,x-1,t,-1});
					break;
				}
				h-=a.h;
			}else{
				int w=upper_bound(tm+1,tm+n+1,t-a.t)-tm-1;
				int k=Query(rt[w],1,n,a.l,a.r,t-a.t,h);
				if(k<=a.r){
					if(k<a.r) stk.push(node{k+1,a.r,a.t,-1});
					a.h=min((ll)fu[k],1ll*re[k]*(t-a.t))-h;
					stk.push(node{k,k,t,a.h});
					if(k>1) stk.push(node{1,k-1,t,-1});
					break;
				}
			}
		}
		if(stk.empty()) ans+=h,stk.push(node{1,n,t,-1});
	}
	printf("%lld\n",ans);
	return 0;
}