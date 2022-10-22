#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000

template <typename T1,typename T2>
struct lazysegtree{
	//x[i]v[n+i]
	//v[i]v[i/2],v[i*2]v[i*2+1]
	vector<T1> v1;
	vector<T2> v2;
	vector<int> sz_;
	int n;
	int cnt;
	
	const T1 init_value1 = -Inf;
	const T2 init_value2 = 0;
	
	lazysegtree(int sz){
		n=1;
		cnt=0;
		while(true){
			if(n>=sz)break;
			n*=2;
			cnt++;
		}
		v1.resize(2*n,init_value1);
		v2.resize(2*n,init_value2);

		for(int i=n-1;i>=0;i--){
			v1[i]=func1(v1[i*2],v1[i*2+1]);
		}
		
		sz_.resize(2*n,n);
		
		for(int i=2;i<2*n;i++){
			sz_[i] = sz_[i/2]/2;
		}
		
	}
	
	lazysegtree(vector<T1> &x){
		n=1;
		cnt=0;
		while(true){
			if(n>=x.size())break;
			n*=2;
			cnt++;
		}
		v1.resize(2*n,init_value1);
		v2.resize(2*n,init_value2);
		for(int i=0;i<x.size();i++){
			v1[n+i]=x[i];
		}
		for(int i=n-1;i>=0;i--){
			v1[i]=func1(v1[i*2],v1[i*2+1]);
		}
		
		sz_.resize(2*n,n);
		
		for(int i=2;i<2*n;i++){
			sz_[i] = sz_[i/2]/2;
		}
		
	}

	//2
	void propagate(int ind){
		update(ind*2,v2[ind]);
		update(ind*2+1,v2[ind]);
		v2[ind] = init_value2;
	}
	
	//
	void reflect(int ind){
		for(int j=cnt;j>=1;j--){
			propagate(ind>>j);
		}
	}
	
	//
	void mergeChildren(int ind){
		v1[ind] = func2(func1(v1[ind*2],v1[ind*2+1]),v2[ind],sz_[ind]);
	}
	
	//
	void update(int ind,T2 x){
		v1[ind] = func2(v1[ind],x,sz_[ind]);
		v2[ind] = func2(v2[ind],x,1);
	}
	
	//[l,r)
	void update(int l,int r,T2 x){
		if(l>=r)return;
		int L = l,R = r;
		l+=n;
		r+=n;
		reflect(l);
		reflect(r-1);
		while(true){
			if(l%2==1){
				update(l,x);
				l++;
			}
			if(r%2==1){
				update(r-1,x);
				r--;
			}
			if(l>=r)break;
			l/=2;
			r/=2;
		}
		
		l = L + n;
		r = R + n;
		
		while(true){
			l/=2;
			r=(r+1)/2;
			if(l<=0)break;
			mergeChildren(l);
			mergeChildren(r-1);
		}
		
	}
	
	//[l,r)
	T1 query(int l,int r){
		T1 res1 = init_value1;
		T1 res2 = init_value1;
		if(l>=r)return res1;
		l+=n;
		r+=n;
		reflect(l);
		reflect(r-1);
		while(true){
			if(l%2==1){
				res1=func1(res1,v1[l]);
				l++;
			}
			if(r%2==1){
				res2=func1(v1[r-1],res2);
				r--;
			}
			if(l>=r)break;
			l/=2;r/=2;
		}
		return func1(res1,res2);
	}
	
	T1 func1(T1 a,T1 b){
		return max(a,b);
	}
	
	T1 func2(T1 a,T2 b,long long sz){
		return a+b;
	}

	void show(){
		int n = 1;
		for(int i=1;i<v1.size();i++){
			for(int j=0;j<n;j++){
				if(j!=0)cout<<' ';
				cout<<v1[i+j];
			}
			cout<<endl;
			i+=n-1;
			n*=2;
		}
	}
	
};

int main(){
	
	int n,m,p;
	cin>>n>>m>>p;
	
	int X = 1000005;
	
	vector<long long> a(X,-Inf),b(X,-Inf);
	
	for(int i=0;i<n;i++){
		long long A,CA;
		scanf("%lld %lld",&A,&CA);
		a[A] = max(a[A],-CA);
	}
	
	for(int i=0;i<m;i++){
		long long A,CA;
		scanf("%lld %lld",&A,&CA);
		
		b[A] = max(b[A],-CA);
	}
	

	
	for(int i=X-2;i>=0;i--){
		a[i] = max(a[i],a[i+1]);
		b[i] = max(b[i],b[i+1]);
	}
	
	
	
	lazysegtree<long long,long long> seg(b);
	
	vector<vector<long long>> V(p,vector<long long>(3));
	
	for(int i=0;i<p;i++){
		scanf("%lld %lld %lld",&V[i][0],&V[i][1],&V[i][2]);
	}
	
	sort(V.begin(),V.end());
	
	long long ans = a[0]+b[0];
	
	for(int i=0;i<p;i++){
		long long t = a[V[i][0]+1];
		seg.update(V[i][1]+1,X,V[i][2]);
		
		t += seg.query(0,X);
		ans = max(ans,t);

	}
	
	
	cout<<ans<<endl;
	
	return 0;
}