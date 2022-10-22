#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000

vector<int> l,r;
int cnt = 1;
void dfs(vector<vector<int>> &E,int now,int parent){

	for(int i = 0;i<E[now].size();i++){
		int to = E[now][i];
		if(to==parent)continue;
		l[to] = cnt;
		cnt++;
	}
	
	r[now] = cnt;
	cnt++;
	
	for(int i=E[now].size()-1;i>=0;i--){
		int to = E[now][i];
		if(to==parent)continue;
		dfs(E,to,now);
	}
	
	
}

int main(){
	
	int n;
	cin>>n;
	
	l.resize(n),r.resize(n);
	
	vector<vector<int>> E(n,vector<int>());
	
	for(int i=0;i<n-1;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		a--;b--;
		E[a].push_back(b);
		E[b].push_back(a);
	}
	l[0] = cnt;
	cnt++;
	dfs(E,0,-1);
	
	for(int i=0;i<n;i++){
		printf("%d %d\n",l[i],r[i]);
	}
	
	
	return 0;
}