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
#include<complex>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;
typedef complex<ld> cd;

#define X real()
#define Y imag()

const int n=1<<21;
const int MaxN=n;
const cd I(0,1);
const ld pi=acos(-1);

int u[n];
cd a[n],w[n],v[n];

void fft(cd *a,int s,int t)
{
	if (n>>t==1) return;
	fft(a,s,t+1);
	fft(a,s+(1<<t),t+1);
	for (int i=0;i<n>>(t+1);++i)
	{
		int p=s+(i<<(t+1));
		cd d=w[i<<t]*a[p+(1<<t)];
		v[i]=a[p]+d;
		v[i+(n>>(t+1))]=a[p]-d;
	}
	for (int i=0;i<n>>t;++i)
		a[s+(i<<t)]=v[i];
}

int main()
{
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;++i)
	{
		int x;
		scanf("%d",&x);
		a[x]=u[x]=1;
	}
	for (int i=0;i<MaxN;++i)
		w[i]=exp(2*pi*i/MaxN*I);
	fft(a,0,0);
	for (int i=0;i<MaxN;++i)
	{
		a[i]*=a[i];
		w[i]=exp(-2*pi*i/MaxN*I);
	}
	fft(a,0,0);
	for (int i=0;i<MaxN;++i)
		a[i]/=MaxN;
	for (int i=1;i<=m;++i)
		if (fabs(a[i].X)>.5&&!u[i])
		{
			puts("NO");
			return 0;
		}
	vector<int> v;
	for (int i=1;i<=m;++i)
		if (fabs(a[i].X)<.5&&u[i])
			v.push_back(i);
	puts("YES");
	cout<<v.size()<<endl;
	for (int i=0;i<v.size();++i)
		printf("%d ",v[i]);
	return 0;
}