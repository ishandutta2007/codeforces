#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<string>
#include<bitset>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;

#define X first
#define Y second

const int MaxN=400010;

int n;
int d[MaxN],w[MaxN];

int a[MaxN];

void add(int x,int p)
{
	for (;x<MaxN;x+=x&-x)
		a[x]+=p;
}

int get(int x)
{
	int p=0;
	for (;x;x-=x&-x)
		p+=a[x];
	return p;
}

int get(int x,int y)
{
	return get(y)-get(x-1);
}

int main()
{
	cin>>n;
	for (int i=1;i<=n;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if (x>y) swap(x,y);
		d[x]=y;
		d[y]=x+2*n;
		add(y,1);
		add(x+2*n,1);
		add(y+2*n,1);
	}
	for (int i=1;i<=2*n;++i)
	{
		add(d[i],-1);
		w[i]=get(i+1,d[i]-1);
	}
	ll ans=0;
	for (int i=1;i<=2*n;++i)
	{
		int j=d[i];
		if (j>2*n) j-=2*n;
		ans+=(ll)w[i]*w[j];
		ans+=(ll)w[j]*(n-w[i]-w[j]-1);
	}
	cout<<(ll)n*(n-1)*(n-2)/6-ans/2<<endl;
	return 0;
}