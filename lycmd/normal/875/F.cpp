#include<bits/stdc++.h>
using namespace std;
int const N=200010;
int n,m,ans,f[N],flg[N];
struct edge{
	int x,y,w;
	int operator<(const edge&rhs)const{
		return w>rhs.w;
	}
};
vector<edge>e;
int find(int x){
	return x^f[x]?f[x]=find(f[x]):x;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m,e.resize(m);
	for(int i=1;i<=n;i++)
		f[i]=i,flg[i]=0;
	for(auto&i:e)
		cin>>i.x>>i.y>>i.w;
	sort(e.begin(),e.end());
	for(const edge&i:e){
		int fx=find(i.x),fy=find(i.y);
		if(fx==fy){
			if(!flg[fx])
				ans+=i.w,flg[fx]=1;
		}else{
			if(!flg[fx]||!flg[fy])
				ans+=i.w,f[fx]=fy,flg[fy]|=flg[fx];
		}
	}
	cout<<ans<<"\n";
}