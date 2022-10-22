#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000
vector<vector<long long>> a;
int n,m;
long long k;
long long ans = 0LL;
map<pair<int,int>,map<long long,long long>> cnt;

void dfs0(int y,int x,long long X){
	X ^= a[y][x];
	if(y+x == (n+m-2)/2){
		cnt[make_pair(y,x)][X]++;
		return;
	}
	if(y!=n-1){
		dfs0(y+1,x,X);
	}
	if(x!=m-1){
		dfs0(y,x+1,X);
	}
}

void dfs1(int y,int x,long long X){
	if(y+x==(n+m-2)/2){
		ans += cnt[make_pair(y,x)][X^k];
		return;
	}
	X ^= a[y][x];
	
	if(y!=0){
		dfs1(y-1,x,X);
	}
	if(x!=0){
		dfs1(y,x-1,X);
	}
}

int main(){

	
	cin>>n>>m;
	
	
	cin>>k;
	
	a.resize(n,vector<long long>(m,0));
	
	rep(i,n){
		rep(j,m){
			cin>>a[i][j];
		}
	}
	
	dfs0(0,0,0LL);
	
	dfs1(n-1,m-1,0LL);
	
	cout<<ans<<endl;
	
	return 0;
}