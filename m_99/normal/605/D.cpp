#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000010

template <typename T,typename F>
struct segtree{
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

	int n;
	cin>>n;
	
	vector<int> a(n),b(n),c(n),d(n);
	
	for(int i=0;i<n;i++){
		scanf("%d %d %d %d",&a[i],&b[i],&c[i],&d[i]);
	}
	
	vector<pair<pair<int,int>,int>> V(n);
	for(int i=0;i<n;i++){
		V[i] = make_pair(make_pair(a[i],b[i]),i);
	}
	
	sort(V.begin(),V.end());
	
	auto f = [](pair<int,int> a,pair<int,int> b){
		return min(a,b);
	};
	pair<int,int> INF(Inf,-1);
	segtree<pair<int,int>,decltype(f)> seg(n,f,INF);
	vector<int> ind(n);
	for(int i=0;i<n;i++){
		seg.update(i,make_pair(V[i].first.second,V[i].second));
		ind[V[i].second] = i;
	}

	vector<int> dis(n,Inf);
	queue<int> Q;
	Q.push(-1);
	vector<int> last(n,-1);
	while(Q.size()>0){
		int u = Q.front();
		Q.pop();
		int x,y;
		int D;
		if(u==-1){
			x=0,y=0;
			D=0;
		}
		else{
			x=c[u],y=d[u];
			D=dis[u];
		}

		int R = distance(V.begin(),upper_bound(V.begin(),V.end(),make_pair(make_pair(x,Inf),Inf)));
		while(true){
			pair<int,int> P = seg.query(0,R);
			if(P.first>y)break;
			dis[P.second] = D+1;
			Q.push(P.second);
			seg.update(ind[P.second],INF);
			last[P.second] = u;
		}
		
	}
	
	if(dis.back()==Inf)cout<<-1<<endl;
	else{
		cout<<dis.back()<<endl;
		int now = n-1;
		vector<int> ans(1,n-1);
		while(true){
			now = last[now];
			if(now==-1)break;
			ans.push_back(now);
		}
		reverse(ans.begin(),ans.end());
		for(int i=0;i<ans.size();i++){
			if(i!=0)cout<<' ';
			cout<<ans[i]+1;
		}
		cout<<endl;
	}

	return 0;
}