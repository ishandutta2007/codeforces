#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000

struct D{
	int c1=0,c2=0;
	D(){
	}
};

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
	
	int n,m;
	cin>>n>>m;
	vector<int> h(n);
	vector<int> t;
	for(int i=0;i<n;i++){
		scanf("%d",&h[i]);
		t.push_back(h[i]);
	}
	
	vector<int> a(m),b(m);
	for(int i=0;i<m;i++){
		scanf("%d %d",&a[i],&b[i]);
		a[i]--;
		t.push_back(b[i]);
	}
	
	sort(t.begin(),t.end());
	t.erase(unique(t.begin(),t.end()),t.end());
	int T = t.size();
	for(int i=0;i<n;i++){
		h[i] = distance(t.begin(),lower_bound(t.begin(),t.end(),h[i]));
	}
	
	for(int i=0;i<m;i++){
		b[i] = distance(t.begin(),lower_bound(t.begin(),t.end(),b[i]));
	}
	
	auto f = [](D a,D b){
		D ret;
		ret.c1 = max(a.c1,b.c1);
		ret.c2 = max(a.c2,b.c2);
		return ret;
	};
	
	segtree<D,decltype(f)> seg(t.size(),f,D());
	vector<int> LISs(n);
	vector<pair<int,int>> LOG;
	for(int i=n-1;i>=0;i--){
		D pre = seg.query(h[i],h[i]+1);
		LOG.emplace_back(h[i],pre.c2);
		LISs[i] = seg.query(h[i]+1,T).c2+1;
		pre.c2 = max(pre.c2,LISs[i]);
		
		seg.update(h[i],pre);
	}
	int ans1 = seg.query(0,T).c2;
	vector<int> mini(n+1,Inf+3),cnt(n+1,0);
	vector<bool> used(n,false);
	for(int i=0;i<n;i++){
		int l = LISs[i];
		if(l==ans1){
			cnt[l]++;
			mini[l] = min(mini[l],h[i]);
			used[i]=true;
		}
		else{
			if(h[i]>mini[l+1]){
				cnt[l]++;
				mini[l] = min(mini[l],h[i]);
				used[i]=true;
			}
		}
	}
	
	

	for(int i=0;i<n;i++){
		if(used[i]){
			if(cnt[LISs[i]]!=1)used[i]=false;
		}
	}/*
	for(int i=0;i<n;i++){
		cout<<used[i]<<endl;
	}
	*/
	
	reverse(LOG.begin(),LOG.end());
	
	vector<vector<pair<int,int>>> query(n,vector<pair<int,int>>());
	for(int i=0;i<m;i++){
		query[a[i]].emplace_back(i,b[i]);
	}
	
	vector<int> ans(m);
	
	for(int i=0;i<n;i++){
		D now = seg.query(LOG[i].first,LOG[i].first+1);
		now.c2 = LOG[i].second;

		seg.update(LOG[i].first,now);
		for(int j=0;j<query[i].size();j++){
			int ind = query[i][j].first;
			int v = query[i][j].second;
			ans[ind]=ans1;
			if(used[i])ans[ind]--;

			ans[ind] = max(seg.query(0,v).c1 + seg.query(v+1,T).c2 + 1,ans[ind]);
		}
		
		now = seg.query(h[i],h[i]+1);
		now.c1 = max(now.c1,seg.query(0,h[i]).c1+1);

		seg.update(h[i],now);
		
	}
	
	for(int i=0;i<m;i++){
		printf("%d\n",ans[i]);
	}
	
	return 0;
}