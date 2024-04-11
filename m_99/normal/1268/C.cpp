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

priority_queue<long long> P1;
priority_queue<long long,vector<long long>,greater<long long>> P2;
long long S1 = 0;
long long S2 = 0;

void check(){
	while(true){
		if(P1.size()<P2.size()){
			P1.push(P2.top());
			S1 += P2.top();
			S2 -= P2.top();
			P2.pop();
			continue;
		}
		if(P1.size() > P2.size()+1){
			P2.push(P1.top());
			S2 += P1.top();
			S1 -= P1.top();
			P1.pop();
			continue;
		}
		if(P1.size()!=0&&P2.size()!=0&&P1.top()>P2.top()){
			P2.push(P1.top());
			S2 += P1.top();
			S1 -= P1.top();
			P1.pop();
			continue;
		}
		break;
	}
}

int main(){
	
	int n;
	cin>>n;
	
	vector<long long> p(n);
	vector<long long> pos(n);
	for(int i=0;i<n;i++){
		scanf("%lld",&p[i]);
		pos[p[i]-1] = i;
	}
	
	vector<long long> tentou(n,0);
	segtree<long long> seg(n);
	for(int i=0;i<n;i++){
		tentou[i] = seg.query(pos[i],n);
		seg.update(pos[i],1);
	}
	
	for(int i=1;i<n;i++){
		tentou[i] += tentou[i-1];
	}
	
	vector<long long> ans(n);
	
	long long now = 0;
	
	for(int i=0;i<n;i++){
		now += (i+1)/2;
		P2.push(pos[i]);
		S2 += pos[i];
		check();
		//cout<<S1<<','<<S2<<endl;
		long long m = P1.top();
		long long a = P1.size() * m - S1;
		a += S2 - P2.size() * m;
		a -= now;
		ans[i] = a + tentou[i];
	}
	
	for(int i=0;i<n;i++){
		if(i!=0)cout<<' ';
		printf("%lld",ans[i]);
	}
	cout<<endl;
	
	
	return 0;
}