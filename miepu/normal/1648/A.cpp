#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

int n,m;
map<int,vector<pair<int,int>>>vis; 

void solve(){
	cin>>n>>m;
	int res=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int x;cin>>x;
			vis[x].push_back({i,j});
		}
	}
	for(auto x:vis){
		int sum=0,num=0;
		sort(x.second.begin(),x.second.end());
		for(auto y:x.second){
			res+=y.first*num;
			res-=sum;
			sum+=y.first;
			num++;
		}
		sort(x.second.begin(),x.second.end(),
		[&](pair<int,int>a,pair<int,int>b){return a.second<b.second;});
		sum=0,num=0;
		for(auto y:x.second){
			res+=y.second*num;
			res-=sum;
			sum+=y.second;
			num++;
		}
	}
	cout<<res<<endl;
}

main(){
	int _T=1;//cin>>_T;
	while(_T--)solve();
}