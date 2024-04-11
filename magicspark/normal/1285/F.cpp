/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
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
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n;
ll ans=0;
int hv[100005];
vector<int>have;
vector<int>mul[100005];
vector<vector<int> >factors[100005];
bool prime[100005];
int primes[100005],szp,szb;
int id[100005];
unsigned int bits[9592][100005/32+5],now[100005/32+5];
void init_prime(){
	for(int i=2;i<=1e5;i++)prime[i]=1;
	for(int i=2;i<=1e5;i++){
		if(prime[i]){
			for(ll j=(ll)i*i;j<=1e5;j+=i)prime[j]=0;
		}
	}
	for(int i=2;i<=1e5;i++){
		if(prime[i]){
			id[i]=szp;
			primes[szp++]=i;
		}
	}
	//szp=9592
}
void bitset_init(int SIZE){
	szb=(SIZE+31)/32;
	for(int i=0;i<szp;i++){
		memset(bits[i],0,sizeof bits[i][0]*szb);
	}
}
void bitset_or(unsigned int *a,unsigned int *b){
	for(int i=0;i<szb;i++)a[i]|=b[i];
}
const unsigned int full=4294967295u;
int find_zero(unsigned int *a){
	for(int i=0;i<szb;i++){
		if(a[i]!=full){
			for(int j=0;j<32;j++)if((a[i]&(1<<j))==0)return i*32+j;
		}
	}
	return inf;
}
vector<int>get_p(int x){
	vector<int>ret;
	for(int i=2;i*i<=x;i++){
		if(x%i==0){
			ret.push_back(id[i]);
			while(x%i==0)x/=i;
		}
	}
	if(x!=1)ret.push_back(id[x]);
	return move(ret);
}
void bitset_set(int pos,int v){
	bits[pos][v>>5]|=(1<<(v&31));
}
void solve(int z){
	vector<int>cur;cur.swap(mul[z]);
	vector<vector<int> >vfp;vfp.swap(factors[z]);
	bitset_init(cur.size());
//	cerr<<z<<endl;
//	for(auto x:cur)cerr<<x<<" ";cerr<<endl;
	int limit=cur.size();
	for(int i=0;i<cur.size();i++){
		int x=cur[i];
		vector<int>vec;
		for(auto u:vfp[i])if(x%u==0)vec.push_back(id[u]);
		for(auto y:vec)bitset_set(y,i);
	}
	for(int i=0;i<cur.size();i++){
		memset(now,0,sizeof now[0]*szb);
		int x=cur[i];
		vector<int>vec;
		for(auto u:vfp[i])if(x%u==0)vec.push_back(id[u]);
		for(auto y:vec)bitset_or(now,bits[y]);
		int tmp=find_zero(now);
		limit=min(limit,tmp);
		if(tmp<cur.size()){
			int y=cur[tmp];ans=max(ans,(ll)x*y*z);
		}
	}
}
int main(){
	init_prime();
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;cin>>x;hv[x]++;
		if(hv[x]>=2)ans=max(ans,(ll)x);
	}
	for(int i=1;i<=1e5;i++)if(hv[i])have.push_back(i);
	reverse(have.begin(),have.end());
	for(auto x:have){
		set<int>factor;
		for(int i=1;i<=sqrt(x);i++){
			if(x%i==0)factor.insert(i);
			if(x%i==0)factor.insert(x/i);
		}
		vector<int>factor_p;
		for(auto y:factor)if(prime[y])factor_p.push_back(y);
		for(auto y:factor){
			mul[y].push_back(x/y);
			factors[y].push_back(factor_p);
		}
	}
	for(int i=1;i<=1e5;i++){
		if(mul[i].size()>=2){
			solve(i);
//			cerr<<ans<<" "<<100000ll*99999ll/(i+1)<<endl;
			if(ans>=100000ll*99999ll/(i+1))break;
		}
	}
	cout<<ans<<endl;
	return 0;
}