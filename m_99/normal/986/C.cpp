#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000

int main(){
	
	int n,m;
	cin>>n>>m;
	
	vector<int> a(m);
	vector<int> ind(1<<n,-1);
	rep(i,m){
		scanf("%d",&a[i]);
		ind[a[i]] = i;
	}
	
	vector<bool> visited((1<<n)+m,false);
	int ans = 0;
	rep(i,m){
		if(visited[(1<<n) + i])continue;
		queue<int> Q;
		visited[(1<<n) + i] = true;
		Q.push((1<<n) + i);
		ans++;
		while(Q.size()>0){
			int u = Q.front();
			Q.pop();
			if(u < (1<<n)){
				rep(j,n){
					if((u>>j)&1){
						int v = u ^ (1<<j);
						if(visited[v])continue;
						Q.push(v);
						visited[v] = true;
					}
				}
				if(ind[u]!=-1){
					int v = (1<<n) + ind[u];
					if(!visited[v]){
						visited[v] = true;
						Q.push(v);
					}
				}
			}
			else{
				int v = a[u-(1<<n)];
				v ^= (1<<n) - 1;
				if(visited[v])continue;
				visited[v] = true;
				Q.push(v);
			}
		}
	}
	
	cout<<ans<<endl;
	
	return 0;
}