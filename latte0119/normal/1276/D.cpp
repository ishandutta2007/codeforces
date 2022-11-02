#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second

using vint=vector<int>;
using pint=pair<int,int>;
using vpint=vector<pint>;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

template<class A,class B>
ostream& operator<<(ostream& ost,const pair<A,B>&p){
	ost<<"{"<<p.first<<","<<p.second<<"}";
	return ost;
}

template<class T>
ostream& operator<<(ostream& ost,const vector<T>&v){
	ost<<"{";
	for(int i=0;i<v.size();i++){
		if(i)ost<<",";
		ost<<v[i];
	}
	ost<<"}";
	return ost;
}

template<uint32_t mod>
struct ModInt{
	uint32_t a;
	ModInt& s(uint32_t vv){
		a=vv<mod?vv:vv-mod;
		return *this;
	}

	ModInt(int64_t x=0){s(x%mod+mod);}

	ModInt& operator+=(const ModInt &x){return s(a+x.a);}
	ModInt& operator-=(const ModInt &x){return s(a+mod-x.a);}
	ModInt& operator*=(const ModInt &x){
		a=uint64_t(a)*x.a%mod;
		return *this;
	}
	ModInt& operator/=(const ModInt &x){
		*this*=x.inv();
		return *this;
	}

	ModInt operator+(const ModInt &x)const{return ModInt(*this)+=x;}
	ModInt operator-(const ModInt &x)const{return ModInt(*this)-=x;}
	ModInt operator*(const ModInt &x)const{return ModInt(*this)*=x;}
	ModInt operator/(const ModInt &x)const{return ModInt(*this)/=x;}
	bool operator==(const ModInt &x)const{return a==x.a;}
	bool operator!=(const ModInt &x)const{return a!=x.a;}
	bool operator<(const ModInt &x)const{return a<x.a;}

	ModInt operator-()const{return ModInt()-*this;}
	ModInt pow(int64_t n)const{
		ModInt res(1),x(*this);
		while(n){
			if(n&1)res*=x;
			x*=x;
			n>>=1;
		}
		return res;
	}

	ModInt inv()const{return pow(mod-2);}
};

template<uint32_t mod>
istream& operator>>(istream& in,ModInt<mod>& a){
	return (in>>a.a);
}
template<uint32_t mod>
ostream& operator<<(ostream& out,const ModInt<mod>& a){
	return (out<<a.a);
}
using mint=ModInt<998244353>;

int N;
vpint G[222222];
mint dp[222222][4];

void dfs(int v,int p,int pt){
	vpint lis;
	for(auto &e:G[v]){
		if(e.fi==p)continue;
		dfs(e.fi,v,e.se);
		lis.eb(e.se,e.fi);
	}
	sort(all(lis));
	int m=lower_bound(all(lis),pint(pt,-1))-lis.begin();
	int n=lis.size();
	vector<mint>pre(n+1);
	pre[0]=1;
	for(int i=0;i<n;i++){
		int u=lis[i].se;
		pre[i+1]=pre[i]*(dp[u][1]+dp[u][2]);
	}
	vector<mint>suf(n+1);
	suf[n]=1;
	for(int i=n-1;i>=0;i--){
		int u=lis[i].se;
		suf[i]=suf[i+1]*(dp[u][0]+dp[u][1]+dp[u][3]);
	}

	dp[v][0]=pre[n];
	dp[v][2]=pre[m]*suf[m];
	for(int i=0;i<n;i++){
		int u=lis[i].se;
		if(i<m){
			dp[v][1]+=pre[i]*suf[i+1]*(dp[u][0]+dp[u][3]);
		}
		else{
			dp[v][3]+=pre[i]*suf[i+1]*(dp[u][0]+dp[u][3]);
		}
	}
}
signed main(){
	scanf("%lld",&N);
	rep(i,N-1){
		int a,b;
		scanf("%lld%lld",&a,&b);
		a--;b--;
		G[a].eb(b,i);G[b].eb(a,i);
	}
	
	dfs(0,-1,-1);
	cout<<(dp[0][0]+dp[0][3])<<endl;
	return 0;
}