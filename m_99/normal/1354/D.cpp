#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000

template <typename T>
struct BIT{
	vector<T> v;
	int n;
	
	const T init_value = 0;
	
	BIT(int sz){
		n=sz+1;
		v.resize(n,init_value);
	}
	
	BIT(vector<T> &x){
		n=x.size()+1;
		v.resize(n,init_value);
		
		for(int i=0;i<x.size();i++){
			add(i,x[i]);
		}
		
	}

	void add(int x,T val){
		x++;
		while(x < n){
			v[x] = func(v[x],val);
			x += x & (-x);
		}
	}
	
	//[0,r)
	T query(int r){
		T ret = init_value;
		
		while(r>0){
			ret = func(v[r],ret);
			r -= r & (-r);
		}
		
		return ret;
	}
	
	T query(int l,int r){
		return query(r) - query(l);
	}
	
	T func(T a,T b){
		return a+b;
	}
	
};

int main(){
	
	BIT<int> B(1000000);
	int n,q;
	scanf("%d %d",&n,&q);
	
	for(int i=0;i<n;i++){
		int a;
		scanf("%d",&a);
		a--;
		B.add(a,1);
	}
	
	for(int i=0;i<q;i++){
		int k;
		scanf("%d",&k);
		if(k>0){
			B.add(k-1,1);
		}
		else{
			k*=-1;
			int ok = 0;
			int ng = 1000001;
			while(ng-ok>1){
				int mid = (ok+ng)/2;
				if(B.query(mid)<k)ok = mid;
				else ng = mid;
			}
			B.add(ok,-1);
		}
	}
	int ok = 0;
	int ng = 1000001;
	while(ng-ok>1){
		int mid = (ok+ng)/2;
		if(B.query(mid)<1)ok = mid;
		else ng = mid;
	}
	
	if(ok==1000000)cout<<0<<endl;
	else cout<<ng<<endl;
	
	return 0;
}