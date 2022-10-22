#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000

long long B;

long long dfs(vector<vector<pair<int,int>>> &E,int now,int parent){
	long long ret = 1;
	for(int i=0;i<E[now].size();i++){
		int to = E[now][i].first;
		if(to==parent)continue;
		long long K = dfs(E,to,now);
		long long X = min((long long)E.size()-K,K);
		B += X * E[now][i].second;
		ret += K;
	}
	return ret;
}


int main(){
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++){
		int k;
		cin>>k;
		
		vector<vector<pair<int,int>>> E(2*k,vector<pair<int,int>>());
		vector<int> jisuu(2*k,0);
		long long G = 0;
		for(int j=0;j<2*k-1;j++){
			int a,b,t;
			scanf("%d %d %d",&a,&b,&t);
			a--;
			b--;
			E[a].emplace_back(b,t);
			E[b].emplace_back(a,t);
			jisuu[a]++;
			jisuu[b]++;
			G += (long long)t;
		}
		vector<int> num(2*k,0);
		queue<int> Q;
		for(int j=0;j<2*k;j++){
			num[j] = 1;
			if(jisuu[j]==1){
				Q.push(j);
				jisuu[j] = 0;
			}
		}
		
		while(Q.size()!=0){
			int from = Q.front();
			Q.pop();
			jisuu[from] = 0;
			for(int j=0;j<E[from].size();j++){
				int to = E[from][j].first;
				if(jisuu[to]==0)continue;
				jisuu[to] --;
				num[to] += num[from];
				num[to] %= 2;
				if(jisuu[to]==1){
					Q.push(to);
				}
				if(num[from]%2==0){
					G -= (long long)E[from][j].second;
				}
				break;
			}
		}
		
		B = 0;
		dfs(E,0,-1);
		cout<<G<<' '<<B<<endl;
		
		
	}
	
	return 0;
}