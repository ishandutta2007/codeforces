#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000

int main(){

	int t;
	cin>>t;
	
	for(int _=0;_<t;_++){
		string S,T;
		cin>>S>>T;
		
		vector<vector<int>> ind(26,vector<int>());
		
		for(int i=0;i<S.size();i++){
			ind[S[i]-'a'].push_back(i);
		}
		
		int now = Inf;
		int ans = 0;
		for(int i=0;i<T.size();i++){
			int x = T[i] - 'a';
			if(ind[x].size()==0){
				ans = -1;
				break;
			}
			auto it = lower_bound(ind[x].begin(),ind[x].end(),now);
			if(it == ind[x].end()){
				now = 0;
				ans ++;
				i--;
				continue;
			}
			now = (*it);
			now++;
		}
		
		cout<<ans<<endl;
	}
	
	return 0;
}