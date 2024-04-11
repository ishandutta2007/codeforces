#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000000

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

	int n,m;
	cin>>n>>m;
	
	vector<int> mini(n),maxi(n,1);
	vector<int> ind(n);
	for(int i=0;i<n;i++){
		mini[i] = i+1;
		ind[i] = m+10+i;
	}
	
	vector<int> a(m);
	for(int i=0;i<m;i++){
		scanf("%d",&a[i]);
		a[i]--;
		mini[a[i]] = 1;
	}

	lazysegtree<int,int> seg(n+m+100);
	
	for(int i=0;i<n;i++){
		seg.update(ind[i],ind[i]+1,i+1);
	}
	//seg.show();
	int last = m+2;
	for(int i=0;i<m;i++){
		int k = seg.query(ind[a[i]],ind[a[i]]+1);
		maxi[a[i]] = max(maxi[a[i]],k);
		seg.update(last+1,ind[a[i]],1);
		seg.update(ind[a[i]],ind[a[i]]+1,-k);
		seg.update(last,last+1,1);
		ind[a[i]] = last;
		last--;
		//seg.show();
	}
	
	for(int i=0;i<n;i++){
		maxi[i] = max(maxi[i],seg.query(ind[i],ind[i]+1));
	}
	
	for(int i=0;i<n;i++){
		printf("%d %d\n",mini[i],maxi[i]);
	}
	
	return 0;
}