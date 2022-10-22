#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000

template <typename T,typename F>
struct segtree{
	//x[i]v[n+i]
	//v[i]v[i/2],v[i*2]v[i*2+1]
	F func;
	vector<T> v;
	int n;
	
	T init_value;
	
	segtree(int sz,F f,T iv):func(f){
		init_value = iv;
		n=1;
		while(true){
			if(n>=sz)break;
			n*=2;
		}
		v.resize(2*n,init_value);

		for(int i=n-1;i>=0;i--){
			v[i]=func(v[i<<1],v[(i<<1)+1]);
		}
	}
	
	segtree(vector<T> &x,F f,T iv):func(f){
		init_value = iv;
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
			v[i]=func(v[i<<1],v[(i<<1)+1]);
		}
	}

	void update(int x,T val){
		x+=n;
		v[x]=val;
		while(x>0){
			x>>=1;
			v[x]=func(v[x<<1],v[(x<<1)+1]);
		}
	}
	
	//[l,r)
	T query(int l,int r){
		if(l>=r)return init_value;
		l+=n;
		r+=n;
		T res1 = init_value;
		T res2 = init_value;
		while(true){
			if(l&1){
				res1=func(res1,v[l++]);
			}
			if(r&1){
				res2=func(v[--r],res2);
			}
			if(l>=r)break;
			l>>=1;r>>=1;
		}
		return func(res1,res2);
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
	
	int n,k;
	cin>>n>>k;
	
	vector<int> l(k),r(k);
	for(int i=0;i<k;i++)cin>>l[i]>>r[i];

	auto f = [](int a,int b){
		return min(a,b);
	};
	
	l.push_back(2*n);
	r.push_back(2*n);
	
	vector<vector<segtree<int,decltype(f)>>> dp(k+1,vector<segtree<int,decltype(f)>>(2,segtree<int,decltype(f)>(n+1,f,Inf)));
	
	if(l[0]>n){
		cout<<"Hungry"<<endl;
		return 0;
	}
	
	dp[0][0].update(l[0],0);
	
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			int B = j-(l[i]-l[i-1]);

			if(B>=0){
				int X = dp[i-1][0].query(B,B+1);
				int A = max(0,j-(l[i]-r[i-1]));
				swap(A,B);
				int Y = dp[i-1][0].query(A,B+1)+2;
				int Z = dp[i-1][1].query(A,B+1)+1;
				dp[i][0].update(j,min({X,Y,Z}));
			}
			
			
			
			int X = dp[i-1][1].query(j,j+1);
			B = max(0,j-(r[i-1]-l[i-1]));
			int Y = dp[i-1][1].query(B,j+1)+2;
			int Z = dp[i-1][0].query(B,j+1)+1;
			
			dp[i][1].update(j,min({X,Y,Z}));
			
		}
	}
	
	//dp[1][0].show();
	//dp[1][1].show();
	
	int ans = min(dp.back()[0].query(n,n+1),dp.back()[1].query(n,n+1));
	
	if(ans==Inf){
		cout<<"Hungry"<<endl;
	}
	else{
		cout<<"Full"<<endl;
		cout<<ans<<endl;
	}
	
	return 0;
}