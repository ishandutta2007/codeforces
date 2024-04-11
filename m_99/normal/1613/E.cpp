#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001


int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n,m;
		scanf("%d %d",&n,&m);
		vector<string> s(n);
		rep(i,n)cin>>s[i];
		vector<int> dx = {1,-1,0,0},dy = {0,0,1,-1};

		
		vector<vector<int>> C(n,vector<int>(m,0));
		queue<pair<int,int>> Q;
		rep(i,n){
			rep(j,m){
				if(s[i][j]=='#')continue;
				int cnt = 0;
				if(s[i][j]!='L'){
					rep(k,4){
						int ii = i+dx[k],jj = j+dy[k];
						if(ii<0||ii>=n||jj<0||jj>=m)continue;
						if(s[ii][jj]=='#')continue;
						cnt++;
					}
				}
				else{
					Q.emplace(i,j);
				}
				C[i][j] = cnt;
			}
		}
		
		
		
		while(Q.size()>0){
			int y = Q.front().first,x = Q.front().second;
			Q.pop();
			rep(i,4){
				int yy = y + dx[i],xx = x+dy[i];
				if(yy<0||yy>=n||xx<0||xx>=m)continue;
				if(s[yy][xx]=='#')continue;
				C[yy][xx] --;
				if(C[yy][xx]<=1&&C[yy][xx]>=0){
					Q.emplace(yy,xx);
					s[yy][xx] = '+';
					C[yy][xx] = 0;
				}
			}
		}
		
		rep(i,n)cout<<s[i]<<'\n';
		
	}
	
	
	return 0;
}