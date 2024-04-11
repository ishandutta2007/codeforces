#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000000000
vector<int> L;
vector<long long> get(vector<int> u,vector<int> v,vector<int> w,int s){
	int n = L.size();
	vector<vector<int>> E(n,vector<int>());
	//cout<<'a'<<endl;
	//cout<<n<<endl;
	rep(i,u.size()){
		//cout<<u[i]<<','<<v[i]<<endl;
		E[u[i]].push_back(i);
		E[v[i]].push_back(i);
	}
//	cout<<'b'<<endl;
	vector<long long> dis(n,Inf);
	dis[s] = 0;
	priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> Q;
	Q.emplace(0,s);
	//return dis;
	while(Q.size()>0){
		long long D = Q.top().first;
		int x = Q.top().second;
		Q.pop();
		if(dis[x]!=D)continue;
		rep(i,E[x].size()){
			int ind = E[x][i];
			int y = u[ind] ^ v[ind] ^ x;
			long long D2 = w[ind];
			if(D+D2 < dis[y]){
				dis[y] = D+D2;
				Q.emplace(dis[y],y);
			}
		}
	}
	return dis;
}

int main(){
	
	int n,m,k;
	cin>>n>>m>>k;
	
	vector<int> u(m),v(m),w(m);
	vector<int> t;
	rep(i,m){
		scanf("%d %d %d",&u[i],&v[i],&w[i]);
		u[i]--;v[i]--;
		t.push_back(i);
	}
	
	sort(t.begin(),t.end(),[&](int a,int b){
		return w[a]<w[b];
	});
	
	m = min(m,k);
	rep(i,m){
		L.push_back(u[t[i]]);
		L.push_back(v[t[i]]);
	}
	
	sort(L.begin(),L.end());
	L.erase(unique(L.begin(),L.end()),L.end());

	vector<int> U(m),V(m),W(m);
	rep(i,m){
		U[i] = distance(L.begin(),lower_bound(L.begin(),L.end(),u[t[i]]));
		V[i] = distance(L.begin(),lower_bound(L.begin(),L.end(),v[t[i]]));
		W[i] = w[t[i]];
	}
	
	vector<long long> dis;
	rep(i,L.size()){

		auto ret = get(U,V,W,i);
		rep(j,i){
			dis.push_back(ret[j]);
		}
	}
	sort(dis.begin(),dis.end());

	
	cout<<dis[k-1]<<endl;
	
	return 0;
}