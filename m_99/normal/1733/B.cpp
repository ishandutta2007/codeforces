#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf32 1000000001
#define Inf64 4000000000000000001


int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n,x,y;
		cin>>n>>x>>y;
		if(x!=0&&y!=0){
			cout<<-1<<endl;
			continue;
		}
		int z = max(x,y);
		if(z==0){
			cout<<-1<<endl;
			continue;
		}
		if((n-1)%z!=0){
			cout<<-1<<endl;
			continue;
		}
		int cur = 1;
		int w = (n-1) / z;
		vector<int> ans;
		rep(i,w){
			rep(j,z)ans.push_back(cur);
			if(cur==1)cur += z+1;
			else cur += z;
		}
		rep(i,ans.size()){
			if(i!=0)cout<<' ';
			cout<<ans[i];
		}
		cout<<endl;
	}
	
	return 0;
}