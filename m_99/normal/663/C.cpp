#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 2000000000000000000

vector<int> check(auto &E,auto &visited,int now){
	{
		queue<int> Q;
		Q.push(now);
		visited[now] = true;
		while(Q.size()!=0){
			int u = Q.front();
			Q.pop();
			for(int i=0;i<E[u].size();i++){
				int v = E[u][i].first;
				if(visited[v])continue;
				visited[v] = true;
				Q.push(v);
			}
		}
	}
	vector<int> ret(1,-1);
	for(int i=0;i<2;i++){
		map<int,int> color;
		color[now] = i;
		queue<int> Q;
		Q.push(now);
		bool f = true;
		while(Q.size()!=0&&f){
			int u = Q.front();
			Q.pop();
			for(int j=0;j<E[u].size();j++){
				int v = E[u][j].first;
				char c = E[u][j].second;
				int target=0;
				if(color[u]==0){
					if(c=='B')target=1;
				}
				else{
					if(c=='R')target=1;
				}
				
				if(!color.count(v)){
					color[v] = target;
					Q.push(v);
				}
				else{
					if(color[v]!=target){
						f=false;
						break;
					}
				}
			}
		}
		if(!f)continue;
		vector<int> temp;
		for(auto j:color){
			if(j.second==1)temp.push_back(j.first);
		}
		
		if(ret.size()==1&&ret[0]==-1)ret=  temp;
		else if(ret.size()>temp.size())ret = temp;
		
	}
	
	return ret;
}

int main(){
	
	
	int n,m;
	cin>>n>>m;
	
	vector<vector<pair<int,char>>> E(n,vector<pair<int,char>>());
	
	for(int i=0;i<m;i++){
		int a,b;
		char c;
		scanf("%d %d %c",&a,&b,&c);
		a--;b--;
		E[a].emplace_back(b,c);
		E[b].emplace_back(a,c);
		
	}
	vector<int> Ans(1,-1);
	
	for(int i=0;i<2;i++){
		
		vector<bool> visited(n,false);
		vector<int> ans;
		bool f = true;
		for(int j=0;j<n;j++){
			if(visited[j])continue;
			vector<int> ret = check(E,visited,j);
			if(ret.size()==1&&ret.back()==-1){
				f=false;
				break;
			}
			while(ret.size()!=0){
				ans.push_back(ret.back());
				ret.pop_back();
			}
		}
		
		if(f){
			if(Ans.size()==1&&Ans[0]==-1)Ans =  ans;
			else if(Ans.size()>ans.size())Ans = ans;
		}
		
		for(int j=0;j<n;j++){
			for(int k=0;k<E[j].size();k++){
				if(E[j][k].second=='R')E[j][k].second='B';
				else E[j][k].second = 'R';
			}
		}
	}

	if(Ans.size()==1&&Ans.back()==-1)cout<<-1<<endl;
	else{
		cout<<Ans.size()<<endl;
		for(int i=0;i<Ans.size();i++){
			if(i!=0)printf(" ");
			cout<<Ans[i]+1;
		}
		printf("\n");
	}
	
	return 0;
}