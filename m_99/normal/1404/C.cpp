#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000

template <typename T0,typename T1,typename F0,typename F1,typename F2>
struct lazysegtree{
	//x[i]v[n+i]
	//v[i]v[i/2],v[i*2]v[i*2+1]
	F0 func0;
	F1 func1;
	F2 func2;
	vector<T0> v0;
	vector<T1> v1;
	int n;
	int cnt;
	
	T0 init_value0;
	T1 init_value1;
	
	lazysegtree(int sz,F0 f0,F1 f1,F2 f2,T0 iv0,T1 iv1):func0(f0),func1(f1),func2(f2){
		init_value0 = iv0;
		init_value1 = iv1;
		n=1;
		cnt=0;
		while(true){
			if(n>=sz)break;
			n*=2;
			cnt++;
		}
		v0.resize(2*n,init_value0);
		v1.resize(2*n,init_value1);
		
	}
	
	lazysegtree(vector<T0> &x,F0 f0,F1 f1,F2 f2,T0 iv0,T1 iv1):func0(f0),func1(f1),func2(f2){
		init_value0 = iv0;
		init_value1 = iv1;
		n=1;
		cnt=0;
		while(true){
			if(n>=x.size())break;
			n*=2;
			cnt++;
		}
		v0.resize(2*n,init_value0);
		v1.resize(2*n,init_value1);
		for(int i=0;i<x.size();i++){
			v0[n+i]=x[i];
		}
		for(int i=n-1;i>=0;i--){
			v0[i]=func0(v0[i<<1],v0[(i<<1)+1]);
		}	
	}

	//2
	void propagate(int ind){
		update(ind<<1,v1[ind]);
		update((ind<<1)+1,v1[ind]);
		v1[ind] = init_value1;
	}
	
	//	
	void reflect(int l,int r){
		int j = cnt;
		while(l>>j==r>>j&&j>=1){
			propagate(l>>j);
			j--;
		}
		for(;j>=1;j--){
			propagate(l>>j);
			propagate(r>>j);
		}
	}
	
	//
	void mergeChildren(int ind){
		v0[ind] = func1(func0(v0[ind<<1],v0[(ind<<1)+1]),v1[ind],n>>(31-__builtin_clz(ind)));
	}
	
	//
	void update(int ind,T1 x){
		v0[ind] = func1(v0[ind],x,n>>(31-__builtin_clz(ind)));
		v1[ind] = func2(v1[ind],x);
	}
	
	//[l,r)
	void update(int l,int r,T1 x){
		if(l>=r)return;
		int L = l,R = r;
		l+=n;
		r+=n;
		reflect(l,r-1);
		while(true){
			if(l&1){
				update(l,x);
				l++;
			}
			if(r&1){
				update(r-1,x);
				r--;
			}
			if(l>=r)break;
			l>>=1;
			r>>=1;
		}
		
		l = L + n;
		r = R + n-1;
		
		while(true){
			l>>=1;
			r>>=1;
			if(l<=0)break;

			if(l==r){
				while(true){
					mergeChildren(l);
					l>>=1;
					if(!l)return;
				}
			}
			else{
				mergeChildren(l);
				mergeChildren(r);
			}
		}
		
	}
	
	//[l,r)
	T0 query(int l,int r){
		T0 res1 = init_value0;
		T0 res2 = init_value0;
		if(l>=r)return res1;
		l+=n;
		r+=n;
		reflect(l,r-1);
		while(true){
			if(l&1){
				res1=func0(res1,v0[l]);
				l++;
			}
			if(r&1){
				res2=func0(v0[r-1],res2);
				r--;
			}
			if(l>=r)break;
			l>>=1;
			r>>=1;
		}
		return func0(res1,res2);
	}

	void show(){
		int n = 1;
		for(int i=1;i<v0.size();i++){
			for(int j=0;j<n;j++){
				if(j!=0)cout<<' ';
				cout<<v0[i+j];
			}
			cout<<endl;
			i+=n-1;
			n*=2;
		}
	}
	
};

template <typename T,typename F>
struct segtree{
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

	int n,q;
	cin>>n>>q;
	
	vector<int> a(n);
	vector<pair<int,int>> A(n);
	vector<bool> ok(n,false);
	int ng = 0;
	rep(i,n){
		scanf("%d",&a[i]);
		A[i].second = i;
		if(a[i]-1>i){
			A[i].first = Inf;
			ok[i] = false;
			ng++;
		}
		else if(i==a[i]-1){
			A[i].first = Inf;
			ok[i] = true;
		}
		else if(((i-(a[i]-1))+ng-i)<=0){
			A[i].first = abs((i-(a[i]-1))+ng-i);
			ok[i] = true;
		}
		else{
			A[i].first = Inf;
			ng++;
		}
	}
	/*
	rep(i,n){
		cout<<ok[i]<<',';
	}
	cout<<endl;
	*/
	auto f0 = [](pair<int,int> a,pair<int,int> b){
		return min(a,b);
	};
	
	auto f1 = [](pair<int,int> a,int b,long long sz){
		a.first += b;
		if(a.first>Inf)a.first=Inf;
		return a;
	};
	
	auto f2 = [](int a,int b){
		return a+b;
	};
	
	pair<int,int> INF(Inf,0);
	
	lazysegtree<pair<int,int>,int,decltype(f0),decltype(f1),decltype(f2)> seg(A,f0,f1,f2,INF,0);
	
	auto f = [](int a,int b){
		return a+b;
	};
	
	vector<int> P(n);
	rep(i,n){
		if(ok[i])P[i] = 1;
		else P[i]=0;
	}
	
	vector<int> ans(q);
	vector<vector<pair<int,int>>> check(n,vector<pair<int,int>>());
	rep(i,q){
		int x,y;
		scanf("%d %d",&x,&y);
		check[x].emplace_back(y,i);
	}
	
	segtree<int,decltype(f)> seg2(P,f,0);
	
	rep(i,n){
		
		rep(j,check[i].size()){
			ans[check[i][j].second] = seg2.query(i,n-check[i][j].first);
		}

		if(ok[i]){
			seg2.update(i,0);
			seg.update(i,i+1,Inf);
			seg.update(i+1,n,-1);
			while(true){
				pair<int,int> t = seg.query(i+1,n);
				if(t.first>=0)break;
				if(ok[t.second]){
					seg2.update(t.second,0);
					seg.update(t.second,t.second+1,Inf);
					seg.update(t.second+1,n,-1);
				}
				ok[t.second]=false;
			}
		}
	}
    
	rep(i,q){
		printf("%d\n",ans[i]);
	}
	
    return 0;
}