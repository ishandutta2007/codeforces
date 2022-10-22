#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000000

template <typename T,typename F>
struct segtree{
	//x[i]v[n+i]
	//v[i]v[i/2],v[i*2]v[i*2+1]
	F func;
	vector<T> v;
	int n;
	
	T init_value;
	
	segtree(int sz,F f,T iv):func(f){
		init_value = iv;
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
	
	segtree(vector<T> &x,F f,T iv):func(f){
		init_value = iv;
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
	
	int t;
	cin>>t;
	
	auto f = [](int a,int b){
		return max(a,b);
	};

	for(int _=0;_<t;_++){
		int n;
		scanf("%d",&n);
		
		vector<int> p(n);
		vector<int> pos(n);
		set<int> S;
		for(int i=0;i<n;i++){
			scanf("%d",&p[i]);
			p[i]--;
			pos[p[i]] = i;
			S.insert(i);
		}
		vector<int> X(n,1);
		
		segtree<int,decltype(f)> seg(X,f,0);
		
		bool f = true;
		
		for(int i=0;i<n;i++){
			if(seg.query(pos[i],pos[i]+1)!=seg.query(0,n)){
				f=false;
				break;
			}
			else{
				int k = seg.query(pos[i],pos[i]+1);
				seg.update(pos[i],0);
				auto it = S.lower_bound(pos[i]);
				it = S.erase(it);
				if(it!=S.end()){
					int x = seg.query(*it,*it+1);
					seg.update(*it,x+k);
				}
			}
		}
		
		if(f)printf("Yes\n");
		else printf("No\n");
		
	}
	
	
	return 0;
}