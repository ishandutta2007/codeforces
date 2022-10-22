//Original Code:
//#define __TAKE_CONST_MOD 10007
//#include <self/utility>
//#include <self/debug>
//using namespace std;
//
//char c[205];
//int n,m;
//int dp[1605][205][205];
//int f[805];
//int g[805],len;
//int r[805],len2,fail;
//int t[805],len3;
//
//inline int fastpow(ll basic,int x)
//{
//	ll res=1;
//	while(x)
//	{
//		if(x&1) (res*=basic)%=mod;
//		(basic*=basic)%=mod;
//		x>>=1;
//	}
//	return res;
//}
//
//vector<int> operator * (const vector<int> &a,const vector<int> &b)
//{
//	if(a.empty()) return a;
//	if(b.empty()) return b;
//	vector<int> c(a.size()+b.size()-1);
//	for(int i=0;i<a.size();i++)
//	{
//		for(int j=0;j<b.size();j++)
//		{
//			c[i+j]=(1LL*a[i]*b[j]+c[i+j])%mod;
//		}
//	}
//	return c;
//}
//
//vector<int> operator % (const vector<int> &a,const vector<int> &b)
//{
//	if(a.size()<b.size()) return a;
//	vector<int> c=a;
//	for(int i=c.size()-b.size();i>=0;i--)
//	{
//		int mut=c[i+b.size()-1];
//		if(!mut) continue;
//		for(int j=0;j<b.size();j++)
//		{
//			chadd(c[i+j],mod-1LL*b[j]*mut%mod);
//		}
//	}
//	for(int i=b.size();i<c.size();i++) assert(c[i]==0);
//	c.resize(b.size()-1);
//	return c;
//}
//
//vector<int> fastpow(vector<int> Mod,int nn)
//{
//	vector<int> res={1};
//	vector<int> bas={0,1};
//	while(nn)
//	{
//		if(nn & 1) res=res*bas%Mod;
//		bas=bas*bas%Mod;nn>>=1;
//	}
//	return res;
//}
//
//int main()
//{
//	freopen("input.txt","r",stdin);
//	scanf("%s",c);
//	scanf("%d",&m);
//	n=strlen(c);m+=n;
//	dp[0][0][n-1]=1;
//	int B=1500+(m&1);
//	vector<int> T;
//	for(int i=0;i<B;i+=2)
//	{
//		for(int j=0;j<=n;j++)
//		{
//			for(int k=n-1;k>=max(0,j-1);k--)
//			{
//				T.clear();
//				if(j<n) T.emplace_back(c[j]);
//				if(T.size()==0 || c[j]!=c[k]) T.emplace_back(c[k]);
//				T.emplace_back('*');
//				// cout<<T<<endl;
//				if(!dp[i/2][j][k]) continue;
//				for(auto &ch:T)
//				// for(char ch='a';ch<='z';ch++)
//				{
//					int w=1LL*(ch=='*'?26-T.size()+1:1)*dp[i/2][j][k]%mod;
//					int nj=(j+(j<=k && c[j]==ch));
//					int nk=(k-(k>j && c[k]==ch && true));
//					chadd(dp[i/2+1][nj][nk],w);
//					if((m&1) && i+1>=n)
//					{
//						int nj=(j+(j<=k && c[j]==ch));
//						int nk=(k-(k>j && c[k]==ch && false));
//						if(nj==nk+1) chadd(f[(i+1-n)/2],w);
//					}
//					else if((!(m&1)) && i+2>=n)
//					{
//						int nj=(j+(j<=k && c[j]==ch));
//						int nk=(k-(k>j && c[k]==ch));
//						if(nj==nk+1) chadd(f[(i+2-n)/2],w);
//					}
//				}
//			}
//		}
//	}
//	int nn=(m-((m-n)&1)-n)/2;
//	fail=-1;
//	len=0;
//	for(int i=0;i<=620;i++)
//	{
//		int w=0;
//		for(int j=1;j<=len;j++)
//		{
//			w=(1LL*g[j-1]*f[i-j]+w)%mod;
//		}
//		if(w==f[i]) continue;
//		int d=(f[i]-w+mod)%mod;
//		int mut=0;
//		if(fail==-1)
//		{
//			len3=i+1;
//			for(int i=0;i<len3;i++) t[i]=0;
//		}
//		else
//		{
//			t[0]=1;
//			len3=len2+1;
//			for(int i=1;i<len3;i++) t[i]=mod-r[i-1];
//			rotate(t,t+len3,t+len3+i-fail-1);
//			memset(t,0,sizeof(int)*(i-fail-1));
//			len3+=i-fail-1;
//			for(int j=1;j<=len3;j++) chadd(mut,1LL*t[j-1]*f[i-j]%mod);
//			mut=1LL*fastpow(mut,mod-2)*d%mod;
//		}
//		len2=len;
//		fail=i;
//		memcpy(r,g,sizeof(int)*len);
//		chmax(len,len3);
//		for(int j=0;j<len3;j++) g[j]=(1LL*mut*t[j]+g[j])%mod;
//		// debug(len);
//		// for(int j=0;j<len;j++) cout<<g[j]<<" \n"[j==len-1];
//	}
//	// for(int i=len;i<=700;i++)
//	// {
//	// 	int s=0;
//	// 	for(int j=1;j<=len;j++) chadd(s,g[j-1]*f[i-j]%mod);
//	// 	cout<<i<<' '<<f[i]<<' '<<s<<endl;
//	// 	assert(f[i]==s);
//	// }
//	// cout<<(vector<int>({1,2,3,4}))%(vector<int>({1,mod-1,1}))<<endl;
//	vector<int> mod;for(int j=0;j<len;j++) mod.emplace_back(g[j]);
//	for(auto &x:mod) x=(::mod-x)%(::mod);
//	reverse(all(mod));mod.emplace_back(1);
//	// cout<<len<<endl;
//	// cout<<mod<<endl;
//	vector<int> dot=fastpow(mod,nn);
//	int res=0;
//	// cout<<dot<<endl;
//	for(int i=0;i<dot.size();i++) res=(1LL*f[i]*dot[i]+res)%(::mod);
//	cout<<res<<endl;
//	return 0;
//}

//substituted with C++ Inliner
#define __TAKE_CONST_MOD 10007
#ifndef _SELF_UTILITY
#define _SELF_UTILITY 1
#include <numeric>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <stack>
#include <assert.h>
#include <bitset>
#include <time.h>
#define Endl endl
#define mp(a,b) make_pair(a,b)
#define mt make_tuple
#define ll long long 
#define ull unsigned long long
#define pii pair<int,int>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define quickcin ios_base::sync_with_stdio(false);
#ifdef __TAKE_MOD
int mod;
#else
#ifdef __TAKE_CONST_MOD
const int mod=__TAKE_CONST_MOD;
#else
const int mod=1000000007;
#endif
#endif
const int gmod=3;
const int inf=1039074182;
#ifdef __TAKE_CONST_EPS
const double eps=__TAKE_CONST_EPS;
#else
const double eps=1e-9;
#endif
const double pi=3.141592653589793238462643383279;
const ll llinf=2LL*inf*inf;
template <typename T1,typename T2> inline void chmin(T1 &x,T2 b) {if(b<x) x=b;}
template <typename T1,typename T2> inline void chmax(T1 &x,T2 b) {if(b>x) x=b;}
inline void chadd(int &x,int b) {x+=b-mod;x+=(x>>31 & mod);}
template <typename T1,typename T2> inline void chadd(T1 &x,T2 b) {x+=b;if(x>=mod) x-=mod;}
template <typename T1,typename T2> inline void chmul(T1 &x,T2 b) {x=1LL*x*b%mod;}
template <typename T1,typename T2> inline void chmod(T1 &x,T2 b) {x%=b,x+=b;if(x>=b) x-=b;}
template <typename T> inline T mabs(T x) {return (x<0?-x:x);}
using namespace std;
#endif
#ifndef _SELF_DEBUG
#define _SELF_DEBUG 1
#ifndef _SELF_OPERATOR
#define _SELF_OPERATOR 1
using namespace std;
template <typename T>
ostream & operator<<(ostream &cout, const vector<T> &vec)
{
	cout << "{";
	for (int i = 0; i < (int)vec.size(); i++)
	{
		cout << vec[i];
		if (i != (int)vec.size() - 1)
			cout << ',';
	}
	cout << "}";
	return cout;
}

template <typename T1, typename T2>
ostream &operator<<(ostream &cout, pair<T1, T2> p)
{
	cout << "(" << p.first << ',' << p.second << ")";
	return cout;
}

template <typename T, typename T2>
ostream &operator<<(ostream &cout, set<T, T2> s)
{
	vector<T> t;
	for (auto x : s)
		t.push_back(x);
	cout << t;
	return cout;
}

template <typename T, typename T2>
ostream &operator<<(ostream &cout, multiset<T, T2> s)
{
	vector<T> t;
	for (auto x : s)
		t.push_back(x);
	cout << t;
	return cout;
}

template <typename T>
ostream &operator<<(ostream &cout, queue<T> q)
{
	vector<T> t;
	while (q.size())
	{
		t.push_back(q.front());
		q.pop();
	}
	cout << t;
	return cout;
}

template <typename T1, typename T2, typename T3>
ostream &operator<<(ostream &cout, map<T1, T2, T3> m)
{
	for (auto &x : m)
	{
		cout << "Key: " << x.first << ' ' << "Value: " << x.second << endl;
	}
	return cout;
}

template <typename T1, typename T2>
void operator+=(pair<T1, T2> &x,const pair<T1, T2> y)
{
	x.first += y.first;
	x.second += y.second;
}
template <typename T1,typename T2>
pair<T1,T2> operator + (const pair<T1,T2> &x,const pair<T1,T2> &y)
{
	return make_pair(x.first+y.first,x.second+y.second);
}

template <typename T1,typename T2>
pair<T1,T2> operator - (const pair<T1,T2> &x,const pair<T1,T2> &y)
{
	return mp(x.first-y.first,x.second-y.second);
}

template <typename T1, typename T2>
pair<T1, T2> operator-(pair<T1, T2> x)
{
	return make_pair(-x.first, -x.second);
}

template <typename T>
vector<vector<T>> operator~(vector<vector<T>> vec)
{
	vector<vector<T>> v;
	int n = vec.size(), m = vec[0].size();
	v.resize(m);
	for (int i = 0; i < m; i++)
	{
		v[i].resize(n);
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			v[i][j] = vec[j][i];
		}
	}
	return v;
}
#endif
#include <sstream>
void print0x(int x)
{
	std::vector <int> vec;
	while(x)
	{
		vec.push_back(x&1);
		x>>=1;
	}
	std::reverse(vec.begin(),vec.end());
	for(int i=0;i<(int)vec.size();i++)
	{
		std::cout<<vec[i];
	}
	std::cout<<' ';
}

template <typename T>
void print0x(T x,int len)
{
	std::vector <int> vec;
	while(x)
	{
		std::cout<<(x&1);
		x>>=1;
		len--;
		// vec.push_back(x&1);
		// x>>=1;
	}
	while(len--) cout<<0;
	// reverse(vec.begin(),vec.end());
	// for(int i=(int)vec.size();i<len;i++)
	// {
	// 	putchar('0');
	// }
	// for(size_t i=0;i<vec.size();i++)
	// {
	// 	std::cout<<vec[i];
	// }
	// std::cout<<' ';
}
vector<string> vec_splitter(string s) {
	s += ',';
	vector<string> res;
	while(!s.empty()) {
		res.push_back(s.substr(0, s.find(',')));
		s = s.substr(s.find(',') + 1);
	}
	return res;
}
void debug_out(
vector<string> __attribute__ ((unused)) args,
__attribute__ ((unused)) int idx, 
__attribute__ ((unused)) int LINE_NUM) { cerr << endl; } 
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
	if(idx > 0) cerr << ", "; else cerr << "Line(" << LINE_NUM << ") ";
	stringstream ss; ss << H;
	cerr << args[idx] << " = " << ss.str();
	debug_out(args, idx + 1, LINE_NUM, T...);
}
#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#endif
using namespace std;

char c[205];
int n,m;
int dp[1605][205][205];
int f[805];
int g[805],len;
int r[805],len2,fail;
int t[805],len3;

inline int fastpow(ll basic,int x)
{
	ll res=1;
	while(x)
	{
		if(x&1) (res*=basic)%=mod;
		(basic*=basic)%=mod;
		x>>=1;
	}
	return res;
}

vector<int> operator * (const vector<int> &a,const vector<int> &b)
{
	if(a.empty()) return a;
	if(b.empty()) return b;
	vector<int> c(a.size()+b.size()-1);
	for(int i=0;i<a.size();i++)
	{
		for(int j=0;j<b.size();j++)
		{
			c[i+j]=(1LL*a[i]*b[j]+c[i+j])%mod;
		}
	}
	return c;
}

vector<int> operator % (const vector<int> &a,const vector<int> &b)
{
	if(a.size()<b.size()) return a;
	vector<int> c=a;
	for(int i=c.size()-b.size();i>=0;i--)
	{
		int mut=c[i+b.size()-1];
		if(!mut) continue;
		for(int j=0;j<b.size();j++)
		{
			chadd(c[i+j],mod-1LL*b[j]*mut%mod);
		}
	}
	for(int i=b.size();i<c.size();i++) assert(c[i]==0);
	c.resize(b.size()-1);
	return c;
}

vector<int> fastpow(vector<int> Mod,int nn)
{
	vector<int> res={1};
	vector<int> bas={0,1};
	while(nn)
	{
		if(nn & 1) res=res*bas%Mod;
		bas=bas*bas%Mod;nn>>=1;
	}
	return res;
}

int main()
{
//	freopen("input.txt","r",stdin);
	scanf("%s",c);
	scanf("%d",&m);
	n=strlen(c);m+=n;
	dp[0][0][n-1]=1;
	int B=1500+(m&1);
	vector<int> T;
	for(int i=0;i<B;i+=2)
	{
		for(int j=0;j<=n;j++)
		{
			for(int k=n-1;k>=max(0,j-1);k--)
			{
				T.clear();
				if(j<n) T.emplace_back(c[j]);
				if(T.size()==0 || c[j]!=c[k]) T.emplace_back(c[k]);
				T.emplace_back('*');
				// cout<<T<<endl;
				if(!dp[i/2][j][k]) continue;
				for(auto &ch:T)
				// for(char ch='a';ch<='z';ch++)
				{
					int w=1LL*(ch=='*'?26-T.size()+1:1)*dp[i/2][j][k]%mod;
					int nj=(j+(j<=k && c[j]==ch));
					int nk=(k-(k>j && c[k]==ch && true));
					chadd(dp[i/2+1][nj][nk],w);
					if((m&1) && i+1>=n)
					{
						int nj=(j+(j<=k && c[j]==ch));
						int nk=(k-(k>j && c[k]==ch && false));
						if(nj==nk+1) chadd(f[(i+1-n)/2],w);
					}
					else if((!(m&1)) && i+2>=n)
					{
						int nj=(j+(j<=k && c[j]==ch));
						int nk=(k-(k>j && c[k]==ch));
						if(nj==nk+1) chadd(f[(i+2-n)/2],w);
					}
				}
			}
		}
	}
	int nn=(m-((m-n)&1)-n)/2;
	fail=-1;
	len=0;
	for(int i=0;i<=620;i++)
	{
		int w=0;
		for(int j=1;j<=len;j++)
		{
			w=(1LL*g[j-1]*f[i-j]+w)%mod;
		}
		if(w==f[i]) continue;
		int d=(f[i]-w+mod)%mod;
		int mut=0;
		if(fail==-1)
		{
			len3=i+1;
			for(int i=0;i<len3;i++) t[i]=0;
		}
		else
		{
			t[0]=1;
			len3=len2+1;
			for(int i=1;i<len3;i++) t[i]=mod-r[i-1];
			rotate(t,t+len3,t+len3+i-fail-1);
			memset(t,0,sizeof(int)*(i-fail-1));
			len3+=i-fail-1;
			for(int j=1;j<=len3;j++) chadd(mut,1LL*t[j-1]*f[i-j]%mod);
			mut=1LL*fastpow(mut,mod-2)*d%mod;
		}
		len2=len;
		fail=i;
		memcpy(r,g,sizeof(int)*len);
		chmax(len,len3);
		for(int j=0;j<len3;j++) g[j]=(1LL*mut*t[j]+g[j])%mod;
		// debug(len);
		// for(int j=0;j<len;j++) cout<<g[j]<<" \n"[j==len-1];
	}
	// for(int i=len;i<=700;i++)
	// {
	// 	int s=0;
	// 	for(int j=1;j<=len;j++) chadd(s,g[j-1]*f[i-j]%mod);
	// 	cout<<i<<' '<<f[i]<<' '<<s<<endl;
	// 	assert(f[i]==s);
	// }
	// cout<<(vector<int>({1,2,3,4}))%(vector<int>({1,mod-1,1}))<<endl;
	vector<int> mod;for(int j=0;j<len;j++) mod.emplace_back(g[j]);
	for(auto &x:mod) x=(::mod-x)%(::mod);
	reverse(all(mod));mod.emplace_back(1);
	// cout<<len<<endl;
	// cout<<mod<<endl;
	vector<int> dot=fastpow(mod,nn);
	int res=0;
	// cout<<dot<<endl;
	for(int i=0;i<dot.size();i++) res=(1LL*f[i]*dot[i]+res)%(::mod);
	cout<<res<<endl;
	return 0;
}