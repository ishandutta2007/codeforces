#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000000

struct unionfind{
	vector<int> data;
	vector<int> size;
	unionfind(int n){
		for(int i=0;i<n;i++){
			data.push_back(i);
			size.push_back(1);
		}
	}
	
	int find(int x){
		if(data[x]==x)return x;
		return data[x]=find(data[x]);
	}
	
	bool unite(int x,int y){
		x=find(x);y=find(y);
		if(x==y)return false;
		if(size[x]>size[y])swap(x,y);
		data[x]=y;
		size[y]+=size[x];
		return true;
	}
	
	bool check(int x,int y){
		return (find(x)==find(y));
	}
	
	int get_size(int x){
		int X = find(x);
		return size[X];
	}
};

void dfs(auto &E,int now,int parent,auto &ans){
	for(int i=0;i<E[now].size();i++){
		int to = E[now][i];
		if(to==parent)continue;
		ans.emplace_back('a'+to,'a'+now);
		dfs(E,to,now,ans);
	}
}

int main(){
	
	int n;
	cin>>n;
	
	string S,T;
	cin>>S>>T;
	
	vector<pair<char,char>> ans;
	unionfind uf(26);
	
	vector<vector<int>> E(26,vector<int>());
	
	for(int i=0;i<n;i++){
		int x = S[i]-'a';
		int y = T[i]-'a';
		
		if(uf.check(x,y))continue;
		E[x].push_back(y);
		E[y].push_back(x);
		uf.unite(x,y);
	}
	
	set<int> used;
	
	for(int i=0;i<26;i++){
		if(used.count(uf.find(i)))continue;
		dfs(E,i,-1,ans);
		used.insert(uf.find(i));
	}
	
	cout<<ans.size()<<endl;
	
	for(int i=0;i<ans.size();i++){
		cout<<ans[i].first<<' '<<ans[i].second<<endl;
	}
	
	return 0;
}