#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define a first
#define b second
#define pb push_back
llo mod=100000007;
int n,m;
int it[1001][1001];
vector<int> vis[1001];
vector<int> vis2[1001];
pair<int,int> par[1001][1001];
pair<int,int> find(int i,int j){
	if(par[i][j].a==i and par[i][j].b==j){
		return {i,j};
	}
	par[i][j]=find(par[i][j].a,par[i][j].b);
	return par[i][j];
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	char s;

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>s;
			if(s=='#'){
				it[i][j]=1;
				vis[i].pb(j);
			}
			else{
				it[i][j]=0;
			}
		}
		
	}
	for(int j=0;j<m;j++){
		int st=0;
		for(int i=0;i<n;i++){
			if(it[i][j]==1){
				vis2[j].pb(i);
			}
		}
	}
	int ans=0;
	for(int i=0;i<n;i++){
		if(vis[i].size()>0){
			for(int j=0;j<vis[i].size()-1;j++){
				if(vis[i][j+1]>vis[i][j]+1){
					ans=-1;
					break;
				}
			}
		}
		else{
			int stt=0;
			for(int j=0;j<m;j++){
				if(vis2[j].size()==0){
					stt=1;
				}
			}
			if(stt==0){
				ans=-1;
			}
		}
	}
	for(int i=0;i<m;i++){
		if(vis2[i].size()>0){
			for(int j=0;j<vis2[i].size()-1;j++){
				if(vis2[i][j+1]>vis2[i][j]+1){
					ans=-1;
					break;
				}
			}
		}
		else{
			int stt=0;
			for(int j=0;j<n;j++){
				if(vis[j].size()==0){
					stt=1;
				}
			}
			if(stt==0){
				ans=-1;
			}
		}
	}
	if(ans==-1){
		cout<<ans<<endl;
	}
	else{
		int co=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(it[i][j]==1){
					par[i][j]={i,j};
					co+=1;
				}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m-1;j++){
				if(it[i][j]==1 and it[i][j+1]==1){
					pair<int,int> x=find(i,j);
					pair<int,int> y=find(i,j+1);
					if(x!=y){
						par[x.a][x.b]=y;
						co-=1;
					}
				}
			}
		}
		for(int i=0;i<n-1;i++){
			for(int j=0;j<m;j++){
				if(it[i][j]==1 and it[i+1][j]==1){
					pair<int,int> x=find(i,j);
					pair<int,int> y=find(i+1,j);
					if(x!=y){
						par[x.a][x.b]=y;
						co-=1;
					}
				}
			}
		}
		cout<<co<<endl;
	}








	return 0;
}