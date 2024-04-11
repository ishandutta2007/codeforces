#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000000


int main(){
	
	int n;
	cin>>n;
	vector<pair<int,int>> ans;
	ans.emplace_back(0,0);
	ans.emplace_back(0,1);
	ans.emplace_back(1,0);
	ans.emplace_back(1,1);
	int y =1,x=1;
	
	for(int i=0;i<n;i++){
		ans.emplace_back(x+1,y);
		ans.emplace_back(x,y+1);
		ans.emplace_back(x+1,y+1);
		x++;y++;
	}
	
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++){
		cout<<ans[i].first<<' '<<ans[i].second<<endl;
	}
	
	return 0;
}