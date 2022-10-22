//Original Code:
//#include <self/utility>
//#include <self/ntt>
//using namespace std;
//int n,m,k;
//char a[200005];
//char b[200005];
//int s[200005];
//
//bitset <200000> solve(char ch)
//{
//	memset(s,0,sizeof(s));
//	for(int i=0;i<n;i++)
//	{
//		if(a[i]!=ch) continue;
//		s[max(0,i-k)]++;
//		s[min(n,i+k+1)]--;
//	}
//	for(int i=1;i<n;i++)
//	{
//		s[i]+=s[i-1];
//	}
//	for(int i=0;i<n;i++)
//	{
//		s[i]=!s[i];
//	}
//	vector <int> v1;
//	for(int i=n-1;i>=0;i--)
//	{
//		v1.push_back(s[i]);
//	}
//	vector <int> v2;
//	for(int i=0;i<m;i++)
//	{
//		if(b[i]==ch) v2.push_back(1);else v2.push_back(0);
//	}
//	vector <int> v3=NTT::multiply(v1,v2);
//	while((int)v3.size()<n) v3.push_back(0);
//	reverse(v3.begin(),v3.begin()+n);
//	bitset <200000> bit;
//	bit.reset();
//	for(int i=0;i<=n-m;i++)
//	{
//		bit[i]=!v3[i];
//	}
//	return bit;
//}
//
//int main()
//{
////	freopen("input.txt","r",stdin);
//	NTT::init();
//	scanf("%d%d%d",&n,&m,&k);
//	scanf("%s",a);
//	scanf("%s",b);
//	cout<<(solve('A') & solve('C') & solve('G') & solve('T')).count()<<endl;
//	return 0;
//}

//substituted with C++ Inliner
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
#define mp make_pair
#define ll long long 
#define ull unsigned long long
#define pii pair<int,int>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define quickcin ios_base::sync_with_stdio(false);
const int mod=998244353;
const int gmod=2;
const int inf=1039074182;
const ll llinf=1LL*inf*inf;
template <typename T1,typename T2> inline void chmin(T1 &x,T2 b) {if(b<x) x=b;}
template <typename T1,typename T2> inline void chmax(T1 &x,T2 b) {if(b>x) x=b;}
inline void chadd(int &x,int b) {x+=b-mod;x+=(x>>31 & mod);}
template <typename T1,typename T2> inline void chadd(T1 &x,T2 b) {x+=b;if(x>=mod) x-=mod;}
template <typename T1,typename T2> inline void chmul(T1 &x,T2 b) {x=1LL*x*b%mod;}
template <typename T1,typename T2> inline void chmod(T1 &x,T2 b) {x%=b,x+=b;if(x>=b) x-=b;}
template <typename T> inline T mabs(T x) {return (x<0?-x:x);}
#endif
using namespace std;
template <int mod>
struct ModInt
{
	int x;
	ModInt(){x=0;}
	ModInt(int _x){x=_x%mod;if(x<0) x+=mod;}
	ModInt <mod>& operator ++()// prefix
	{
		++x;
		if(x==mod) x=0;
		return *this;
	}
};

template <int mod>
bool operator < (ModInt <mod> a,ModInt <mod> b)
{
	return a.x<b.x;
}

template <int mod>
bool operator > (ModInt <mod> a,ModInt <mod> b)
{
	return b.x<a.x;
}

template <int mod>
bool operator == (ModInt <mod> a,ModInt <mod> b)
{
	return a.x==b.x;
}

template <int mod>
bool operator == (ModInt <mod> a,int x)
{
	return (a.x==x);
}

template <int mod>
bool operator <= (ModInt <mod> a,ModInt <mod> b)
{
	return a.x<=b.x;
}

template <int mod>
bool operator >= (ModInt <mod> a,ModInt <mod> b)
{
	return b.x<=a.x;
}

template <int mod>
ModInt <mod> operator + (ModInt <mod> a,int b)
{
	a.x+=b;
	if(a.x>=mod) a.x-=mod;
	return a;
}

template <int mod>
ModInt <mod> operator + (ModInt <mod> a,ModInt <mod> b)
{
	int tmp=a.x+b.x;
	if(tmp>=mod) tmp-=mod;
	return tmp;
}

template <int mod>
ModInt <mod> operator - (ModInt <mod> a,ModInt <mod> b)
{
	int tmp=a.x-b.x;
	if(tmp<0) tmp+=mod;
	return tmp;
}

template <int mod>
ModInt <mod> operator - (ModInt <mod> a,int b)
{
	return a-(ModInt <mod> )b;
}

template <int mod>
ModInt <mod> operator * (ModInt <mod> a,ModInt <mod> b)
{
	return 1LL*a.x*b.x%mod;
}

template <int mod>
void operator *= (ModInt <mod> &a,ModInt <mod> b)
{
	a=a*b;
}

template <int mod>
void operator += (ModInt <mod> &a,ModInt <mod> b)
{
	a.x+=b.x;
	if(a.x>=mod) a.x-=mod;
}

template <int mod>
inline ModInt <mod> inv(ModInt <mod> x)
{
	int m=mod-2;
	ModInt <mod> basic=x;
	x=1;
	while(m)
	{
		if(m&1) x*=basic;
		m>>=1;
		basic*=basic;
	}
	return x;
}

template <int mod>
ModInt <mod> operator / (ModInt <mod> a,ModInt <mod> b)
{
	return a*inv(b);
}

template <int mod>
ModInt <mod> operator / (ModInt <mod> a,int b)
{
	return a*inv((ModInt <mod>)b);
}

template <int mod>
void operator /= (ModInt <mod> &a,ModInt <mod> b)
{
	a=a/b;
}

template <int mod>
istream & operator >> (istream &cin,ModInt <mod> &x)
{
	cin>>x.x;
	return cin;
}

template <int mod>
ostream & operator << (ostream &cout,ModInt <mod> x)
{
	cout<<x.x;
	return cout;
}
namespace NTT
{
	const int mod=998244353;
	using ModInt=ModInt <mod>;
	using Vector=vector <ModInt>;
	const ModInt g=3;
	const int LogN=19;
	const int MaxN=(1<<LogN);
	ModInt UnitRoot;
	int inv[MaxN];
	ModInt w[MaxN+1];
	inline ModInt fastpow(ModInt basic,int x)
	{
		ModInt res=1;
		while(x)
		{
			if(x&1)	res*=basic;
			basic*=basic;
			x>>=1;
		}
		return res;
	}
	inline void init()
	{
		inv[0]=0;
		for(int i=1;i<MaxN;i++)
		{
			inv[i]=(inv[(i>>1)]>>1) | ((i&1)<<(LogN-1));
		}
		UnitRoot=fastpow(g,(mod-1)>>LogN);
		w[0]=1;
		for(int i=1;i<=MaxN;i++)
		{
			w[i]=w[i-1]*UnitRoot;
		}
	}
	ModInt v[MaxN];
	ModInt buf[MaxN];
	inline ModInt zeta(int n,int k,int rev)
	{
		return (rev==0?w[MaxN/n*k]:w[MaxN/n*(n-k)]);
	}
	Vector ntt(Vector a,int rev)
	{
		for(int i=0;i<MaxN;i++)
		{
			v[i]=(inv[i]>=(int)a.size()?0:a[inv[i]]);
		}
		for(int m=2;m<=MaxN;m<<=1)
		{
			for(int b=0;b<MaxN;b+=m)
			{
				for(int i=0;i<(m>>1);i++)
				{
					buf[b+i]=v[b+i]+v[b+i+(m>>1)]*zeta(m,i,rev);
//					assert((v[b+i]-v[b+i+(m>>1)]*zeta(m,i,rev))==(v[b+i]+v[b+i+(m>>1)]*zeta(m,i+(m>>1),rev)));
					buf[b+i+(m>>1)]=v[b+i]-v[b+i+(m>>1)]*zeta(m,i,rev);
				}
			}
			for(int j=0;j<MaxN;j++)
			{
				v[j]=buf[j];
			}
		}
		Vector b(MaxN);
		for(int i=0;i<MaxN;i++)
		{
			b[i]=v[i];
		}
		return b;
	}
	Vector multiply(Vector a,Vector b)
	{
		a=ntt(a,0);
		b=ntt(b,0);
		for(int i=0;i<MaxN;i++)
		{
			a[i]=a[i]*b[i];
		}
		a=ntt(a,1);
		while(a.back()==0) a.pop_back();
		for(int i=0;i<MaxN;i++)
		{
			a[i]/=(ModInt)MaxN;
		}
		return a;
	}
	vector <int> multiply(vector <int> &a,vector <int> &b)
	{
		Vector ta(a.size()),tb(b.size());
		for(int i=0;i<(int)a.size();i++)
		{
			ta[i]=a[i];
		}
		for(int i=0;i<(int)b.size();i++)
		{
			tb[i]=b[i];
		}
//		cout<<a<<' '<<b<<endl;
		ta=multiply(ta,tb);
//		cout<<ta<<endl;
		vector <int> c(ta.size());
		for(int i=0;i<(int)ta.size();i++)
		{
			c[i]=ta[i].x;
		}
		while(!c.empty() && c.back()==0) c.pop_back();
		return c;
	}
};
using namespace std;
int n,m,k;
char a[200005];
char b[200005];
int s[200005];

bitset <200000> solve(char ch)
{
	memset(s,0,sizeof(s));
	for(int i=0;i<n;i++)
	{
		if(a[i]!=ch) continue;
		s[max(0,i-k)]++;
		s[min(n,i+k+1)]--;
	}
	for(int i=1;i<n;i++)
	{
		s[i]+=s[i-1];
	}
	for(int i=0;i<n;i++)
	{
		s[i]=!s[i];
	}
	vector <int> v1;
	for(int i=n-1;i>=0;i--)
	{
		v1.push_back(s[i]);
	}
	vector <int> v2;
	for(int i=0;i<m;i++)
	{
		if(b[i]==ch) v2.push_back(1);else v2.push_back(0);
	}
	vector <int> v3=NTT::multiply(v1,v2);
	while((int)v3.size()<n) v3.push_back(0);
	reverse(v3.begin(),v3.begin()+n);
	bitset <200000> bit;
	bit.reset();
	for(int i=0;i<=n-m;i++)
	{
		bit[i]=!v3[i];
	}
	return bit;
}

int main()
{
//	freopen("input.txt","r",stdin);
	NTT::init();
	scanf("%d%d%d",&n,&m,&k);
	scanf("%s",a);
	scanf("%s",b);
	cout<<(solve('A') & solve('C') & solve('G') & solve('T')).count()<<endl;
	return 0;
}