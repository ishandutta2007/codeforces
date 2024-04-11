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
using namespace std;
#include <bits/stdc++.h>
#include <chrono>
#include <time.h>
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l,r) uniform_int_distribution<int>(l,r)(rng)

struct StringHash
{
	template <typename T>
	inline bool checkPrime(T x)
	{
		for(T i=2;i*i<=x;i++)
		{
			if(x%i==0) return false;
		}
		return true;
	}
	inline int nextPrime(int x)
	{
		for(int i=x;;i++)
		{
			if(checkPrime(i)) return i;
		}
	}
	int *hh;
	int n;
	int prime;
	int mod;
	int *e;
	inline void init(int _n,int _prime=-1,int _mod=-1)
	{
		n=_n;
		if(_prime==-1) prime=nextPrime(rand(1e8,3e8));else prime=_prime;
		if(_mod==-1) mod=nextPrime(rand(8e8,1e9));else mod=_mod;
		hh=new int[n+5];
		e=new int[n+5];
		e[0]=1;
		for(int i=1;i<n;i++)
		{
			e[i]=1LL*e[i-1]*prime%mod;
		}
	}
	inline void feedString(char c[])
	{
		n=strlen(c);
		hh[0]=c[0];
		for(int i=1;i<n;i++)
		{
			hh[i]=(1LL*hh[i-1]*prime+c[i])%mod;
		}
	}
	inline int getHash(int pos,int len)
	{
		assert(pos+len<=n);
		return (hh[pos+len-1]-1LL*(pos?hh[pos-1]:0)*e[len]%mod+mod)%mod;
	}
	inline bool same(int x,int y,int len)
	{
		if(x+len>n) return false;
		if(y+len>n) return false;
		return (getHash(x,len)==getHash(y,len));
	}
};

template <int P>
struct HashValue
{
	int hashValue[P];
	bool operator == (HashValue x)
	{
		for(int i=0;i<P;i++)
		{
			if(hashValue[i]!=x.hashValue[i]) return false;
		}
		return true;
	}
};

template <int P>
struct MultipleStringHash
{
	StringHash h[P];
	int n;
	inline void init(int _n)
	{
		n=_n;
		for(int i=0;i<P;i++)
		{
			h[i].init(n);
		}
	}
	inline void feedString(char c[])
	{
		for(int i=0;i<P;i++)
		{
			h[i].feedString(c);
		}
	}
	inline HashValue <P> getHash(int x,int len)
	{
		HashValue <P> g;
		for(int i=0;i<P;i++)
		{
			g[i]=h[i].getHash(x,len);
		}
		return g;
	}
	inline bool same(int x,int y,int len)
	{
		return (getHash(x,len)==getHash(y,len));
	}
};

template <int P>
struct PalindromeHash
{
	StringHash h[P];
	StringHash rh[P];
	int n;
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<P;i++)
		{
			h[i].init(n);
		}
		for(int i=0;i<P;i++)
		{
			rh[i].init(n,h[i].prime,h[i].mod);
		}
	}
	void feedString(char c[])
	{
		n=strlen(c);
		for(int i=0;i<P;i++)
		{
			h[i].feedString(c);
		}
		reverse(c,c+n);
		for(int i=0;i<P;i++)
		{
			rh[i].feedString(c);
		}
		reverse(c,c+n);
	}
	bool checkOdd(int x,int len)
	{
		for(int i=0;i<P;i++)
		{
			if(h[i].getHash(x,len)!=rh[i].getHash(n-x-1,len)) return false;
		}
		return true;
	}
	inline int maxOdd(int x)
	{
		int l=1,r=min(x+1,n-x),mid,res=1;
		while(l<=r)
		{
			mid=l+r>>1;
			if(checkOdd(x,mid))
			{
				res=mid;
				l=mid+1;
			}
			else
			{
				r=mid-1;
			}
		}
		return res;
	}
};
using namespace std;
template <typename T>
ostream & operator << (ostream& cout,vector<T> vec)
{
	cout<<"{";
	for(int i=0;i<vec.size();i++)
	{
		cout<<vec[i];
		if(i!=(int)vec.size()-1) cout<<',';
	}
	cout<<"}";
	return cout;
}

template <typename T1,typename T2>
ostream & operator << (ostream & cout,pair<T1,T2> p)
{
	cout<<"("<<p.first<<','<<p.second<<")";
	return cout;
}

template <typename T>
T operator * (vector <T> v1,vector <T> v2)
{
	assert(v1.size()==v2.size());
	int n=v1.size();
	T res=0;
	for(int i=0;i<n;i++)
	{
		res+=v1[i]*v2[i];
	}
	return res;
}

template <typename T1,typename T2>
pair<T1,T2> operator - (pair<T1,T2> x)
{
	return make_pair(-x.first,-x.second);
}
#define Endl endl
#define mp make_pair
#define ll long long 
#define ull unsinged long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
#define srand() mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l,r) uniform_int_distribution<int>(l,r)(rng)
template <typename T1,typename T2> inline void chmin(T1 &x,T2 b) {if(b<x) x=b;}
template <typename T1,typename T2> inline void chmax(T1 &x,T2 b) {if(b>x) x=b;}
const int inf=1039074182;
const int P=3;
const int mod[P]={1000000007,1000000009,1000000021};
const int prime[P]={237498241,237498263,237498269};
const ll llinf=1LL*inf*inf;
using namespace std;
double timeCost=0;
char c[2000005];
char rc[2000005];
int a[2000005];
char tmp[2000005];
int ps[2000005];
int ss[2000005];
int n;
int psmatch;
PalindromeHash <1> ph;

pair<int,pii> solveOdd()
{
	pair<int,pii> res=mp(ps[psmatch-1]+ss[n-psmatch],mp(psmatch-1,n-psmatch));
	int pre,suf;
	for(int i=psmatch;i<n-psmatch;i++)
	{
		int t=ph.maxOdd(i);
		chmin(t,i-(psmatch-1));
		chmin(t,n-psmatch-i);
		if(i-t+1<=psmatch)
		{
			int posl=i+t-1;
			int posr=n-psmatch;
			chmax(res,mp(ps[posl]+ss[posr],mp(posl,posr)));
		}
		if(i+t-1>=n-1-psmatch)
		{
			int posl=psmatch-1;
			int posr=i-t+1;
			chmax(res,mp(ps[posl]+ss[posr],mp(posl,posr)));
		}
//		cout<<i<<' '<<res<<endl;
	}
	chmin(res,mp(ps[n-1],mp(1,2)));
	return res;
}

inline int addch(char c[])
{
	int k=0;
	tmp[k++]='#';
	for(int i=0;i<n;i++)
	{
		tmp[k++]=c[i];
		tmp[k++]='#';
	}
	for(int i=0;i<k;i++)
	{
		c[i]=tmp[i];
	}
	c[k]='\0';
	return k;
}

void solve()
{
//	memset(c,0,sizeof(c));
//	memset(tmp,0,sizeof(tmp));
	scanf("%s",c);
	n=strlen(c);
	n=addch(c);
	ph.feedString(c);
	pair<int,pii> res;
	for(int i=0;i<n;i++)
	{
		ps[i]=(i?ps[i-1]:0)+(c[i]!='#');
	}
	for(int i=n-1;i>=0;i--)
	{
		ss[i]=(i==n-1?0:ss[i+1])+(c[i]!='#');
	}
	psmatch=0;
	for(int i=0;i<n;i++)
	{
		if(c[i]!=c[n-1-i]) break;
		if(i>=n-1-i) break;
		psmatch++;
	}
	res=solveOdd();
	for(int i=0;i<=res.second.first;i++)
	{
		if(c[i]!='#') putchar(c[i]);
	}
	for(int i=res.second.second;i<n;i++)
	{
		if(c[i]!='#') putchar(c[i]);
	}
	puts("");
}

int main()
{
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	ph.init(2e6);
	int T;
	cin>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}