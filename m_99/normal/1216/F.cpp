#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((mod_x)%modulo)
#define Inf 10000000000000000

template <typename T,typename F>
struct segtree{
	//x[i]v[n+i]
	//v[i]v[i/2],v[i*2]v[i*2+1]
	F func;
	vector<T> v;
	int n;
	
	const T init_value = Inf;
	
	segtree(int sz,F f):func(f){
		n=1;
		while(true){
			if(n>=sz)break;
			n*=2;
		}
		v.resize(2*n,init_value);

		for(int i=n-1;i>=0;i--){
			v[i]=func(v[i<<1],v[(i<<1)+1]);
		}
	}
	
	segtree(vector<T> &x,F f):func(f){
		n=1;
		while(true){
			if(n>=x.size())break;
			n*=2;
		}
		v.resize(2*n,init_value);
		
		for(int i=0;i<x.size();i++){
			v[n+i]=x[i];
		}
		for(int i=n-1;i>=0;i--){
			v[i]=func(v[i<<1],v[(i<<1)+1]);
		}
	}

	void update(int x,T val){
		x+=n;
		v[x]=val;
		while(x>0){
			x>>=1;
			v[x]=func(v[x<<1],v[(x<<1)+1]);
		}
	}
	
	//[l,r)
	T query(int l,int r){
		if(l>=r)return init_value;
		l+=n;
		r+=n;
		T res1 = init_value;
		T res2 = init_value;
		while(true){
			if(l&1){
				res1=func(res1,v[l++]);
			}
			if(r&1){
				res2=func(v[--r],res2);
			}
			if(l>=r)break;
			l>>=1;r>>=1;
		}
		return func(res1,res2);
	}
	
	void show(){
		int n = 1;
		for(int i=1;i<v.size();i++){
			for(int j=0;j<n;j++){
				if(j!=0)cout<<' ';
				cout<<v[i+j];
			}
			cout<<endl;
			i+=n-1;
			n*=2;
		}
	}
	
};

int main(){
	
	int n,k;
	cin>>n>>k;
	
	string S;
	cin>>S;
	
	vector<vector<pair<int,int>>> V(n,vector<pair<int,int>>());
	
	for(int i=0;i<n;i++){
		V[i].emplace_back(i+1,0);
		if(S[i]=='1'){
			int x = min(i+k,n-1);
			//int a = 0;
			int a = x-max(0,i-k);
			//x-=max(0,i-k);
			V[x].emplace_back(i+1,a);
		}
	}
	
	auto f = [](long long a,long long b){
		return min(a,b);
	};
	
	segtree<long long,decltype(f)> dp(n+1,f);
	dp.update(0,0);
	
	for(int i=0;i<n;i++){
		for(int j=0;j<V[i].size();j++){
			dp.update(i+1,min(dp.query(i-V[i][j].second,i+1)+V[i][j].first,dp.query(i+1,i+2)));
		}
		//dp.show();
	}
	
	cout<<dp.query(n,n+1)<<endl;
	
	
    return 0;
}