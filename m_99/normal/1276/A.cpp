#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000

int main(){
	
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++){
		string s;
		cin>>s;
		vector<int> ans;
		for(int j=0;j<s.size();j++){
			if(j+4 < s.size()&&s.substr(j,5)=="twone"){
				ans.push_back(j + 2);
				j += 4;
				continue;
			}
			if(j+2 < s.size()&&s.substr(j,3)=="two"){
				ans.push_back(j+1);
				j+=2;
				continue;
			}
			if(j+2 < s.size()&&s.substr(j,3)=="one"){
				ans.push_back(j+1);
				j+=2;
				continue;
			}
		}
		cout<<ans.size()<<endl;
		for(int j=0;j<ans.size();j++){
			if(j!=0)cout<<' ';
			cout<<ans[j]+1;
		}
		cout<<endl;
			
	}
	
	return 0;
}