#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000

int main(){
	
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++){
		int n,m,a,b;
		cin>>n>>m>>a>>b;
		a--;b--;
		vector<vector<int>> E(n,vector<int>());
		
		for(int j=0;j<m;j++){
			int x,y;
			cin>>x>>y;
			x--;y--;
			E[x].push_back(y);
			E[y].push_back(x);
		}
		
		vector<bool> visited1(n,false),visited2(n,false);
		queue<int> Q;
		Q.push(a);
		visited1[a] = true;
		while(Q.size()!=0){
			int from = Q.front();
			Q.pop();
			if(from==b)continue;
			for(int j=0;j<E[from].size();j++){
				int to = E[from][j];
				if(visited1[to])continue;
				visited1[to] = true;
				Q.push(to);
			}
		}
		
		Q.push(b);
		visited2[b] = true;
		while(Q.size()!=0){
			int from = Q.front();
			Q.pop();
			if(from==a)continue;
			for(int j=0;j<E[from].size();j++){
				int to = E[from][j];
				if(visited2[to])continue;
				visited2[to] = true;
				Q.push(to);
			}
		}
		
		long long K1 = 0,K2 = 0;
		for(int j=0;j<n;j++){
			if(visited1[j]&&!visited2[j])K1++;
			if(!visited1[j]&&visited2[j])K2++;
		}
		
		cout<<K1*K2<<endl;
			
	}
	
	return 0;
}