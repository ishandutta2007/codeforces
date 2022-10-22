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
#define Endl endl
#define mp make_pair
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
#define srand() mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l,r) uniform_int_distribution<int>(l,r)(rng)
typedef unsigned long long ull;
const int inf=1039074182;
using namespace std;
int a[200005];
int b[200005];
int eq[200005];
int n,k;

//be careful not percalc()
using namespace std;
const int N=200005*4+555;
const int LOGN=20;
int g=3;//g 998244353  
const int mod=998244353;

inline int mul(int a,int b){
	return int(1LL*a*b%mod);
}

inline int norm(int a)
{
	if(a>=mod) a-=mod;
	if(a<0) a+=mod;
	return a;
}

inline int ksm(int basic,int x)
{
	int res=1;
	while(x)
	{
		if(x&1)
		{
			res=mul(res,basic);
		}
		x>>=1;
		basic=mul(basic,basic);
	}
	return res;
}

inline int inv(int a)
{
	return ksm(a,mod-2);
}

vector<int> w[LOGN];
vector<int> rv[LOGN];

void precalc()
{
    int wb=ksm(g,(mod-1)/(1<<LOGN));
    for(int st=0;st<LOGN-1;st++)
	{
        w[st].assign(1<<st,1);
        int bw=ksm(wb,1<<(LOGN-st-1));
        int cw=1;
        for (int k=0;k<(1<<st);k++)
		{
            w[st][k]=cw;
            cw=mul(cw,bw);
        }
    }
    for(int st=0;st<LOGN;st++)
	{
        rv[st].assign(1 << st, 0);
        if(st == 0)
		{
            rv[st][0] = 0;
            continue;
        }
        int h=(1<<(st-1));
        for(int k=0;k<(1<<st);k++)
        {
        	rv[st][k] = (rv[st - 1][k & (h - 1)] << 1) | (k >= h);
		}
    }
}

inline void fft(int a[N],int n,bool inverse)
{
    int ln=0;
    while((1<<ln)<n) ln++;
    n=(1<<ln);
    for(int i=0;i<n;i++)
    {
        int ni=rv[ln][i];
        if(i<ni)
        {
        	swap(a[i], a[ni]);
		}
    }
    for(int st=0;(1<<st)<n;st++)
	{
        int len=(1<<st);
        for(int k=0;k<n;k+=(len<<1))
		{
            for(int pos=k;pos<k+len;pos++)
			{
                int l=a[pos];
                int r=mul(a[pos+len],w[st][pos-k]);
                a[pos]=norm(l+r);
                a[pos+len]=norm(l-r);
            }
        }
    }
    if(inverse)
	{
        int in=inv(n);
        for(int i=0;i<n;i++)
        {
        	a[i]=mul(a[i],in);
		}
        reverse(a+1,a+n);
    }
}

int aa[N],bb[N],cc[N];

inline vector<int> multiply(const vector<int> a,const vector<int> b)
{
	int ln=1;
	while(ln<(a.size()+b.size())) ln<<=1;
	for(int i=0;i<ln;i++)
	{
		aa[i]=(i<a.size()?a[i]:0);
	}
	for(int i=0;i<ln;i++)
	{
		bb[i]=(i<b.size()?b[i]:0);
	}
	fft(aa,ln,false);
	fft(bb,ln,false);
	for(int i=0;i<ln;i++)
	{
		cc[i]=mul(aa[i],bb[i]);
	}
	fft(cc,ln,true);
	vector<int> c(ln,0);
	for(int i=0;i<c.size();i++)
	{
		c[i]=cc[i];
	}
	while(c.size()>1 && c.back()==0) c.pop_back();
	return c;
}

namespace combinatorics
{
	int *fac;
	int *ifac;
	int __Tmod;
	inline int add(int a,int b)
	{
		return (a+b)%__Tmod;
	}
	inline int sub(int a,int b)
	{
		return (a-b+__Tmod)%__Tmod;
	}
	inline int mult(int a,int b)
	{
		return (1LL*a*b)%__Tmod;
	}
	inline int fastpow(int basic,int x)
	{
		int res=1;
		while(x)
		{
			if(x&1)	res=mult(res,basic);
			basic=mult(basic,basic);
			x>>=1;
		}
		return res;
	}
	inline int inv(int x)
	{
		return fastpow(x,__Tmod-2);
	}
	void init(int n,int tmod)
	{
		__Tmod=tmod;
		fac=new int[n+5];
		ifac=new int[n+5];
		fac[0]=1;
		for(int i=1;i<=n;i++)
		{
			fac[i]=mult(fac[i-1],i);
		}
		ifac[n]=inv(fac[n]);
		for(int i=n-1;i>=0;i--)
		{
			ifac[i]=mult(ifac[i+1],i+1);
		}
	}
	inline int C(int n,int m)
	{
		return mult(mult(fac[n],ifac[m]),ifac[n-m]);
	}
	inline int Cat(int x)
	{
		return mult(C(x*2,x),inv(x+1));
	}
};
using namespace combinatorics;

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
	}
	int ct=0;
	for(int i=0;i<n;i++)
	{
		int cur=a[i];
		int nxt=a[(i+1)%n];
		if(cur==nxt) eq[i]=k;
		else
		{
			eq[i]=k-2;
			b[i]=1;
			ct++;
		}
	}
	int cct=ct;
	init(0,998244353);
	precalc();
	vector <int> basic;
	vector <int> now;
	now.push_back(1);
	basic.push_back(1);
	basic.push_back((k-2)%998244353);
	basic.push_back(1);
	while(ct)
	{
		if(ct&1) now=multiply(now,basic);
		if(ct!=1) basic=multiply(basic,basic);
		ct>>=1;
	}
	int ff=fastpow(k,n-cct);
	int ans=0;
	for(int i=0;i<(int)now.size()/2;i++)
	{
		ans=add(ans,now[i]);
//		cout<<now[i]<<' ';
	}
	ans=mult(ans,ff);
	cout<<ans<<endl;
	return 0;
}