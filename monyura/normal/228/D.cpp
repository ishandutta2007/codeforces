#ifdef _MONYURA_
#pragma comment(linker,"/STACK:256000000")
#endif

#include <iostream>
#include <cstdio>
#include <memory>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <stack>
#include <complex>
#include <cmath>
#include <queue>
#include <ctime>


using namespace std;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(c) (c).begin(), (c).end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll Buff[5][10][200100]={0};
int Cnt[5][10];

ll *D;
int A[120000];

void buildD(int v,int l,int r)
{
	if (l==r)
	{
		D[v]=A[l];
		return;
	}
	int c=(l+r)>>1;
	buildD(2*v,l,c);
	buildD(2*v+1,c+1,r);
	D[v]=D[2*v]+D[2*v+1];
}

ll getSum(int v,int l,int r,int ql,int qr)
{
	if (l==ql && r==qr)
	{
		return D[v];
	}
	int c=(l+r)>>1;
	if (qr<=c)
		return getSum(2*v,l,c,ql,qr);
	if (ql>c)
		return getSum(2*v+1,c+1,r,ql,qr);
	return getSum(2*v,l,c,ql,c) + getSum(2*v+1,c+1,r,c+1,qr);
}

void update(int v,int l,int r,int pos,int val)
{
	if (l==r)
	{
		D[v]=val;
		return;
	}
	int c=(l+r)>>1;
	if (pos<=c)
		update(2*v,l,c,pos,val);
	else
		update(2*v+1,c+1,r,pos,val);
	D[v]=D[2*v]+D[2*v+1];
}

void run()
{
	int B[100100];
	int n;
	cin>>n;
	rep(i,0,n)
		scanf("%d",B+i);
	rep(z,2,7)
	{
		int add=2*z-2;
		rep(mod,0,add)
		{
			D=Buff[z-2][mod];
			int cnt=0;
			for (int j=mod;j<n;j+=add)
			{
				A[cnt++]=B[j];
			}
			if (cnt)
				buildD(1,0,cnt-1);
			Cnt[z-2][mod]=cnt;
		}
	}
	int m;
	cin>>m;
	rep(i,0,m)
	{
		int t;
		scanf("%d",&t);
		if (t==1)
		{
			int p,val;
			scanf("%d%d",&p,&val);
			--p;
			rep(z,2,7)
			{
				int add=2*z-2;
				int mod=p%add;
				int pos=p/add;
				D=Buff[z-2][mod];
				update(1,0,Cnt[z-2][mod]-1,pos,val);
			}
		}
		else
		{
			int l,r,z;
			scanf("%d%d%d",&l,&r,&z);
			--l;--r;
			int add=2*z-2;
			ll res=0;
			int P[12];
			rep(i,0,z)
				P[i]=i+1;
			rep(i,0,z-2)
				P[i+z]=z-1-i;
			rep(i,0,add)
				if (l+i<=r)
				{
					int st=(l+i)/add;
					int mod=(l+i)%add;
					int en=(r-mod)/add;
					D=Buff[z-2][mod];
					res+=ll(P[i])*getSum(1,0,Cnt[z-2][mod]-1,st,en);
				}
			printf("%I64d\n",res);
		}
	}

}



int main()
{
#ifdef _MONYURA_
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    time_t st=clock();
#endif
    run();
#ifdef _MONYURA_
    printf("=============\n");
	printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif
    return 0;
}

/*

*/