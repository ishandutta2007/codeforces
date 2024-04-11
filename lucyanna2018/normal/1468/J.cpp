#include<bits/stdc++.h>
using namespace std;
int K,n;
int ace[222222];int ancestor(int x){return x-ace[x]?ace[x]=ancestor(ace[x]):x;}
vector<pair<int,pair<int,int> > > e;
int main(){
	int _,M,X,Y,Z;
	for(scanf("%d",&_); _--;){
		scanf("%d%d%d",&n,&M,&K);
		for(int i=1; i<=n; i++)
			ace[i] = i;
		int w = (int)2e9;
		e.clear();
		while(M--){
			scanf("%d%d%d",&X,&Y,&Z);
			w = min(w, (int)labs(Z - K));
			if(Z <= K)
				ace[ancestor(X)] = ancestor(Y);
			else
				e.push_back(make_pair(Z-K, make_pair(X,Y)));
		}
		bool ff = false;
		for(int i=1; i<=n && !ff; i++)
			if(ancestor(i) != ancestor(1))
				ff = true;
		if(ff){
			long long int res = 0;
			sort(e.begin(), e.end());
			for(auto P : e){
				X = P.second.first, Y = P.second.second;
				X = ancestor(X);
				Y = ancestor(Y);
				if(X != Y){
					ace[X] = Y;
					res += P.first;
				}
			}
			cout << res << endl;
		}else
			cout << w << endl;
	}
	return 0;
}