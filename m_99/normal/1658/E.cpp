#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001

int main(){
	
	int n,k;
	scanf("%d %d",&n,&k);
	vector v(n,vector<int>(n));
	vector<pair<int,int>> pos(n*n);

	rep(i,n){
		rep(j,n){
			scanf("%d",&v[i][j]);
			v[i][j]--;
			pos[v[i][j]] = make_pair(i,j);
			
		}
	}
	
	vector<string> ans(n,string(n,'G'));
	
	int l = -Inf,r = Inf,t = -Inf,b = Inf;
	for(int i=n*n-1;i>=0;i--){
		
		int x = pos[i].first,y = pos[i].second;
		int z = x;
		x += y;
		y -= z;
		bool f = false;
		//cout<<l<<','<<r<<','<<t<<','<<b<<endl;
		if(x>=l && x<=r && y>=t && y<=b)f = true;
		if(f){
			ans[pos[i].first][pos[i].second] = 'M';
			l = max(l,x-k);
			r = min(r,x+k);
			t = max(t,y-k);
			b = min(b,y+k);
		}
		
	}
	rep(i,n)cout<<ans[i]<<'\n';
	
	return 0;
}