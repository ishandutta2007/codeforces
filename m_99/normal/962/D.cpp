#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 2000000001


int main(){	

	int n;
	cin>>n;
	
	map<long long,set<int>> mp;
	set<long long> two;
	vector<int> a(n);
	rep(i,n){
		scanf("%d",&a[i]);
		mp[a[i]].insert(i);
		if(mp[a[i]].size()>=2){
			two.insert(a[i]);
		}
	}
	
	while(two.size()!=0){
		long long t = *(two.begin());
		two.erase(t);
		int x = *(mp[t].begin());
		mp[t].erase(x);
		int y = *(mp[t].begin());
		mp[t].erase(y);
		if(mp[t].size()>=2)two.insert(t);
		if(mp[t].size()==0)mp.erase(t);
		mp[t*2].insert(y);
		if(mp[t*2].size()>=2)two.insert(t*2);
	}
	
	vector<pair<int,long long>> ans;
	for(auto x:mp){
		for(auto y:x.second){
			ans.emplace_back(y,x.first);
		}
	}
	
	sort(ans.begin(),ans.end());
	cout<<ans.size()<<endl;
	
	rep(i,ans.size()){
		if(i!=0)printf(" ");
		printf("%lld",ans[i].second);
	}
	cout<<endl;
	
    return 0;
}