#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000

template <typename T>
struct segtree{
	//x[i]v[n+i]
	//v[i]v[i/2],v[i*2]v[i*2+1]
	vector<T> v;
	int n;
	
	const T init_value = 0;
	
	segtree(int sz){
		n=1;
		while(true){
			if(n>=sz)break;
			n*=2;
		}
		v.resize(2*n,init_value);

		for(int i=n-1;i>=0;i--){
			v[i]=func(v[i*2],v[i*2+1]);
		}
	}
	
	segtree(vector<T> &x){
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
			v[i]=func(v[i*2],v[i*2+1]);
		}
	}

	void update(int x,T val){
		x+=n;
		v[x]=val;
		while(true){
			x=(x)/2;
			v[x]=func(v[x*2],v[x*2+1]);
			if(x<=0)break;
		}
	}
	
	//[l,r)
	T query(int l,int r){
		T res1 = init_value;
		T res2 = init_value;
		if(l>=r)return res1;
		l+=n;
		r+=n;
		while(true){
			if(l%2==1){
				res1=func(res1,v[l]);
				l++;
			}
			if(r%2==1){
				res2=func(v[r-1],res2);
				r--;
			}
			if(l>=r)break;
			l/=2;r/=2;
		}
		return func(res1,res2);
	}
	T func(T a,T b){
		return a+b;
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
	
	vector<pair<int,int>> V(n);
	
	for(int i=0;i<n;i++){
		scanf("%d %d",&V[i].first,&V[i].second);
		V[i].first--;
		V[i].second--;
	}
	
	sort(V.begin(),V.end());
	
	segtree<long long> S(2*n);
	
	long long cnt =0;
	for(int i=0;i<n;i++){
		long long k = S.query(V[i].first,V[i].second+1);

		cnt += k;

		S.update(V[i].second,S.query(V[i].second,V[i].second+1)+1);
	}

	if(cnt!=n-1){
		cout<<"NO"<<endl;
		return 0;
	}
	
	unionfind uf(n);
	set<pair<int,int>> se;
	
	for(int i=0;i<n;i++){
		for(auto it = se.lower_bound(make_pair(V[i].first,0));it!=se.end();it++){
			if((*it).first > V[i].second)break;
			uf.unite(i,(*it).second);
		}
		se.insert(make_pair(V[i].second,i));
	}
	if(uf.get_size(0)==n){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
	
	return 0;
}