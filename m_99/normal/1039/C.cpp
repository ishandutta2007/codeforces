#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000000
int n,m;
long long k;

int beki(long long a,long long b,int M = modulo){
	int x = 1;
	while(b!=0){
		if(b&1){
			x=((long long)x*a)%M;
		}
		a=((long long)a*a)%M;
		b>>=1;
	}
	return x;
}

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
		if(size[x]>size[y])swap(x,y);
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

int get(vector<pair<int,int>> p){
	vector<int> inds;
	for(int i=0;i<p.size();i++){
		inds.push_back(p[i].first);
		inds.push_back(p[i].second);
	}
	sort(inds.begin(),inds.end());
	inds.erase(unique(inds.begin(),inds.end()),inds.end());
	
	unionfind uf(inds.size());
	
	for(int i=0;i<p.size();i++){
		int a = distance(inds.begin(),lower_bound(inds.begin(),inds.end(),p[i].first));
		int b = distance(inds.begin(),lower_bound(inds.begin(),inds.end(),p[i].second));
		uf.unite(a,b);
	}
	
	int ans = 1;
	for(int i=0;i<inds.size();i++){
		if(uf.find(i)==i)ans = mod(ans * 2);
	}
	ans = mod(ans * beki(2,n-inds.size()));
	return ans;
}

int main(){

	cin>>n>>m>>k;
	
	vector<long long> c(n);
	for(int i=0;i<n;i++)scanf("%lld",&c[i]);
	
	map<long long,vector<pair<int,int>>> mp;
	
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		a--;b--;
		mp[c[a]^c[b]].emplace_back(a,b);
	}
	
	int ans = 0;
	ans = mod(mod((1LL<<k) - mp.size()) * beki(2,n));
	
	for(auto a:mp){
		ans = mod(ans + get(a.second));
	}
	
	cout<<ans<<endl;
	
	
	return 0;
}