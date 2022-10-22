#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

vector<vector<int>> inds;
string s;
int k;
vector<string> S;
int n;
void Put(){
	cout<<S.size()<<endl;
	rep(i,S.size())cout<<S[i]<<endl;
	exit(0);
}

void dfs(int cur){
	if(cur==n){
		S.push_back(s);
		if(S.size()==k){
			Put();
		}
		return;
	}
	rep(i,inds[cur].size()){
		s[inds[cur][i]] = '1';
		dfs(cur+1);
		s[inds[cur][i]] = '0';
	}
}

int main(){
	
	int m;
	scanf("%d %d %d",&n,&m,&k);
	
	vector<int> a(m),b(m);
	vector<vector<int>> E(n);
	rep(i,m){
		scanf("%d %d",&a[i],&b[i]);
		a[i]--;b[i]--;
		E[a[i]].push_back(b[i]);
		E[b[i]].push_back(a[i]);
	}
	
	queue<int> Q;
	Q.push(0);
	vector<int> dis(n,Inf);
	dis[0] = 0;
	
	while(Q.size()>0){
		int u = Q.front();
		Q.pop();
		rep(i,E[u].size()){
			int v = E[u][i];
			if(dis[v]==Inf){
				dis[v] = dis[u]+1;
				Q.push(v);
			}
		}
	}
	
	s.resize(m,'0');
	inds.resize(n);
	rep(i,m){
		
		if(dis[a[i]]+1==dis[b[i]]){
			inds[b[i]].push_back(i);
		}
		if(dis[b[i]]+1==dis[a[i]]){
			inds[a[i]].push_back(i);
		}
	}
	//cout<<'a'<<endl;
	dfs(1);
	
	Put();
	
	return 0;
}