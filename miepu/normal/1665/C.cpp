#include<bits/stdc++.h>
#define int long long
const int N=1000050;
using namespace std;
int dg[N],vis[N];
void solve(){
	int n;cin>>n;
	for(int i=1;i<=n;i++)dg[i]=0;
	for(int i=2;i<=n;i++){
		int x,y;cin>>x;dg[x]++;
	}
	int l=1,r=n,res=n;
	while(l<=r){
		int mid=(l+r)>>1;
		for(int i=0;i<=n;i++)vis[i]=0;
		priority_queue<pair<int,int>>q;
		for(int i=1;i<=n;i++)if(dg[i])q.push({dg[i],i});
		q.push({1,0});
		for(int i=1;i<=mid;i++){
			if(q.empty())break;
			auto nw=q.top();q.pop();
			if(!vis[nw.second])nw.first-=mid-i+1,vis[nw.second]=1;
			else nw.first--;
			if(nw.first>0)q.push(nw); 
		}
		if(q.empty())res=mid,r=mid-1;
		else l=mid+1;
	}
	cout<<res<<endl;
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}