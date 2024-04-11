#pragma comment(linker,"/STACK:32000000")
#include <cstdio>
#include <memory>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <complex>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <fstream>
#include <functional>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef unsigned short int usi;
typedef long double ld;
typedef pair<int,int> pii;
#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(x) (x).begin(),(x).end()

const double PI=acos(-1.0);

template<class T> inline T SQR(T a){return a*a;}

int base=1e9;
struct dig
{
	int A[9];
	int len;
	dig(int a=0)
	{
		A[0]=a;
		len=1;
	}
	dig(ll a)
	{
		A[0]=a%base;
		A[1]=a/base;
		if (A[1]) len=2;
		else len=1;
	}
};

dig operator+(const dig &a,const dig &b)
{
	dig res;
	res.len=a.len;
	if (res.len<b.len) res.len=b.len;
	++res.len;
	ll buff=0;
	rep(i,0,res.len)
	{
		if (i<a.len) buff+=a.A[i];
		if (i<b.len) buff+=b.A[i];
		res.A[i]=buff%base;
		buff/=base;
	}
	while (res.len>1 && res.A[res.len-1]==0) res.len--;
	return res;
}

dig operator*(const dig &a,const dig &b)
{
	dig res;
	res.len=a.len+b.len;
	memset(res.A,0,sizeof(ll)*res.len);
	rep(i,0,a.len)
		rep(j,0,b.len)
		{
			ll curr=(res.A[i+j]+ll(a.A[i])*b.A[j]);
			res.A[i+j]=curr%base;
			res.A[i+j+1]+=curr/base;
		}
	while (res.len>1 && res.A[res.len-1]==0) res.len--;
	return res;
}

dig operator-(const dig &a,const dig &b)
{
	dig res;
	res.len=a.len;
	int care=0;
	rep(i,0,a.len)
	{
		int curr=a.A[i]-care;
		if (i<b.len) curr-=b.A[i];
		care=1;
		if (curr<0)
			curr+=base;
		else
			care=0;
		res.A[i]=curr;
	}
	while (res.len>1 && res.A[res.len-1]==0) res.len--;
	return res;
}

bool operator<=(const dig &a,const dig &b)
{
	if (a.len!=b.len) return a.len<b.len;
	for (int i=a.len-1;i>=0;i--)
		if (a.A[i]!=b.A[i])
			return a.A[i]<b.A[i];
	return true;
}

ll Mas[2000000];
int Cnt=0;

void rec(char step,ll val)
{
	if (step>=18) return;
	Mas[Cnt++]=val;
	rec(step+1,val*10+4);
	rec(step+1,val*10+7);
}

ll Left[100001];
ll Right[100001];
dig Sum[100001];

ll INF=1000000000000000000LL;
int n;
ll k;
ll dist=INF;

bool can(int K)
{
	dig sumr=0;
	int cntl=0;
	int cntr=0;
	dig curr;
	rep(i,0,Cnt-K+1)
	{
		ll a=Mas[i];
		ll b=Mas[i+K-1];
		if (b-a+1>dist) continue;
		while (cntr<n && Right[cntr]<=b)
		{
			if (cntr!=0)
				sumr=sumr+dig(Right[cntr]-Right[cntr-1])*cntr;
			cntr++;
		}
		curr=sumr;
		if (cntr>0)
			curr=curr+dig(b-Right[cntr-1])*cntr;
		while (cntl<n && Left[cntl]<=a)
			cntl++;
		if (cntl<n)
		{
			curr=curr+Sum[cntl]-dig(n-cntl)*a;
		}
		if (curr<=k)
			return true;
	}
	return false;
}

int main()
{
	cin>>n>>k;
	rec(0,4);
	rec(0,7);
	sort(Mas,Mas+Cnt);
	rep(i,0,n)
	{
		scanf("%I64d%I64d",Left+i,Right+i);
		if (Right[i]-Left[i]+1<dist)
			dist=Right[i]-Left[i]+1;
	}
	sort(Left,Left+n);
	sort(Right,Right+n);
	Sum[n-1]=Left[n-1];

	for (int i=n-2;i>=0;i--)
			Sum[i]=Sum[i+1]+Left[i];
	int l=1,r=1000000;
	int res=0;
	while (l<=r)
	{
		int c=(l+r)>>1;
		if (can(c))
		{
			res=c;
			l=c+1;
		}
		else
			r=c-1;
	}
	printf("%d\n",res);
	return 0;
}
/*
2 1
5 6
7 8

1 0
5 6

1 1
3 43

1 0
3 4

2 0
1 1000000000000000000
4 4
*/