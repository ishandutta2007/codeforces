#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000

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

int main(){
	
	int n;
	cin>>n;
	
	map<int,int> mp;
	
	vector<int> a(n),b(n);
	
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	for(int i=0;i<n;i++){
		scanf("%d",&b[i]);
	}
	
	for(int i=0;i<n;i++){
		mp[b[i]-a[i]]=0;
	}
	
	mp[1000000003]=0;
	
	int now = 0;
	for(auto &x:mp){
		//cout<<a.first<<endl;
		x.second = now;
		now++;
	}
	
	
	segtree<long long> B(now);
	
	long long ans = 0;
	
	for(int i=0;i<n;i++){
		int ind = (*(mp.lower_bound(a[i]-b[i]))).second;
		ans += B.query(0,ind);
		B.update(mp[b[i]-a[i]],B.query(mp[b[i]-a[i]],mp[b[i]-a[i]]+1)+1LL);
		//B.show();
	}
	
	cout<<ans<<endl;
	
	return 0;
}