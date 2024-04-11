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
typedef unsigned char uc;
typedef short int si;
typedef unsigned short int usi;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(x) (x).begin(),(x).end()
#define movmax(A,B) {if(A<(B)) A=(B);}
#define movmin(A,B) {if(A>(B)) A=(B);}
#define x first
#define y second

const double PI=acos(-1.0);
template<class T> T SQR(const T &a){return a*a;}

ll mult(const pii &a,const pii &b)
{
	return ll(a.x)*b.y-ll(a.y)*b.x;
	
}

pii operator-(const pii &a,const pii &b)
{
	return pii(a.x-b.x,a.y-b.y);
}

pii St;

pii A[100100];
pii C[100100];
int bins1(int l,int r,const pii &p)
{
	pii c=p-St;
	int res=0;
	while (l<=r)
	{
		int mid=(l+r)>>1;
		if (mult(C[mid],c)<=0)
		{
			res=mid;
			l=mid+1;
		}
		else
			r=mid-1;
	}
	return res;
}

int bins2(int l,int r,const pii &p)
{
	pii c=p-St;
	int res=0;
	while (l<=r)
	{
		int mid=(l+r)>>1;
		if (mult(C[mid],c)>=0)
		{
			res=mid;
			r=mid-1;
		}
		else
			l=mid+1;
	}
	return res;
}

double dist(const pii&a,const pii&b)
{
	return sqrt(0.0+SQR(ll(a.x-b.x))+SQR(ll(a.y-b.y)));
}


int main()
{
	int n;
	cin>>n;
	
	rep(i,0,n)
		scanf("%d%d",&A[i].x,&A[i].y);
	rep(i,0,n)
		C[i]=A[i]-A[0];
	St=A[0];
	int m;
	cin>>m;
	pii B[20100];
	rep(i,0,m)
		scanf("%d%d",&B[i].x,&B[i].y);
	bool ok=1;
	double Eps=1e-6;
	rep(i,0,m)
	{
		if (B[i]==St) ok=0;
		if (mult(C[1],B[i]-St)>=0) ok=0;
		if (mult(C[n-1],B[i]-St)<=0) ok=0;
		int l=bins1(1,n-1,B[i]);
		int r=bins2(1,n-1,B[i]);
		if (l>r) ok=0;
		else if (l==r)
		{
			if (B[i]==A[l] || dist(B[i],A[0])+dist(B[i],A[l])>dist(A[0],A[l])+Eps)
				ok=0;
		}
		else if (mult(A[r]-A[l],B[i]-A[l])>=0) ok=0;
	}
	puts(ok?"YES":"NO");
	return 0;
}

/*
4
0 0
0 2
2 2
2 0
1
-1 -1
*/