#pragma comment(linker,"/STACK:128000000")
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
//#define x first
//#define y second

const double PI=acos(-1.0);
template<class T> T SQR(const T &a){return a*a;}

pii A[100100];
int V[100100];

bool cmp(const pii &a,const pii &b)
{
	if (a.first!=b.first)
		return a.first<b.first;
	return V[a.second]<V[b.second];
}

bool can(double t,int n,int k)
{
	ll curr=k;
	for (int i=n-1;i>=0;i--)
		if (curr>0 && curr<=t*double(V[A[i].second]))
			curr--;
	return curr==0;
}

int main()
{
	int n,k,h;
	cin>>n>>k>>h;
	rep(i,0,n)
	{
		scanf("%d",&A[i].first);
		A[i].second=i;
	}
	rep(i,0,n)
		scanf("%d",V+i);
	sort(A,A+n,cmp);
	int Ans[100100];
	double Eps=1e-9;
	double l=0;
	double r=k+Eps;
	double c=(l+r)/2.0;
	double res=c;
	while (l<c && c<r)
	{
		if (can(c,n,k))
		{
			res=c;
			r=c;
		}
		else
			l=c;
		c=(l+r)/2.0;
	}
	ll curr=1;
	rep(i,0,n)
		if (curr<=res*double(V[A[i].second]))
		{
			Ans[curr-1]=A[i].second;
			curr++;
		}
	rep(i,0,k)
		printf("%d ",Ans[i]+1);
	puts("");
	return 0;
}

/*
ab
adb
*/