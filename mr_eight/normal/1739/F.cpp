//#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <algorithm>
#include <climits>
#include <functional>
#include <cstring>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <complex>
#include <random>
#include <tr1/unordered_map>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define itn int
#define nit int
#define ll long long
#define ms multiset
#define F(i,a,b) for(register int i=a,i##end=b;i<=i##end;++i)
#define UF(i,a,b) for(register int i=a,i##end=b;i>=i##end;--i)
#define re register
#define ri re int
#define il inline
#define pii pair<int,int>
#define cp complex<double>
//#pra gma G CC opti mize(3)
using namespace std;
//using namespace __gnu_pbds;
const double Pi=acos(-1);
namespace fastIO {
	template<class T>
	inline void read(T &x) {
		x=0;
		bool fu=0;
		char ch=0;
		while(ch>'9'||ch<'0') {
			ch=getchar();
			if(ch=='-')fu=1;
		}
		while(ch<='9'&&ch>='0') x=(x*10-48+ch),ch=getchar();
		if(fu)x=-x;
	}
	inline int read() {
		int x=0;
		bool fu=0;
		char ch=0;
		while(ch>'9'||ch<'0') {
			ch=getchar();
			if(ch=='-')fu=1;
		}
		while(ch<='9'&&ch>='0') x=(x*10-48+ch),ch=getchar();
		return fu?-x:x;
	}
	template<class T,class... Args>
	inline void read(T& t,Args&... args) {
		read(t);
		read(args...);
	}
	char _n_u_m_[40];
	template<class T>
	inline void write(T x ) {
		if(x==0){
			putchar('0');
			return;
		}
		T tmp = x > 0 ? x : -x ;
		if( x < 0 ) putchar('-') ;
		register int cnt = 0 ;
		while( tmp > 0 ) {
			_n_u_m_[ cnt ++ ] = tmp % 10 + '0' ;
			tmp /= 10 ;
		}
		while( cnt > 0 ) putchar(_n_u_m_[ -- cnt ]) ;
	}
	template<class T>
	inline void write(T x ,char ch) {
		write(x);
		putchar(ch);
	}
}
using namespace fastIO;
int n,c[2002],w[4002],cnt;
char s[2002][2002];
vector<int>v[2002];
tr1::unordered_map<ll,int>V,W;
tr1::unordered_map<int,pair<int,ll> >dp[1<<12];
ll a[2002],b[2002];
int len[2002];
bool vis[15];
pair<int,ll>ans={0,-1};
inline void solve(vector<int>&v,char *s){
	int now=1;
	memset(vis,0,sizeof(vis));
	vis[s[1]-'a']=true;
	v.push_back(s[1]-'a');
	F(i,2,strlen(s+1)){
		if(!vis[s[i]-'a']){
			vis[s[i]-'a']=true;
			if(now==v.size()){
				++now;
				v.push_back(s[i]-'a');
			}else if(now==1){
				v.insert(v.begin(),s[i]-'a');
			}else{
				v.clear();
				return;
			}
		}else{
			if(now!=v.size()&&v[now]==s[i]-'a'){
				++now;
			}else if(now>1&&v[now-2]==s[i]-'a'){
				--now;
			}else{
				v.clear();
				return;
			}
		}
	}
}
struct T{
	int len;
	ll v;
}t[15];
inline bool operator<(const T &x,const T &y){
	return x.v<y.v;
}
inline T operator+(T x,T y){
	return {x.len+y.len,x.v<<(y.len<<2)|y.v};
}
inline ll ss(ll v,int l,int r){
	return v>>((l-1)<<2)&((1ll<<((r-l+1)<<2))-1);
}
inline void solve(ll s,int len){
	memset(vis,0,sizeof(vis));
	int num=12-len+1,now=1;
	t[num]={len,s};
	while(s)vis[s&15]=true,s>>=4;
	F(i,1,12)if(!vis[i])t[now++]={1,i};
	sort(t+1,t+num+1);
	do{
		T sum={0,0ll};
		F(i,1,num)sum=sum+t[i];
		ll v=sum.v;int tot=0;
		F(i,1,11)F(j,i+1,12)if(V.count(ss(v,i,j)))tot+=V[ss(v,i,j)];
		ans=max(ans,make_pair(tot,v));//cerr<<tot<<endl;
	}while(next_permutation(t+1,t+num+1));
}
inline int orz(ll qwq,int len){
	return W.count(qwq)?W[qwq]:(W[qwq]=(V.count(qwq)?V[qwq]:0)+orz(qwq&((1ll<<((len-1)<<2))-1),len-1));
}
inline int orz(ll qwq){
	return orz(qwq,(67-__builtin_clzll(qwq))>>2);
}
inline int gg(ll qwq){
	return (67-__builtin_clzll(qwq))>>2;
}
const int N=(1<<16)-1,K=(1<<12)-1;
const ll M=(1ll<<48)-1;
int main(){
	cin>>n;
	F(i,1,n)read(c[i]),scanf("%s",s[i]+1);
	F(i,1,n)solve(v[i],s[i]);
	F(i,1,n)if(v[i].size()){
		w[++cnt]=c[i];
		len[cnt]=v[i].size();
		for(int j:v[i]){
			a[cnt]=a[cnt]<<4|(j+1);
		}
		reverse(v[i].begin(),v[i].end());
		for(int j:v[i]){
			b[cnt]=b[cnt]<<4|(j+1);
		}
		V[a[cnt]]+=c[i],V[b[cnt]]+=c[i];
	//	cerr<<w[cnt]<<" "<<len[cnt]<<" "<<a[cnt]<<" "<<b[cnt]<<endl;
	}
	F(i,1,n){
		if(len[i]>=6){
			solve(a[i],len[i]);
		}
	}
	W[0]=0;
	dp[0][0]={0,0ll};
	F(i,0,(1<<12)-2){
		for(auto j:dp[i]){
			ll s=j.first,r=K^i;
			int v=j.second.first;
			ll S=j.second.second;
			for(int k=__builtin_ctz(r);r;r^=(-r&r),k=__builtin_ctz(r)){
				ans=max(ans,dp[i|(1ll<<k)][(s<<4|(k+1))&N]=max(dp[i|(1ll<<k)][(s<<4|(k+1))&N],make_pair(v+orz(s<<4|(k+1)),S<<4|(k+1))));
			}
		}
	}
	while(ans.second){
		putchar('a'+(ans.second&15)-1);
		ans.second>>=4;
	}
    return 0;
}