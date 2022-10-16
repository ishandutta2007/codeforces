#include <bits/stdc++.h>
#define int long long
#define mid ((l+r)>>1)
using namespace std;
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> vc[n+1];
		int a[n+1];
		for(int i=1;i<=n;i++) cin>>a[i];
		int b[n+3];
		for(int i=0;i<=n+2;i++) b[i]=0;
		for(int i=1;i<=n;i++) b[a[i]]++;
		for(int i=n;i>=0;i--) b[i]+=b[i+1];
		int k=0;
		for(int i=0;i<=n;i++){
			if(b[i+1]==i){
				k=i;
				break;
			}
		}
		int ans[n+1],deg[n+1],id[n+1],top=0;
		for(int i=1;i<=n;i++) deg[i]=id[i]=0;
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
		for(int i=1;i<=n;i++){
			if(a[i]==n+1||a[i]==0){
				;
			}
			else{
				vc[a[i]].push_back(i);
				deg[i]++;
				id[a[i]]++;
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i]==n+1||a[i]==0) q.push(make_pair(id[i],i));
		}		
		while(!q.empty()){
			auto f=q.top();
			q.pop();
			ans[++top]=f.second;
			for(auto v:vc[f.second]){
				deg[v]--;
				if(!deg[v]){
					q.push(make_pair(id[v],v));
				}
			}
		}
		cout<<k<<endl;
		for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
		cout<<endl;
	}
	return 0;
}