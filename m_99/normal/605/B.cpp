#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000

int main(){

	int n,m;
	cin>>n>>m;
	
	vector<pair<int,int>> used,unused;
	
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		if(b==0){
			unused.emplace_back(a,i);
		}
		else{
			used.emplace_back(a,i);
		}
	}
	
	if(used.size()+1!=n){
		cout<<-1<<endl;
		return 0;
	}
	
	sort(used.begin(),used.end());
	
	vector<pair<int,int>> ans(m);
	
	for(int i=0;i<used.size();i++){
		ans[used[i].second] = make_pair(i,i+1);
	}
	
	multimap<int,pair<int,int>> remains;
	
	for(int i=0;i<n;i++){
		for(int j=i-2;j>=0;j--){
			remains.emplace(used[i-1].first,make_pair(i,j));
		}
		if(remains.size()>unused.size())break;
	}
	
	sort(unused.rbegin(),unused.rend());
	for(int i=0;i<unused.size();i++){
		auto it = remains.upper_bound(unused[i].first);
		if(it==remains.begin()){
			cout<<-1<<endl;
			return 0;
		}
		it--;
		ans[unused[i].second] = make_pair(it->second.first,it->second.second);
		remains.erase(it);
	}
	
	for(int i=0;i<ans.size();i++){
		printf("%d %d\n",ans[i].first+1,ans[i].second+1);
	}

	return 0;
}