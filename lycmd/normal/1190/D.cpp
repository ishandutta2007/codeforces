#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=233333;
int n,ans,cnt,p[N],tx[N],ty[N],x[N],y[N],vis[N],tr[N];
vector<int>vx,vy;
void add(int x,int y){
	for(;x<N;x+=x&-x)tr[x]+=y;
}
int ask(int x){
	int res=0;
	for(;x;x&=x-1)res+=tr[x];
	return res;
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>x[i]>>y[i],p[i]=i,
		vx.push_back(x[i]),vy.push_back(y[i]);
	sort(p+1,p+1+n,[&](int a,int b){
		return y[a]>y[b]||(y[a]==y[b]&&x[a]<x[b]);
	});
	for(int i=1;i<=n;i++)
		tx[i]=x[p[i]],ty[i]=y[p[i]];
	memcpy(x,tx,sizeof x);
	memcpy(y,ty,sizeof y);
	sort(vx.begin(),vx.end());
	sort(vy.begin(),vy.end());
	vx.erase(unique(vx.begin(),vx.end()),vx.end());
	vy.erase(unique(vy.begin(),vy.end()),vy.end());
	for(int i=1;i<=n;i++)
		x[i]=lower_bound(vx.begin(),vx.end(),x[i])-vx.begin()+2,
		y[i]=lower_bound(vy.begin(),vy.end(),y[i])-vy.begin()+2;
	for(int i=1;i<=n;i++){
		if(!vis[x[i]])
			cnt+=vis[x[i]]=1,add(x[i],1);
		ans+=ask(x[i])*((y[i]==y[i+1]?
			ask(x[i+1]-1):cnt)-ask(x[i])+1);
	}
	cout<<ans<<"\n";
}