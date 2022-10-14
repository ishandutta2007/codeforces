#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=1000010;
int n,ans,a[N],f[N],sz[N];
struct edge{
	int x,y,w;
	int operator<(const edge&rhs)const{
		return w<rhs.w;
	}
};
vector<edge>e;
void init(int n){
	for(int i=1;i<=n;i++)
		f[i]=i,sz[i]=1;
}
int find(int x){
	return x^f[x]?f[x]=find(f[x]):x;
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n,init(n),e.resize(n-1);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(auto&i:e)
		cin>>i.x>>i.y,i.w=max(a[i.x],a[i.y]);
	sort(e.begin(),e.end());
	for(auto i:e){
		int x=find(i.x),y=find(i.y);
		ans+=sz[x]*sz[y]*i.w,sz[y]+=sz[x],f[x]=y;
	}
	init(n);
	for(auto&i:e)
		i.w=min(a[i.x],a[i.y]);
	sort(e.begin(),e.end());
	reverse(e.begin(),e.end());
	for(auto i:e){
		int x=find(i.x),y=find(i.y);
		ans-=sz[x]*sz[y]*i.w,sz[y]+=sz[x],f[x]=y;
	}
	cout<<ans<<"\n";
}