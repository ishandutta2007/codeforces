#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000000



int main(){
	
	vector<int> cnt(4);
	int S = 0;
	for(int i=0;i<4;i++){
		cin>>cnt[i];
		S += cnt[i];
	}
	
	for(int i=0;i<4;i++){
		vector<int> ans;
		vector<int> C = cnt;
		if(C[i]==0)continue;
		C[i]--;
		ans.push_back(i);
		while(true){
			if(ans.back()!=0&&C[ans.back()-1]!=0){
				ans.push_back(ans.back()-1);
				C[ans.back()]--;
				continue;
			}
			if(ans.back()!=3&&C[ans.back()+1]!=0){
				ans.push_back(ans.back()+1);
				C[ans.back()]--;
				continue;
			}
			break;
		}
		if(S!=ans.size())continue;
		cout<<"YES"<<endl;
		for(int j=0;j<ans.size();j++){
			
			if(j!=0)cout<<' ';
			cout<<ans[j];
		}
		cout<<endl;
		return 0;
		
	}
	
	cout<<"NO"<<endl;
	
	
	return 0;
}