#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxm=310,maxn=15e4+10;
int m,n;
struct node{int a,b,t;inline bool operator<(const node &k)const{return t<k.t;}}a[maxm];
ll d,f[maxn],g[maxn];
void solve(int l,int r,int L,int R,int id){
	if(l>r||L>R)return;
	ri mid=l+r>>1,pos=0;
	for(ri i=L;i<=R;++i){
		if(abs(i-mid)>d*(a[id].t-a[id-1].t))continue;
		ll val=f[i]+a[id].b-max(abs(a[id].a-mid),0);
		if(val>g[mid])g[mid]=val,pos=i;
	}
	solve(l,mid-1,L,pos,id);
	solve(mid+1,r,pos,R,id);
}
int main(){
	scanf("%d%d%lld",&m,&n,&d);
	for(ri i=1;i<=n;++i)scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].t);
	sort(a+1,a+n+1);
	for(ri i=1;i<=n;++i){
		memset(g,-0x3f,m+1<<3);
		solve(1,m,1,m,i);
		memcpy(f,g,m+1<<3);
	}
	printf("%lld",*max_element(f+1,f+m+1));
	return 0;
}