#include <bits/stdc++.h>
using namespace std;

using ll=long long;
//#define int ll

#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=a;i--)
#define per(i,b) gnr(i,0,b)
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
#ifdef LOCAL
#define dmp(x) cerr<<__LINE__<<" "<<#x<<" "<<x<<endl
#else
#define dmp(x) void(0)
#endif

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;

using pi=pair<int,int>;
using vi=vc<int>;

template<class t,class u>
ostream& operator<<(ostream& os,const pair<t,u>& p){
	return os<<"{"<<p.a<<","<<p.b<<"}";
}

template<class t> ostream& operator<<(ostream& os,const vc<t>& v){
	os<<"{";
	for(auto e:v)os<<e<<",";
	return os<<"}";
}

/*
int cnt(vi p){
	int n=p.size();
	vi dp(1<<n);
	rng(bit,1,1<<n){
		dp[bit]=n;
		int sub=bit;
		do{
			vi idx;
			rep(i,n)if(sub&1<<i)
				idx.pb(i);
			bool ok=true;
			rep(i,idx.size()-2){
				if((p[idx[i]]<p[idx[i+1]])!=(p[idx[i+1]]<p[idx[i+2]]))
					ok=false;
			}
			if(ok)
				chmin(dp[bit],dp[bit^sub]+1);
			sub=(sub-1)&bit;
		}while(sub!=bit);
	}
	return dp[int(1<<n)-1];
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	rng(n,1,9){
		vi p(n);
		iota(all(p),0);
		int mx=0;
		do{
			chmax(mx,cnt(p));
		}while(next_permutation(all(p)));
		cout<<n<<" "<<mx<<endl;
	}
}
*/

void slv(){
	int n;cin>>n;
	vi mn(n+1);
	for(int k=1;k*(k+1)/2<=n;k++)
		mn[k*(k+1)/2]=k;
	rep(i,n)
		chmax(mn[i+1],mn[i]);
	vi a(n);
	rep(i,n){
		cin>>a[i];
		a[i]--;
	}
	vi buf,pre(n),lis(n),use(n);
	vvc<int> ans;
	while(a.size()){
		int s=a.size();
		buf.assign(s+1,1e9);
		buf[0]=-1;
		pi mx(-1,-1);
		for(auto v:a){
			int i=lower_bound(all(buf),v)-buf.bg;
			pre[v]=buf[i-1];
			lis[v]=i;
			buf[i]=v;
			chmax(mx,pi(i,v));
		}
		int len=mx.a;
		if(len<=mn[s]){
			int m=ans.size();
			ans.resize(m+len);
			for(auto v:a)
				ans[m-1+lis[v]].pb(v);
			break;
		}else{
			int cur=mx.b;
			vi ad;
			while(cur!=-1){
				use[cur]=1;
				ad.pb(cur);
				cur=pre[cur];
			}
			reverse(all(ad));
			ans.pb(ad);
			int j=0;
			rep(i,s)if(!use[a[i]])
				a[j++]=a[i];
			a.resize(j);
		}
	}
	cout<<ans.size()<<"\n";
	for(auto idx:ans){
		cout<<idx.size();
		for(auto i:idx)
			cout<<" "<<i+1;
		cout<<"\n";
	}
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int t;cin>>t;
	rep(_,t)slv();
}