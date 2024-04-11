#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000000

int main(){
	
	long long u,v;
	cin>>u>>v;
	
	if(u==0&&v==0){
		cout<<0<<endl;
		return 0;
	}
	
	if(u==v){
		cout<<1<<endl;
		cout<<u<<endl;
		return 0;
	}
	
	if(u>v){
		cout<<-1<<endl;
		return 0;
	}
	
	vector<long long> ans;
	
	if((v-u)%2==1){
		cout<<-1<<endl;
		return 0;
	}
	
	
	ans.push_back((v-u)/2);
	ans.push_back((v-u)/2);
	ans.push_back(u);
	
	if((ans.back()^ans[1])==ans.back()+ans[1]){
		ans[1] ^= ans.back();
		ans.pop_back();
	}
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++){
		if(i!=0)cout<<' ';
		cout<<ans[i];
	}
	cout<<endl;
	
	
	return 0;
}