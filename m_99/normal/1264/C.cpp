#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000000

//ab
int beki(int a,int b){
	int x = 1;
	while(b!=0){
		if(b&1){
			x=mod(x*a);
		}
		a=mod(a*a);
		b>>=1;
	}
	return x;
}

//a
int gyakugen(int a){
	return beki(a,modulo-2);
}

template <typename T>
struct segtree{
	//x[i]v[n+i]
	//v[i]v[i/2],v[i*2]v[i*2+1]
	vector<T> v;
	int n;
	
	const T init_value = make_pair(0,1);
	
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
		int ll = l;
		int rr = r;
		l+=n;r+=n;
		while(true){
			if(l%2==1){
				res1=func(res1,v[l]);
				l++;
			}
			if(r%2==1){
				r--;
			}
			if(l>=r)break;
			l/=2;r/=2;
		}
		l = ll + n;
		r = rr + n;
		while(true){
			if(l%2==1){
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
		return make_pair(mod(mod(a.first * b.second) + b.first),mod(a.second * b.second));
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
	vector<pair<int,int>> p(n);
	for(int i=0;i<n;i++){
		cin>>p[i].first;
		p[i].first = mod(100 * gyakugen(p[i].first));
		p[i].second = p[i].first;
	}
	
	segtree<pair<int,int>> seg(p);
	
	set<int> S;
	S.insert(0);
	S.insert(n);
	
	int ans = seg.query(0,n).first;
	
	for(int i=0;i<q;i++){
		int x;
		cin>>x;
		x--;
		
		if(S.count(x)){
			S.erase(x);
			auto it1 = S.lower_bound(x);
			auto it2 = it1;
			it2--;
			int ind1 = (*it2);
			int ind2 = (*it1);
			ans = mod(ans - seg.query(ind1,x).first);
			ans = mod(ans - seg.query(x,ind2).first);
			ans = mod(ans + seg.query(ind1,ind2).first);
		}
		else{
			auto it1 = S.lower_bound(x);
			auto it2 = it1;
			it2--;
			int ind1 = (*it2);
			int ind2 = (*it1);

			ans = mod(ans - seg.query(ind1,ind2).first);
			ans = mod(ans + seg.query(ind1,x).first);
			ans = mod(ans + seg.query(x,ind2).first);
			S.insert(x);
		}
		cout<<ans<<endl;
	}
	
	return 0;
}