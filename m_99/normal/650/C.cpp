#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000

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

int main(){
	
	int n,m;
	cin>>n>>m;
	
	vector<vector<int>> a(n,vector<int>(m));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	
	unionfind uf(n*m);
	
	for(int i=0;i<n;i++){
		map<int,int> mp;
		for(int j=0;j<m;j++){
			if(mp.count(a[i][j])){
				uf.unite(i*m+j,mp[a[i][j]]);
			}
			mp[a[i][j]]=i*m+j;
		}
	}
	
	for(int i=0;i<m;i++){
		map<int,int> mp;
		for(int j=0;j<n;j++){
			if(mp.count(a[j][i])){
				uf.unite(j*m+i,mp[a[j][i]]);
			}
			mp[a[j][i]]=j*m+i;
		}
	}
	
	vector<pair<int,int>> VC;
	vector<vector<pair<int,int>>> pos(n*m,vector<pair<int,int>>());
	
	for(int i=0;i<n*m;i++){
		int y = i/m,x = i%m;
		int u = uf.find(i);
		if(pos[u].size()==0){
			VC.emplace_back(a[y][x],u);
		}
		pos[uf.find(i)].emplace_back(y,x);
	}
	
	sort(VC.begin(),VC.end());
	
	vector<vector<int>> ans(n,vector<int>(m,0));
	vector<int> MR(n,0),MC(m,0);
	
	for(int i=0;i<VC.size();i++){
		int u = VC[i].second;
		int maxi = 1;
		for(int j=0;j<pos[u].size();j++){
			maxi = max({maxi,MR[pos[u][j].first]+1,MC[pos[u][j].second]+1});
		}
		for(int j=0;j<pos[u].size();j++){
			ans[pos[u][j].first][pos[u][j].second]=maxi;
			MR[pos[u][j].first]=maxi;
			MC[pos[u][j].second]=maxi;
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(j!=0)printf(" ");
			printf("%d",ans[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}