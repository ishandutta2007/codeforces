#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000

int main(){
	
	int n;
	cin>>n;
	vector<int> p(n);
	rep(i,n){
		cin>>p[i];
		p[i]--;
	}
	
	vector ans(n,vector<int>(n,-1));
	
	vector<vector<pair<int,int>>> pos(n);
	rep(i,n){
		rep(j,i+1){
			pos[i].emplace_back(i,j);
			ans[i][j] = i;
		}
	}
	
	vector<int> npos(n);
	rep(i,n){
		npos[p[i]] = i;
	}
	
	while(true){
		int ind = -1;
		rep(i,n-1){
			if(npos[ans[i][i]]>npos[ans[i+1][i+1]]){
				ind = i;
				break;
			}
		}
		if(ind==-1)break;
		//cout<<ind<<endl;
		int x = ans[ind][ind],y = ans[ind+1][ind+1];

		rep(i,pos[x].size()){
			pos[x][i].first++;
			pos[x][i].second++;
			if(pos[x][i].first>=n){
				pos[x][i].first--;
				pos[x][i].second--;
			}
			else if(ans[pos[x][i].first][pos[x][i].second]!=y){
				pos[x][i].first--;
				pos[x][i].second--;
			}
			else{
				ans[pos[x][i].first][pos[x][i].second] = x;
			}
		}
		rep(i,pos[y].size()){
			//cout<<i<<endl;
			pos[y][i].first--;
			pos[y][i].second--;
			//cout<<i<<endl;
			//cout<<ans[pos[y][i].first][pos[y][i].second]<<endl;
			if(pos[y][i].second<0){
				//cout<<i<<endl;
				pos[y][i].first++;
				pos[y][i].second++;
			}
			else if(ans[pos[y][i].first][pos[y][i].second]!=x){
			//	cout<<i<<endl;
				pos[y][i].first++;
				pos[y][i].second++;
			}
			else{
				//cout<<i<<endl;
				ans[pos[y][i].first][pos[y][i].second] = y;
			}
			//cout<<i<<endl;
		}
		
	}
	
	
	rep(i,n){
		rep(j,n){
			if(ans[i][j]<0)break;
			if(j!=0)printf(" ");
			cout<<ans[i][j]+1;
		}
		printf("\n");
	}
	
	
    return 0;
}