#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 100000000000000000


int main(){
	
	int n;
	cin>>n;
	vector<int> dx = {1,-1,0,0},dy = {0,0,1,-1};
	set<pair<int,int>> S;
	set<pair<int,int>> s;
	vector<int> x(n),y(n);
	rep(i,n){
		scanf("%d %d",&x[i],&y[i]);
		S.emplace(x[i],y[i]);
		s.emplace(x[i],y[i]);
		rep(j,4){
			S.emplace(x[i]+dx[j],y[i]+dy[j]);
		}
	}
	
	queue<pair<int,int>> Q;
	map<pair<int,int>,pair<int,int>> mp;
	for(auto a:S){
		if(s.count(a))continue;
		Q.push(a);
		mp[a] = a;
	}
	
	while(Q.size()>0){
		int ux = Q.front().first;
		int uy = Q.front().second;
		Q.pop();
		rep(i,4){
			int xx = ux + dx[i];
			int yy = uy + dy[i];
			if(!S.count(make_pair(xx,yy)))continue;
			if(mp.count(make_pair(xx,yy)))continue;
			mp[make_pair(xx,yy)] = mp[make_pair(ux,uy)];
			Q.emplace(xx,yy);
		}
	}
	
	rep(i,n){
		printf("%d %d\n",mp[make_pair(x[i],y[i])].first, mp[make_pair(x[i],y[i])].second);
	}
	
	
	return 0;
}