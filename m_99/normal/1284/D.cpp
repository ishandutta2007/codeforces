#include <bits/stdc++.h>
using namespace std;
#define modulo 924844033
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000

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
struct segtree1{
	//x[i]v[n+i]
	//v[i]v[i/2],v[i*2]v[i*2+1]
	vector<T> v;
	int n;
	
	const T init_value = 0;
	
	segtree1(int sz){
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
	
	segtree1(vector<T> &x){
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

template <typename T>
struct segtree2{
	//x[i]v[n+i]
	//v[i]v[i/2],v[i*2]v[i*2+1]
	vector<T> v;
	int n;
	
	const T init_value = 1;
	
	segtree2(int sz){
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
	
	segtree2(vector<T> &x){
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
		return mod(a*b);
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

template <typename T>
struct segtree3{
	//x[i]v[n+i]
	//v[i]v[i/2],v[i*2]v[i*2+1]
	vector<T> v;
	int n;
	
	const T init_value = 0;
	
	segtree3(int sz){
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
	
	segtree3(vector<T> &x){
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
		return a^b;
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
	
	vector<pair<pair<int,int>,int>> a(n),b(n);
	
	map<int,int> mp;
	
	for(int i=0;i<n;i++){
		scanf("%d %d %d %d",&a[i].first.second,&a[i].first.first,&b[i].first.second,&b[i].first.first);
		mp[a[i].first.first]=0;
		mp[a[i].first.second]=0;
		mp[b[i].first.first]=0;
		mp[b[i].first.second]=0;
		a[i].second = i;
		b[i].second = i;
	}
	
	int now = 0;
	for(auto &x:mp){
		x.second = now;
		now++;
	}
	
	for(int i=0;i<n;i++){
		a[i].first.first = mp[a[i].first.first];
		a[i].first.second = mp[a[i].first.second];
		b[i].first.first = mp[b[i].first.first];
		b[i].first.second = mp[b[i].first.second];
	}
	
	vector<vector<long long>> h1(n,vector<long long>(3));
	vector<vector<long long>> h2(n,vector<long long>(3));
	
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	
	{
		segtree1<long long> seg1A(now),seg1B(now);
		segtree2<long long> seg2A(now),seg2B(now);
		segtree3<long long> seg3A(now),seg3B(now);
		
		for(int i=0;i<n;i++){
			int r = a[i].first.first;
			int l = a[i].first.second;
			int ind = a[i].second+2;
			seg1B.update(l,seg1B.query(l,l+1)+ind);
			seg2B.update(l,mod(seg2B.query(l,l+1)*ind));
			seg3B.update(l,seg3B.query(l,l+1)^ind);
		}
		
		for(int i=0;i<n;i++){
			int r = a[i].first.first;
			int l = a[i].first.second;
			int ind = a[i].second+2;
			seg1B.update(l,seg1B.query(l,l+1)-ind);
			seg2B.update(l,mod(seg2B.query(l,l+1)*gyakugen(ind)));
			seg3B.update(l,seg3B.query(l,l+1)^ind);
			//if(ind==2){
				//cout<<r<<endl;
				//seg1B.show();
			//}
			h1[ind-2][0] = seg1A.query(l,now)+seg1B.query(0,r+1);
			h1[ind-2][1] = mod(seg2A.query(l,now)*seg2B.query(0,r+1));
			h1[ind-2][2] = seg3A.query(l,now)^seg3B.query(0,r+1);
			
			seg1A.update(r,seg1A.query(r,r+1)+ind);
			seg2A.update(r,mod(seg2A.query(r,r+1)*ind));
			seg3A.update(r,seg3A.query(r,r+1)^ind);
			
		}
		
	}
	
	{
		segtree1<long long> seg1A(now),seg1B(now);
		segtree2<long long> seg2A(now),seg2B(now);
		segtree3<long long> seg3A(now),seg3B(now);
		
		for(int i=0;i<n;i++){
			int r = b[i].first.first;
			int l = b[i].first.second;
			int ind = b[i].second+2;
			seg1B.update(l,seg1B.query(l,l+1)+ind);
			seg2B.update(l,mod(seg2B.query(l,l+1)*ind));
			seg3B.update(l,seg3B.query(l,l+1)^ind);
		}
		
		for(int i=0;i<n;i++){
			int r = b[i].first.first;
			int l = b[i].first.second;
			int ind = b[i].second+2;
			seg1B.update(l,seg1B.query(l,l+1)-ind);
			seg2B.update(l,mod(seg2B.query(l,l+1)*gyakugen(ind)));
			seg3B.update(l,seg3B.query(l,l+1)^ind);
			
			h2[ind-2][0] = seg1A.query(l,now)+seg1B.query(0,r+1);
			h2[ind-2][1] = mod(seg2A.query(l,now)*seg2B.query(0,r+1));
			h2[ind-2][2] = seg3A.query(l,now)^seg3B.query(0,r+1);
			
			seg1A.update(r,seg1A.query(r,r+1)+ind);
			seg2A.update(r,mod(seg2A.query(r,r+1)*ind));
			seg3A.update(r,seg3A.query(r,r+1)^ind);
			
		}
		
	}
	/*
	for(int i=0;i<n;i++){
		cout<<i<<':'<<h1[i][0]<<','<<h1[i][1]<<','<<h1[i][2]<<endl;
		cout<<i<<':'<<h2[i][0]<<','<<h2[i][1]<<','<<h2[i][2]<<endl<<endl;;
	}
	*/
	
	if(h1==h2){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
	
	
	
    return 0;
}