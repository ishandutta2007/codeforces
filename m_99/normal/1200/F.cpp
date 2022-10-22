#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x))%modulo)
#define Inf 10000000000000000



int main(){
	int n;
	cin>>n;
	vector<long long> k(n);
	for(int i=0;i<n;i++)cin>>k[i];
	vector<vector<int>> E(n,vector<int>(0));
	
	for(int i=0;i<n;i++){
		int m;cin>>m;
		
		for(int j=0;j<m;j++){
			int to;
			cin>>to;
			to--;
			E[i].push_back(to);
		}
	}
	
	vector<int> e(2520*n,-1);
	
	for(int i=0;i<2520*n;i++){
		int a = i/2520;
		int b = i%2520;
		
		if(E[a].size()==0)continue;
		int to_a = E[a][b%E[a].size()];
		int to_b = (b+k[to_a])%2520;
		if(to_b<0)to_b+=2520;
		e[i] = to_a*2520 + to_b;
		
	}
	
	vector<int> ans(2520*n,-1);
	
	for(int i=0;i<ans.size();i++){
		if(ans[i]!=-1)continue;
		vector<int> V(0);
		set<int> S;
		int now = i;
		int k = 0;
		while(true){
			V.push_back(now);
			S.insert(now);
			ans[now] = k;
			k++;
			now = e[now];
			
			if(ans[now]!=-1){
				if(S.find(now)==S.end()){
					k = ans[now];
					break;
				}
				else{
					set<int> SS;
					int x = k-ans[now];
					for(int j=0;j<x;j++){
						SS.insert(now/2520);
						now = e[now];
					}
					
					k = SS.size();
					break;
				}
			}
					
		}
		for(int j=0;j<V.size();j++){
			ans[V[j]] = k;
		}
	}
	
	int q;
	cin>>q;
	
	for(int i=0;i<q;i++){
		int x,y;
		cin>>x>>y;
		x--;
		y += k[x];
		y%=2520;
		if(y<0)y+=2520;
		
		
		cout<<ans[x*2520 + y]<<endl;
	}
	
	
	return 0;
}