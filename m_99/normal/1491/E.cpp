#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001


vector<int> F;
vector<bool> ok;
void DFS(vector<vector<int>> &E,vector<int> &cnt,int cur,int p){
	rep(i,E[cur].size()){
		int to = E[cur][i];
		if(to==p)continue;
		DFS(E,cnt,to,cur);
		cnt[cur] += cnt[to];
	}
}

void DFS2(vector<vector<int>> &E,vector<int> &color,int cur,int p,int x,bool f=false){
	if(x==cur)f=true;
	if(f)color[cur] = 1;
	rep(i,E[cur].size()){
		int to = E[cur][i];
		if(to==p)continue;
		DFS2(E,color,to,cur,x,f);
	}	
}

bool dfs(vector<vector<int>> E){

	if(E.size()<=3)return true;
	
	vector<int> cnt(E.size(),1);
	
	DFS(E,cnt,0,-1);
	int ind = -1;
	rep(i,E.size()){
		if(ok[cnt[i]]&&ok[E.size()-cnt[i]]){
			ind = i;
			break;
		}
	}
	if(ind==-1)return false;
	
	vector<int> color(E.size(),0);
	
	DFS2(E,color,0,-1,ind);
	
	vector<int> inds(E.size());
	int c[2] = {0,0};
	rep(i,E.size()){
		inds[i] = c[color[i]];
		c[color[i]]++;
	}
	
	vector<vector<int>> Ea(c[0]),Eb(c[1]);
	
	rep(i,E.size()){
		int x = inds[i];
		rep(j,E[i].size()){
			int to = E[i][j];
			if(color[i]!=color[to])continue;
			int y = inds[to];
			if(color[i]==0){
				Ea[x].push_back(y);
			}
			else{
				Eb[x].push_back(y);
			}
		}
	}
	return dfs(Ea)&&dfs(Eb);;
}

int main(){
	
	
	F.push_back(1);
	F.push_back(2);
	
	while(F.back()<=200000){
		F.push_back(F.back() + F[F.size()-2]);
	}
	F.pop_back();
	ok.resize(200001,false);
	rep(i,F.size()){
		ok[F[i]] = true;
	}
	int n;
	scanf("%d",&n);
	
	vector<vector<int>> E(n);
	rep(i,n-1){
		int u,v;
		scanf("%d %d",&u,&v);
		u--;v--;
		E[u].push_back(v);
		E[v].push_back(u);
	}
	
	if(!ok[n]){
		cout<<"No"<<endl;
		return 0;
	}
	
	if(dfs(E)){
		cout<<"Yes"<<endl;
	}
	else{
		cout<<"No"<<endl;
	}
	
    return 0;
}