#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000000


int main(){
	
	long long k;
	cin>>k;
	k--;
	string S = "codeforces";
	
	vector<int> ans(S.size(),1);
	long long now = 0;
	
	while(true){
		long long t = k;
		for(int i=0;i<ans.size();i++){
			t/=ans[i];
		}
		if(t<=0)break;
		ans[now] ++;
		now ++;
		if(now==ans.size())now=0;
	}
	
	for(int i=0;i<S.size();i++){
		for(int j=0;j<ans[i];j++)cout<<S[i];
	}
	cout<<endl;
	
	return 0;
}