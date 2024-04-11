#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000001

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
		return max(a,b);
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
	
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		
		vector<int> a(n);
		for(int j=0;j<n;j++){
			cin>>a[j];
		}
		segtree<int> seg(a);
		
		vector<int> maxi(n+1,0);
		int m;
		cin>>m;
		
		for(int j=0;j<m;j++){
			int p,s;
			cin>>p>>s;
			maxi[s] = max(maxi[s],p);
		}
		
		for(int j=n-1;j>=0;j--){
			maxi[j] = max(maxi[j],maxi[j+1]);
		}
		
		
		int ans = 0;
		int now = 0;
		while(now!=n){
			int ok = 0;
			int ng = n-now+1;
			while(ng-ok>1){
				int mid = (ok+ng)/2;
				int k = seg.query(now,now + mid);
				if(k>maxi[mid])ng=mid;
				else ok=mid;
			}
			//cout<<ok<<endl;
			if(ok==0){
				ans = -1;
				break;
			}
			now += ok;
			ans ++;
		}
		cout<<ans<<endl;
		
	}
	
	
    return 0;
}