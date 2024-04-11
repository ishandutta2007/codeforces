#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x)+modulo)%modulo)
#define Inf 10000000000000000

int main() {
	
	int t;
	cin>>t;
	
	vector<int> P = {2,3,5,7,11,13,17,19,23,29,31};
	
	for(int _=0;_<t;_++){
		int n;
		cin>>n;
		
		map<int,vector<int>> mp;
		
		for(int i=0;i<n;i++){
			int a;
			cin>>a;
			for(int j=0;j<P.size();j++){
				if(a%P[j]==0){
					mp[j].push_back(i);
					break;
				}
			}
		}
		
		cout<<mp.size()<<endl;
		vector<int> ans(n);
		int now = 1;
		for(auto a:mp){
			for(int i=0;i<a.second.size();i++){
				ans[a.second[i]]=now;
			}
			now++;
		}
		
		for(int i=0;i<n;i++){
			if(i!=0)cout<<' ';
			cout<<ans[i];
		}
		cout<<endl;
	}
	
    return 0;
}