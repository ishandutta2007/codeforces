#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#pragma comment(linker, "/STACK:16000000")
//#define map gp_hash_table
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679
using namespace std;
using namespace __gnu_pbds;
#define int long long
using namespace std;
const int inf=0x3f3f3f3f;
const long long inf2=0x3f3f3f3f3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int n,k;
int fastpow(int x,int y){
	if(y==1)return x%mod;
	if(y&1){
		ll tmp=fastpow(x,y>>1);
		tmp=tmp*tmp%(ll)mod;
		tmp*=x;
		tmp%=mod;
		return tmp;
	}else{
		ll tmp=fastpow(x,y>>1);
		tmp=tmp*tmp%(ll)mod;
		return tmp;
	}
}
int inv(int x){
	return fastpow(x,mod-2);
}
const int maxn = 105;
ll x[maxn], ans;
queue<ll> aria;
ll min(ll a, ll b)
{
	if(a < b)	return a;
	else	return b;
}
ll multi(ll a, ll b, ll p)	// 
{
	ll ans = 0;
	while(b){
		if(b & 1LL)	ans = (ans+a)%p;
		a = (a+a)%p;
		b >>= 1;
	}
	return ans;
}
ll qpow(ll a, ll b, ll p)
{
	ll ans = 1;
	while(b){
		if(b & 1LL)	ans = multi(ans, a, p);
		a = multi(a, a, p);
		b >>= 1;
	}
	return ans;
}
 
bool MR(ll n)
{
	if(n == 2)	return true;
	int s = 20, i, t = 0;
	ll u = n-1;
	while(!(u&1)){
		t++;
		u >>= 1;
	}
	while(s--){
		ll a = rand()%(n-2)+2;
		x[0] = qpow(a, u, n);
		for(i = 1; i <= t; i++){
			x[i] = multi(x[i-1], x[i-1], n);
			if(x[i] == 1 && x[i-1] != 1 && x[i-1] != n-1)	return false;	
		}
		if(x[t] != 1)	return false;
	}
	return true;	
}
 
ll gcd(ll a, ll b)
{
	if(b == 0)	return a;
	else	return gcd(b, a%b);
}
 
ll Pollard_Rho(ll n, int c)
{
	ll i = 1, k = 2, x = rand()%(n-1)+1, y = x;
	while(1){
		i++;
		x = (multi(x, x, n)+c)%n;
		ll p = gcd((y-x+n)%n, n);
		if(p != 1 && p != n)	return p;
		if(y == x)	return n;
		if(i == k){
			y = x;
			k <<= 1;
		}	
	}
}
 
void find(ll n, int c)
{
	if(n == 1)	return;
	if(MR(n)){
		aria.push(n);
		return;
	}
	ll p = n, k = c;
	while(p >= n){
		p = Pollard_Rho(p, c--);
	}
	find(p, k);
	find(n/p, k);
}
vector<pair<int,int> >vect;
ll ANS=0;
int dp[11111][(int)log2(5e15)];
int dat[(int)log2(5e15)][11111];
void dfs(int x,int pos,int cur){
	if(pos==vect.size()){ANS+=(cur)%mod*(x%mod)%mod;ANS%=mod;return;}
	dfs(x,pos+1,cur*dat[pos][0]%mod);
	int mul=1;
	for(int i=1;i<=vect[pos].second;i++){
		mul*=vect[pos].first;
		int newcur=(ll)cur%mod*dat[pos][i]%mod;
		newcur%=mod;
		dfs(x*mul,pos+1,newcur);
	}
}
vector<int>primes;
int val[11111];
int dist[11111],tdist[11111];
int invs[11111];
map<int,int>All;
signed main(){
	cin>>n>>k;
	find(n,107);
	queue<ll>q=aria;
	while(q.size()){
		All[q.front()]++;
		q.pop();
	}
	vector<int>pows;
	for(auto p:All)primes.push_back(p.first),pows.push_back(p.second);
	for(int i=0;i<11111;i++)invs[i]=inv(i);
	for(int i=0;i<primes.size();i++)vect.push_back(make_pair(primes[i],pows[i]));
	for(int i=0;i<primes.size();i++){
		memset(dp,0,sizeof(dp));
		dp[0][pows[i]]=1;
		for(int t=0;t<k;t++){
			for(int j=0;j<=pows[i];j++)for(int tt=pows[i];tt>=j;tt--)dp[t+1][j]+=dp[t][tt]*invs[tt+1]%mod,dp[t+1][j]%=mod;
		}
		//cout<<i<<endl;
		//for(int j=0;j<=pows[i];j++)cout<<dp[k][j]<<" ";cout<<endl;
		for(int j=0;j<=pows[i];j++)dat[i][j]=dp[k][j]%mod;
	}
	dfs(1,0,1);
	int TT=ANS%mod;
	cout<<TT%mod<<endl;
	return 0;
}