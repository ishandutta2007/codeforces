#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1200000000
vector<vector<int>> a;
vector<pair<int,int>> E;
vector<int> ans;
int r;
void dfs(vector<int> t,int p){

	if(t.size()!=1){
		
		int maxi = 0;
		rep(i,t.size()){
			if(i==0)continue;
			maxi = max(maxi,a[t[0]][t[i]]);
		}
		
		int xx = ans.size();
		ans.push_back(maxi);
		if(p!=-1){
			E.emplace_back(xx,p);
		}
		else{
			r = ans.size();
		}
		vector<vector<int>> x(1,vector<int>(1,t[0]));
		
		rep(i,t.size()){
			if(i==0)continue;
			bool f = false;
			rep(j,x.size()){
				bool F = true;
				if(a[x[j][0]][t[i]]!=maxi){
					x[j].push_back(t[i]);
					f=true;
					break;
				}
			}
			if(!f){
				x.push_back(vector<int>(1,t[i]));
			}
		}
		/*
		if(x.size()==1){
			x.push_back(vector<int>(1,x[0].back()));
			x[0].pop_back();
		}
		*/
		
		rep(i,x.size()){
			dfs(x[i],xx);
		}
		
	}
	else{
		E.emplace_back(t[0],p);
	}
}
		
		

int main(){
	
	int n;
	scanf("%d",&n);
	
	a.resize(n,vector<int>(n));
	
	rep(i,n){
		rep(j,n){
			scanf("%d",&a[i][j]);
		}
	}
	
	ans.resize(n);
	rep(i,n){
		ans[i] = a[i][i];
	}
	
	
	vector<int> t(n);
	rep(i,n)t[i] = i;
	
	dfs(t,-1);
	cout<<ans.size()<<endl;
	rep(i,ans.size()){
		if(i!=0)printf(" ");
		printf("%d",ans[i]);
	}
	
	cout<<endl;
	cout<<r<<endl;
	
	rep(i,E.size()){
		printf("%d %d\n",E[i].first+1,E[i].second+1);
	}
	
    return 0;
}