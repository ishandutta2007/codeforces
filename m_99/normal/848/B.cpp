#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000

vector<int> ansX,ansY;
int n,w,h;

void calc(vector<vector<int>> d){
	vector<pair<int,int>> Y,X;
	rep(i,d.size()){
		if(d[i][0]==1)X.emplace_back(d[i][1],d[i][2]);
		else Y.emplace_back(d[i][1],d[i][2]);
	}
	sort(X.begin(),X.end());
	sort(Y.begin(),Y.end());
	if(X.size()!=0){
		for(int i=X.size()-1;i>=0;i--){
			int a = Y.size();
			int b = X.size()-1-i;
			if(b<a){
				ansX[X[i].second] = w;
				ansY[X[i].second] = Y[b].first;
			}
			else{
				ansX[X[i].second] = X[i+a].first;
				ansY[X[i].second] = h;
			}
		}
		
	}
	if(Y.size()!=0){
		for(int i=Y.size()-1;i>=0;i--){
			int a = X.size();
			int b = Y.size()-1-i;
			if(b<a){
				ansY[Y[i].second] = h;
				ansX[Y[i].second] = X[b].first;
			}
			else{
				ansY[Y[i].second] = Y[i+a].first;
				ansX[Y[i].second] = w;
			}
		}
	}
}

int main(){

	
	cin>>n>>w>>h;
	
	map<int,vector<vector<int>>> mp;
	
	rep(i,n){
		int g,p,t;
		scanf("%d %d %d",&g,&p,&t);
		mp[p-t].push_back({g,p,i});
	}
	
	ansX.resize(n),ansY.resize(n);
	
	for(auto a:mp){
		calc(a.second);
	}
	
	rep(i,n){
		printf("%d %d\n",ansX[i],ansY[i]);
	}
	
    return 0;
}