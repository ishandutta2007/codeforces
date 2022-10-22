#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x)+modulo)%modulo)
#define Inf 1000000000000


int main() {
	
	int t;
	cin>>t;
	
	for(int _=0;_<t;_++){
		int n;
		scanf("%d",&n);
		
		vector<vector<int>> V(n,vector<int>());
		set<int> S;
		for(int i=0;i<n;i++){
			int k;
			scanf("%d",&k);
			for(int j=0;j<k;j++){
				int x;
				scanf("%d",&x);
				x--;
				V[i].push_back(x);
			}
			S.insert(i);
		}
		
		int ans = -1;
		
		for(int i=0;i<n;i++){
			bool f = false;
			for(int j=0;j<V[i].size();j++){
				if(S.count(V[i][j])){
					f=true;
					S.erase(V[i][j]);
					break;
				}
			}
			if(!f)ans = i;
		}
		if(ans==-1){
			cout<<"OPTIMAL"<<endl;
		}
		else{
			cout<<"IMPROVE"<<endl;
			cout<<ans+1<<' '<<1+(*(S.begin()))<<endl;
		}
	}
	
    return 0;
}