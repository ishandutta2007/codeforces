#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000000
int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		int n,k;
		scanf("%d %d",&n,&k);
		vector cost(k+1,vector(k+1,vector<int>(4,0)));
		vector<int> dx = {1,0,-1,0},dy = {0,-1,0,1};
		rep(i,k+1){
			rep(j,k+1){
				if(i==0)cost[i][j][1] = Inf;
				if(j==0)cost[i][j][2] = Inf;
				if(i==k)cost[i][j][3] = Inf;
				if(j==k)cost[i][j][0] = Inf;
			}
		}
		
		rep(i,n){
			int a,b,c,d;
			scanf("%d %d %d %d",&a,&b,&c,&d);
			a--;b--;c--;d--;
			if(abs(a-c)==1){
				if(a>c)swap(a,c);
				cost[c][d][0] ++;
				cost[c][d+1][2] ++;
				cost[k-c][k-d][2] ++;
				cost[k-c][k-(d+1)][0]++;
			}
			else{
				if(b>d)swap(b,d);
				cost[c][d][3] ++;
				cost[c+1][d][1] ++;
				cost[k-c][k-d][1]++;
				cost[k-(c+1)][k-d][3]++;
			}
		}
		
		vector dis(k+1,vector<int>(k+1,Inf));
		dis[0][0] = 0;
		priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> Q;
		Q.emplace(0,make_pair(0,0));
		
		while(Q.size()){
			int D = Q.top().first;
			int y = Q.top().second.first,x = Q.top().second.second;
			Q.pop();
			if(dis[y][x]!=D)continue;
			rep(i,4){
				if(cost[y][x][i]==Inf)continue;
				int yy = y + dy[i],xx = x+dx[i];
				int DD = D + cost[y][x][i];
				if(dis[yy][xx]>DD){
					dis[yy][xx] = DD;
					Q.emplace(DD,make_pair(yy,xx));
				}
			}
		}
		int ans = n - dis[k/2][k/2];
		printf("%d\n",ans);
			
		
	}
	
	return 0;
}