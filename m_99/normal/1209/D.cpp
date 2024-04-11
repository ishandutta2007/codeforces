#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000

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
	
	int n,k;
	cin>>n>>k;
	
	vector<pair<int,int>> P(k);
	unionfind uf(n);
	
	for(int i=0;i<k;i++){
		cin>>P[i].first>>P[i].second;
		P[i].first--;P[i].second--;
		
		uf.unite(P[i].first,P[i].second);
	}
	
	vector<int> cnt(n,0);
	
	for(int i=0;i<k;i++){
		cnt[uf.find(P[i].first)]++;
	}
	
	int sum = 0;
	
	for(int i=0;i<n;i++){
		sum += min(uf.get_size(i)-1,cnt[i]);
	}
	
	cout<<k-sum<<endl;
		
	
	
	return 0;
}