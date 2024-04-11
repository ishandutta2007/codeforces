#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],vis[1005];
vector<pair<int,int> >ans;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	while(1.0*clock()/CLOCKS_PER_SEC<0.9){
		sort(a+1,a+n+1);
		int pos=1;
		while(pos<=n&&a[pos]*3<=m)pos++;
		random_shuffle(a+pos,a+n+1);
		memset(vis,0,sizeof vis);
		for(int i=n;i>=1;i--)if(!vis[i]){
			if(a[i]*3ll<=m){
				ans.push_back(make_pair(2*a[i],3*a[i]));
				vis[i]=1;continue;
			}
			bool hv=0;
			for(int j=i-1;j>=1;j--)if(!vis[j]&&a[i]%a[j]==0&&2ll*a[i]+a[j]<=m){
				vis[j]=1;vis[i]=1;ans.push_back(make_pair(a[j]+a[i]+a[i],a[j]+a[i]));hv=1;break;
			}
			if(!hv){
				ans.clear();
				break;
			}
		}
		if(!ans.size())continue;
		cout<<ans.size()<<endl;
		for(auto p:ans)cout<<p.first<<" "<<p.second<<endl;
		return 0;
	}
	puts("-1");
	return 0;
}