#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000

vector<vector<int>> get(vector<string> S,char c){
	vector<vector<int>> ret(S.size(),vector<int>(S[0].size(),Inf));
	
	queue<pair<int,int>> Q;
	rep(i,S.size()){
		rep(j,S[i].size()){
			if(S[i][j]==c){
				ret[i][j] = 0;
				Q.emplace(i,j);
			}
		}
	}
	
	while(Q.size()!=0){
		int y = Q.front().first;
		int x = Q.front().second;
		Q.pop();
		rep(i,4){
			int yy = y,xx = x;
			if(i==0)yy++;
			if(i==1)yy--;
			if(i==2)xx++;
			if(i==3)xx--;
			if(yy<0||yy>=S.size()||xx<0||xx>=S[0].size())continue;
			if(ret[yy][xx]!=Inf)continue;
			if(S[yy][xx]=='#')continue;
			ret[yy][xx] = ret[y][x] + 1;
			Q.emplace(yy,xx);
		}
	}
	
	return ret;
}

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
	
	vector<string> S(n);
	rep(i,n)cin>>S[i];
	
	vector<vector<vector<int>>> dis(3);
	rep(i,3){
		dis[i] = get(S,'1'+i);
	}
	
	unionfind uf(3);
	
	rep(i,n){
		rep(j,m){
			if(i!=n-1){
				if(isdigit(S[i][j])&&isdigit(S[i+1][j])){
					uf.unite(S[i][j]-'1',S[i+1][j]-'1');
				}
			}
			if(j!=m-1){
				if(isdigit(S[i][j])&&isdigit(S[i][j+1])){
					uf.unite(S[i][j]-'1',S[i][j+1]-'1');
				}
			}
		}
	}
	
	int ans = Inf;
	vector<vector<int>> mini(3,vector<int>(3,Inf));
	rep(i,n){
		rep(j,m){
			if(S[i][j]=='.'){
				ans = min(ans,dis[0][i][j] + dis[1][i][j] + dis[2][i][j]-2);
				rep(a,3){
					rep(b,3){
						mini[a][b] = min(mini[a][b],dis[a][i][j] + dis[b][i][j]-1);
					}
				}
			}
		}
	}
	
	if(uf.get_size(0)==3)ans = 0;
	
	rep(i,3){
		int a = i;
		int b = (i+1)%3;
		ans = min(ans,mini[a][b] + mini[b][(b+1)%3]);
		if(uf.check(a,b)){
			rep(j,n){
				rep(k,m){
					if(S[j][k]=='.'){
						ans = min(ans,dis[(b+1)%3][j][k] + min(dis[a][j][k],dis[b][j][k])-1);
					}
				}
			}
			
		}
	}
	if(ans==Inf)cout<<-1<<endl;
	else cout<<ans<<endl;
	
    return 0;
}