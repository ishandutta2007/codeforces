#include <bits/stdc++.h>
using namespace std;
#define modulo m
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000


int main(){
	
	int n;
	cin>>n;
	
	vector<vector<int>> x(n,vector<int>(n)),y(n,vector<int>(n));
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d %d",&x[i][j],&y[i][j]);
			x[i][j]--;
			y[i][j]--;
		}
	}
	
	vector<string> ans(n,string(n,'?'));
	
	vector<vector<bool>> visited(n,vector<bool>(n,false));
	
	queue<pair<int,int>> Q;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==x[i][j]&&j==y[i][j]){
				Q.emplace(i,j);
				visited[i][j]=true;
				ans[i][j]='X';
			}
		}
	}
	
	while(Q.size()!=0){
		int yy = Q.front().first;
		int xx = Q.front().second;
		Q.pop();
		
		for(int i=0;i<4;i++){
			int yyy = yy,xxx = xx;
			if(i==0)yyy++;
			if(i==1)yyy--;
			if(i==2)xxx++;
			if(i==3)xxx--;
			
			if(yyy<0||xxx<0||yyy>=n||xxx>=n)continue;
			if(visited[yyy][xxx])continue;
			
			if(x[yyy][xxx]!=x[yy][xx]||y[yyy][xxx]!=y[yy][xx])continue;
			char c;
			if(i==0)c='U';
			if(i==1)c='D';
			if(i==2)c='L';
			if(i==3)c='R';
			ans[yyy][xxx] = c;
			Q.emplace(yyy,xxx);
			visited[yyy][xxx]=true;
			
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(-2==x[i][j]&&-2==y[i][j]){
				Q.emplace(i,j);
				visited[i][j]=true;
			}
		}
	}
	
	while(Q.size()!=0){
		int yy = Q.front().first;
		int xx = Q.front().second;
		Q.pop();
		
		for(int i=0;i<4;i++){
			int yyy = yy,xxx = xx;
			if(i==0)yyy++;
			if(i==1)yyy--;
			if(i==2)xxx++;
			if(i==3)xxx--;
			
			if(yyy<0||xxx<0||yyy>=n||xxx>=n)continue;
			
			if(x[yyy][xxx]!=-2||y[yyy][xxx]!=-2)continue;
			char c,c2;
			if(i==0){
				c='U';
				c2='D';
			}
			if(i==1){
				c='D';
				c2='U';
			}
			if(i==2){
				c='L';
				c2='R';
			}
			if(i==3){
				c='R';
				c2='L';
			}
			ans[yyy][xxx] = c;
			ans[yy][xx] = c2;
			if(visited[yyy][xxx])continue;
			Q.emplace(yyy,xxx);
			visited[yyy][xxx]=true;
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(ans[i][j]=='?'){
				cout<<"INVALID"<<endl;
				return 0;
			}
		}
	}
	
	cout<<"VALID"<<endl;
	
	for(int i=0;i<n;i++)cout<<ans[i]<<endl;
	
	return 0;
}