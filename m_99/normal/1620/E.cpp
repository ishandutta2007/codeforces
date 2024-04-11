#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001


int main(){
	
	vector<vector<int>> v(500005,vector<int>());
	int q;
	cin>>q;
	int cur = 0;
	rep(i,q){
		int t;
		scanf("%d",&t);
		if(t==1){
			int x;
			scanf("%d",&x);
			v[x].push_back(cur);
			cur++;
		}
		else{
			int x,y;
			scanf("%d %d",&x,&y);
			if(x==y)continue;
			if(v[y].size()<v[x].size())swap(v[x],v[y]);
			while(v[x].size()!=0){
				v[y].push_back(v[x].back());
				v[x].pop_back();
			}
			
		}
	}
	vector<int> ans(cur);
	rep(i,v.size()){
		rep(j,v[i].size())ans[v[i][j]] = i;
	}
	
	rep(i,cur){
		if(i!=0)printf(" ");
		printf("%d",ans[i]);
	}
	cout<<endl;
	
	return 0;
}