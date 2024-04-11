#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000

bool check(vector<vector<int>> E){
	vector<int> color(E.size(),-1);
	rep(i,E.size()){
		if(color[i]!=-1)continue;
		queue<int> Q;
		Q.push(i);
		color[i] = 0;
		
		while(Q.size()>0){
			int u = Q.front();
			Q.pop();
			
			rep(j,E[u].size()){
				int v = E[u][j];
				if(color[v]==-1){
					color[v] = color[u]^1;
					Q.push(v);
				}
				else{
					if(color[v]==color[u])return false;
				}
			}
		}
	}
	return true;
}

int main(){
	
	int n,m;
	cin>>n>>m;
	
	vector<vector<int>> E(n,vector<int>());
	vector<vector<int>> dis(n,vector<int>(n,Inf));
	
	rep(i,n){
		dis[i][i] = 0;
	}
	
	rep(i,m){
		int x,y,z;
		cin>>x>>y>>z;
		x--;y--;
		
		if(z==0){
			dis[x][y] = 1;
			dis[y][x] = 1;
		}
		else{
			dis[x][y] = 1;
			dis[y][x] = -1;
		}
		
		E[x].push_back(y);
		E[y].push_back(x);
	}
	
	if(!check(E)){
		cout<<"NO"<<endl;
		return 0;
	}
	
	rep(i,n){
		rep(j,n){
			rep(k,n){
				dis[j][k] = min(dis[j][k],dis[j][i]+dis[i][k]);
			}
		}
	}
	
	rep(i,n){
		rep(j,n){
			rep(k,n){
				if(dis[j][k]>dis[j][i]+dis[i][k]){
					cout<<"NO"<<endl;
					return 0;
				}
			}
		}
	}
	
	int maxi = -1,ind = -1;
	
	rep(i,n){
		int a=Inf,b=-Inf;
		rep(j,n){
			a = min(a,dis[i][j]);
			b = max(dis[i][j],b);
		}
		if(b-a>maxi){
			maxi = b-a;
			ind = i;
		}
	}
	int mini = Inf;
	rep(i,n){
		mini = min(mini,dis[ind][i]);
	}
	rep(i,n){
		dis[ind][i] -= mini;
	}
	cout<<"YES"<<endl;
	cout<<maxi<<endl;
	rep(i,n){
		if(i!=0)cout<<' ';
		cout<<dis[ind][i];
	}
	cout<<endl;
	
	
    return 0;
}