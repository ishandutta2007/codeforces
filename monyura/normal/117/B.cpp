#pragma comment(linker,"/STACK:64000000")
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
typedef long double ld;
typedef pair<int,int> pii;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(x) (x).begin(),(x).end()

const double PI=acos(-1.0);

template<class T> inline T SQR(T a){return a*a;}

int base=1e9;
struct dig
{
	int A[3];
	int len;
	dig(int a=0)
	{
		A[0]=a;
		len=1;
	}
};

dig divide(const dig &a,ll b,ll &mod)
{
	dig res;
	res.len=a.len;
	ll curr=0;
	for (int i=a.len-1;i>=0;i--)
	{
		curr=curr*base+a.A[i];
		res.A[i]=curr/b;
		curr-=res.A[i]*ll(b);
	}
	mod=curr;
	while (res.len>1 && res.A[res.len-1]==0) res.len--;
	return res;
}

dig operator+(const dig &a,const dig &b)
{
	dig res;
	res.len=max(a.len,b.len)+1;
	int buff=0;
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
	rep(i,0,res.len)
		res.A[i]=0;
	rep(i,0,a.len)
		rep(j,0,b.len)
		{
			ll curr=(res.A[i+j]+a.A[i]*ll(b.A[j]));
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
	rep(i,0,res.len)
	{
		int otn=a.A[i]-care;
		if (i<b.len) otn-=b.A[i];
		if (otn<0)
		{
			care=1;
			otn+=base;
		}
		else 
			care=0;
		res.A[i]=otn;
	}
	while (res.len>1 && res.A[res.len-1]==0) res.len--;
	return res;
}

int main()
{
	int a,b,mod;
	cin>>a>>b>>mod;
	dig da;
	int ans=-1;
	rep(i,0,min(mod,a)+1)
	{
		da.len=2;
		da.A[0]=0;
		da.A[1]=i;
		ll res;
		divide(da,mod,res);
		if (res!=0 && -res+mod>b)
		{
			ans=i;
			break;
		}
	}
	if (ans==-1)
		printf("2\n");
	else
		printf("1 %.9d\n",ans);

	return 0;
}


/*
5 5
1 5 4
1 3 1
1 3 4
3 1 5
4 2 5

5 5
3 1 5
4 2 5

5 4
1 2 6

*/