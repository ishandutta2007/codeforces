#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x)+modulo)%modulo)
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
	vector<int> sz_;
	int n;
	int cnt;
	
	const T0 init_value0 = 0;
	const T1 init_value1 = -1;
	
	lazysegtree(int sz,F0 f0,F1 f1,F2 f2):func0(f0),func1(f1),func2(f2){
		n=1;
		cnt=0;
		while(true){
			if(n>=sz)break;
			n*=2;
			cnt++;
		}
		v0.resize(2*n,init_value0);
		v1.resize(2*n,init_value1);

		for(int i=n-1;i>=0;i--){
			v0[i]=func0(v0[i<<1],v0[(i<<1)+1]);
		}
		
		sz_.resize(2*n,n);
		
		for(int i=2;i<2*n;i++){
			sz_[i] = sz_[i>>1]>>1;
		}
		
	}
	
	lazysegtree(vector<T0> &x,F0 f0,F1 f1,F2 f2):func0(f0),func1(f1),func2(f2){
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
		
		sz_.resize(2*n,n);
		
		for(int i=2;i<2*n;i++){
			sz_[i] = sz_[i>>1]>>1;
		}
		
	}

	//2
	void propagate(int ind){
		update(ind<<1,v1[ind]);
		update((ind<<1)+1,v1[ind]);
		v1[ind] = init_value1;
	}
	
	//
	void reflect(int ind){
		for(int j=cnt;j>=1;j--){
			propagate(ind>>j);
		}
	}
	
	//
	void mergeChildren(int ind){
		v0[ind] = func1(func0(v0[ind<<1],v0[(ind<<1)+1]),v1[ind],sz_[ind]);
	}
	
	//
	void update(int ind,T1 x){
		v0[ind] = func1(v0[ind],x,sz_[ind]);
		v1[ind] = func2(v1[ind],x);
	}
	
	//[l,r)
	void update(int l,int r,T1 x){
		if(l>=r)return;
		int L = l,R = r;
		l+=n;
		r+=n;
		reflect(l);
		reflect(r-1);
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
		r = R + n;
		
		while(true){
			l>>=1;
			r=(r+1)>>1;
			if(l<=0)break;
			mergeChildren(l);
			mergeChildren(r-1);
		}
		
	}
	
	//[l,r)
	T0 query(int l,int r){
		T0 res1 = init_value0;
		T0 res2 = init_value0;
		if(l>=r)return res1;
		l+=n;
		r+=n;
		reflect(l);
		reflect(r-1);
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

vector<long long> calc(vector<long long> &m){
	auto f0 = [](long long a,long long b){
		return a+b;
	};
	
	auto f1 = [](long long a,long long b,long long sz){
		if(b==-1)return a;
		return b*sz;
	};
	
	auto f2 = [](long long a,long long b){
		if(b==-1)return a;
		return b;
	};
	
	lazysegtree<long long,long long,decltype(f0),decltype(f1),decltype(f2)> seg((int)m.size(),f0,f1,f2);
	
	vector<long long> ret(m.size(),0);
	
	for(int i=0;i<m.size();i++){
		int ok = i;
		int ng = -1;
		while(ok-ng>1){
			int mid = (ok+ng)/2;
			if(seg.query(mid,mid+1)>m[i]){
				ok = mid;
			}
			else{
				ng = mid;
			}
		}
		seg.update(ok,i+1,m[i]);
		ret[i] = seg.query(0,m.size());
	}
	return ret;
	
}

int main() {
	
	int n;
	scanf("%d",&n);
	
	vector<long long> m(n);
	for(int i=0;i<n;i++){
		scanf("%lld",&m[i]);
	}
	
	auto ret1 = calc(m);
	reverse(m.begin(),m.end());
	auto ret2 = calc(m);
	reverse(ret2.begin(),ret2.end());
	reverse(m.begin(),m.end());
	
	long long maxi = -1;
	int ind;
	
	for(int i=0;i<n;i++){
		if(maxi<ret1[i]+ret2[i]-m[i]){
			ind = i;
			maxi = ret1[i]+ret2[i]-m[i];
		}
	}
	
	vector<long long> ans(n);
	
	ans[ind] = m[ind];
	
	for(int i=ind+1;i<n;i++){
		ans[i] = min(m[i],ans[i-1]);
	}
	
	for(int i=ind-1;i>=0;i--){
		ans[i] = min(m[i],ans[i+1]);
	}
	
	for(int i=0;i<n;i++){
		if(i!=0)printf(" ");
		printf("%lld",ans[i]);
	}
	cout<<endl;
	
	
    return 0;
}