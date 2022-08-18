#include <iostream>
#include <fstream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cmath>
#include<vector>
#include<ctime>
#include<memory.h>
#include<algorithm>
#define sqr(x) ((x)*(x))
#define sqrt(x) sqrt((x)*1.)
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))  
#define abs(x) ((x)>0?(x):-(x))
#define getar(m,n) for(int _=0;_<n;++_) cin>>(m)[_];
#define FOR(i,a,b) for(int i=(a),_b(b);i<_b;++i)
#define FORD(i,a,b) for(int i=(a),_b(b);i>=_b;--i)
#define REP(i,n) FOR(i,0,n)
#define CL(x) memset(x, 0, sizeof(x))
#define SINF(x) memset(x, 0x3F, sizeof(x));
#define SVAL(x, y) memset(x, y, sizeof(x))
#define CP(t, f) memcpy(t, f, sizeof(f));
#define CPS(t, f, s) memcpy(t, f, s*sizeof(f[0]));
#define random(x) (((rand()*25)+rand())%(x))
#define pi 3.1415926535897932
#define y1 stupid_cmath
#define y0 qstupid_cmath_make_me_cry
#define tm stupid_ctime
#define pb push_back
#define mp make_pair
#include<map>
#include<set>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#pragma comment(linker,"/STACK:256000000")
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned short us;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef pair<int,int> pii;
typedef pair<int, bool> pib;

#define maxll 0x7fffffffffffffffLL
#define mod 1000000007
#define INF 1000000000

int main3()
{
	int n,t;
	cin>>n>>t;
	int a[1000][1000];
	int m=n;
	for (int j=1;j<=m;j++)
		a[1][j]=0;
	a[1][m+1]=1;
	for (int i=2;i<=m+1;i++)
	{
		for (int j=1;j<=m+1;j++)
		{
			if (j==1)
			{
				a[i][j]=a[i-1][j+1];
			}
			else
			{
				if (j==m+1)
				{
					a[i][j]=a[i-1][j-1];
				}
				else
				{
					a[i][j]=a[i-1][j-1] ^ a[i-1][j+1];
				}
			}
		}
	}
int s=0;

	for (int i=1;i<=m+1;i++)
	{
		int k=0;
		for (int j=1;j<=m+1;j++)
		{
			k+=a[i][j];	
		}
		if (k==t)
		{
			s++;
		}

	}
	cout<<s<<endl;
	return 0;
}
int main()
{
	ll b[50][50];
	for (int i=0;i<50;i++)
	{
		b[0][i]=0;
		b[i][0]=1;
	}
	for (int i=1;i<50;i++)
	{
		for (int j=1;j<50;j++)
		{
			b[i][j]=b[i-1][j]+b[i-1][j-1];
		}
	}
	ll n,t;
		cin>>n>>t;
		
		ll k=0;
		ll s=0;
		if (t==1)
			s--;
		while (t%2==0)
		{
			t/=2;
			k++;
		}
		if (t>1)
		{
			cout<<0<<endl;
			return 0;
		}
		t=k;
		ll p=0;
		ll c=0;
		k=1;
		n++;
		while (k*2<=n)
		{
			k*=2;
			s+=b[p][t];
			p++;
		}
		n-=k-1;
		while (n>0)
		{
			k=1;
			p=0;
			while (k*2<=n)
			{
				k*=2;
				p++;
			}
			n-=k;
			if (t-c>=0)
				s+=b[p][t-c];
			else
			{
				;
			}
			c++;
		}
		cout<<s<<endl;
	
	return 0;
}