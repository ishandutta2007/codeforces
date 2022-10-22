#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000

template <typename T1,typename T2>
struct lazysegtree{
	//x[i]v[n+i]
	//v[i]v[i/2],v[i*2]v[i*2+1]
	vector<T1> v1;
	vector<T2> v2;
	vector<int> sz_;
	int n;
	int cnt;
	
	const T1 init_value1 = 0;
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
		return a+b;
	}
	
	T1 func2(T1 a,T2 b,long long sz){
		return a+b*sz;
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
	
	int n;
	cin>>n;
	
	vector<long long> a(n);
	
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	
	vector<long long> k(n-1);
	for(int i=0;i<n-1;i++){
		scanf("%lld",&k[i]);
	}
	
	map<int,int> mp;
	mp[0] = 0;
	
	for(int i=1;i<n;i++){
		if(a[i]-k[i-1]==a[i-1]){
			(*mp.rbegin()).second = i;
		}
		else{
			mp[i] = i;
		}
	}
	
	lazysegtree<long long,long long> seg(a);
	
	int q;
	cin>>q;
	
	for(int i=0;i<q;i++){
		char c;
		int x,y;

		getchar(); 

		scanf("%c %d %d",&c,&x,&y);
		//cout<<c<<','<<x<<','<<y<<endl;
		if(c=='+'){
			x--;
			auto it = mp.upper_bound(x);
			it--;
			
			if((*it).first != x){
				int k = (*it).second;
				(*it).second = x-1;
				mp[x] = k;
				it = mp.lower_bound(x);
			}
			
			seg.update((*it).first,(*it).second+1,y);
			
			while(true){
				it = mp.lower_bound(x);
				int A = (*it).second;
				if(A==n-1)break;
				long long V1 = seg.query(A,A+1),V2 = seg.query(A+1,A+2);
				long long dif = V1 + k[A] - V2;
				if(dif<=0)break;
				it ++;
				seg.update((*it).first,(*it).second+1,dif);
				int k = (*it).second;
				mp.erase(it);
				it = mp.lower_bound(x);
				(*it).second = k;
			}
			
		}
		else{
			printf("%lld\n",seg.query(x-1,y));
		}
	}
	
	
	
    return 0;
}