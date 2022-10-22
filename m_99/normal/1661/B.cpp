#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001


int main(){
	
	vector<int> d(32768,Inf);
	d[0] = 0;
	queue<int> Q;
	Q.push(0);
	
	vector<vector<int>> E(32768);
	rep(i,32768){
		E[(i+1)%32768].push_back(i);
		E[(i*2)%32768].push_back(i);
	}
	
	while(Q.size()>0){
		int u = Q.front();
		Q.pop();
		rep(i,E[u].size()){
			int v = E[u][i];
			if(d[v]!=Inf)continue;
			d[v] = d[u]+1;
			Q.push(v);
		}
	}
	
	int n;
	cin>>n;
	vector<int> a(n);
	rep(i,n)cin>>a[i];
	rep(i,n){
		if(i!=0)cout<<' ';
		cout<<d[a[i]];
	}
	cout<<endl;
	
	return 0;
}