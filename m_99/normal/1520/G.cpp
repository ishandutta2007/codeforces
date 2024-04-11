#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define inf 1000000000
#define Inf 1000000000000000000

int d0[2001][2001],d1[2001][2001];
long long a[2001][2001];

int main(){
	
	int n,m;
	cin>>n>>m;
	long long w;
	cin>>w;
	
	rep(i,n){
		rep(j,m){
			scanf("%lld",&a[i][j]);
		}
	}
	
	rep(i,n){
		rep(j,m){
			d0[i][j] = inf;
			d1[i][j] = inf;
		}
	}
	
	vector<int> dy = {0,0,1,-1},dx = {1,-1,0,0};
	
	{
		queue<pair<int,int>> Q;
		Q.emplace(0,0);
		d0[0][0] = 0;
		while(Q.size()>0){
			int y = Q.front().first,x = Q.front().second;
			Q.pop();
			rep(i,4){
				int yy = y + dy[i],xx = x + dx[i];
				if(yy<0||yy>=n||xx<0||xx>=m)continue;
				if(a[yy][xx]==-1)continue;
				if(d0[yy][xx]!=inf)continue;
				d0[yy][xx] = d0[y][x] + 1;
				Q.emplace(yy,xx);
			}
		}
	}
	
	{
		queue<pair<int,int>> Q;
		Q.emplace(n-1,m-1);
		d1[n-1][m-1] = 0;
		while(Q.size()>0){
			int y = Q.front().first,x = Q.front().second;
			Q.pop();
			rep(i,4){
				int yy = y + dy[i],xx = x + dx[i];
				if(yy<0||yy>=n||xx<0||xx>=m)continue;
				if(a[yy][xx]==-1)continue;
				if(d1[yy][xx]!=inf)continue;
				d1[yy][xx] = d1[y][x] + 1;
				Q.emplace(yy,xx);
			}
		}
	}
	
	long long ans = Inf;
	if(d1[0][0]!=inf){
		ans = d1[0][0];
		ans *= w;
	}
	
	long long s0 = Inf,s1 = Inf;
	
	rep(i,n){
		rep(j,m){
			if(d0[i][j]==inf)continue;
			if(a[i][j]<=0)continue;
			long long t = d0[i][j];
			t *= w;
			t += a[i][j];
			s0 = min(s0,t);
		}
	}
	
	rep(i,n){
		rep(j,m){
			if(d1[i][j]==inf)continue;
			if(a[i][j]<=0)continue;
			long long t = d1[i][j];
			t *= w;
			t += a[i][j];
			s1 = min(s1,t);
		}
	}
	
	ans = min(ans,s0+s1);
	
	if(ans==Inf)cout<<-1<<endl;
	else cout<<ans<<endl;
	
    return 0;
}