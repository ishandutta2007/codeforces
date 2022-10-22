#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000

struct unionfind{
	vector<int> data;
	vector<int> size;
	unionfind(int n){
		for(int i=0;i<n;i++){
			data.push_back(i);
			size.push_back(1);
		}
	}
	
	int find(int x){
		if(data[x]==x)return x;
		return data[x]=find(data[x]);
	}
	
	bool unite(int x,int y){
		x=find(x);y=find(y);
		if(x==y)return false;
		data[x]=y;
		size[y]+=size[x];
		return true;
	}
	
	bool check(int x,int y){
		return (find(x)==find(y));
	}
	
	int get_size(int x){
		int X = find(x);
		return size[X];
	}
};


int main(){
	
	int n;
	cin>>n;
	
	vector<long long> x(n),y(n),c(n),k(n);
	
	for(int i=0;i<n;i++){
		cin>>x[i]>>y[i];
	}
	
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	
	for(int i=0;i<n;i++){
		cin>>k[i];
	}
	
	vector<pair<long long,pair<int,int>>> P;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j)continue;
			long long dis = abs(x[i]-x[j])+abs(y[i]-y[j]);
			long long K = k[i]+k[j];
			P.emplace_back(K*dis,make_pair(i,j));
		}
	}
	
	for(int i=0;i<n;i++){
		P.emplace_back(c[i],make_pair(i,n));
	}
	
	long long ans = 0;
	unionfind uf(n+1);
	sort(P.begin(),P.end());
	
	vector<int> stand(0);
	vector<pair<int,int>> cable(0);
	
	for(int i=0;i<P.size();i++){
		if(uf.check(P[i].second.first,P[i].second.second))continue;
		ans+=P[i].first;
		uf.unite(P[i].second.first,P[i].second.second);
		if(P[i].second.second==n){
			stand.push_back(P[i].second.first);
		}
		else{
			cable.emplace_back(P[i].second.first,P[i].second.second);
		}
	}
	cout<<ans<<endl;
	cout<<stand.size()<<endl;
	for(int i=0;i<stand.size();i++){
		if(i!=0)cout<<' ';
		cout<<stand[i]+1;
	}
	cout<<endl;
	cout<<cable.size()<<endl;
	
	for(int i=0;i<cable.size();i++){
		cout<<cable[i].first+1<<' '<<cable[i].second+1<<endl;
	}
	
	
    return 0;
}