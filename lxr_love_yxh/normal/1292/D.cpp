/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
#define int long long
#pragma comment("-Wl,--stack=1024000000")
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
#ifndef LOCAL
#define cerr if(0)cout
#define eprintf(...) 0
#else
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#endif
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){int ret=1;do{if(y&1)ret=(ll)ret*x%md;x=(ll)x*x%md;}while(y>>=1);return ret;}
int n;
int cnt[5005];
const int k=5000;
vector<int>primes;
bool is_prime(int x){
	for(int i=2;i*i<=x;i++)if(x%i==0)return false;return true;
}
struct num{
	signed cnt[5005];
}val[5005];
vector<pair<int,num> >hv;
bool dead[5005];
int calc(int x){
	int ret=0,now=0;
	for(auto &p:hv){
		if((!dead[now])&&(p.second.cnt[x]>=1))ret+=p.first;
		now++;
	}
	return ret;
}
void del(int x){
	int now=0;
	for(auto &p:hv){
		p.second.cnt[x]--;if(p.second.cnt[x]<0)dead[now]=1;
		now++;
	}
}
void func(int x){
	int now=0;
	for(auto &p:hv){
		if(p.second.cnt[x])dead[now]=1;now++;
	}
}
signed main(){
	scanf("%I64d",&n);
	for(int i=2;i<=k;i++)if(is_prime(i))primes.push_back(i);
	for(int i=1;i<=n;i++){
		int x;scanf("%I64d",&x);cnt[x]++;
	}
	ll ans=0;
	for(int i=1;i<=k;i++){
		for(auto x:primes){
			int tmp=i,all=0;
			while(tmp){
				tmp/=x;all+=tmp;
			}
			val[i].cnt[x]=all;
			ans+=all*cnt[i];
		}
	}
	for(int i=1;i<=k;i++)if(cnt[i])hv.push_back(make_pair(cnt[i],val[i]));
	ll show=1;
	reverse(primes.begin(),primes.end()); 
	for(auto x:primes){
		int v=calc(x);
		while(v+v>=n){
			show*=x;
			ans-=v*2-n;
			del(x);
			v=calc(x);
		}
		func(x);
	}
	cerr<<show<<endl;
	cout<<ans<<endl;
	return 0;
}