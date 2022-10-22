#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000


int main(){
	
	string S;
	cin>>S;
	
	vector<int> ind1,ind2;
	
	for(int i=0;i<S.size();i++){
		if(S[i]=='('){
			ind1.push_back(i);
		}
		else{
			ind2.push_back(i);
		}
	}
	
	//reverse(ind2.begin(),ind2.end());
	
	vector<int> ans;
	
	for(int i=0;i<ind1.size();i++){
		if(ind2.size()==0)break;
		if(ind1[i] < ind2.back()){
			ans.push_back(ind1[i]);
			ans.push_back(ind2.back());
			ind2.pop_back();
		}
	}
	
	if(ans.size()==0){
		cout<<0<<endl;
		return 0;
	}
	
	cout<<1<<endl;
	cout<<ans.size()<<endl;
	
	sort(ans.begin(),ans.end());
	
	for(int i=0;i<ans.size();i++){
		if(i!=0)cout<<' ';
		cout<<ans[i]+1;
	}
	cout<<endl;
	
	return 0;
}