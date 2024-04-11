#ifdef _MONYURA_
#pragma comment(linker,"/STACK:256000000")
#endif

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
typedef pair<short,short> pss;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(x) (x).begin(),(x).end()
#define movmax(A,B) {if(A<(B)) A=(B);}
#define movmin(A,B) {if(A>(B)) A=(B);}

const double PI=acos(-1.0);
template<class T> T SQR(const T &a){return a*a;}


ll P[64][64]={0}, N[64][64]={0};

bool isPeriodik(char *A,int n)
{
	rep(i,1,n)
		if (n%i==0)
		{
			bool ok=1;
			for (int j=i;j<n && ok;j+=i)
				if (strncmp(A,A+j,i)!=0)
					ok=0;
			if (ok)
				return true;
		}
	return false;
}

int getLen(ll x)
{
	for (int i=63;i>=0;i--)
		if ((x>>i)&1)
			return i+1;
	return 0;
}

bool all;
void init(ll x)
{
	char A[100]={0};
	int len=getLen(x);
	rep(i,0,len)
		A[i]=((x>>i)&1)+'0';
	reverse(A,A+len);
	all=isPeriodik(A,len);
	rep(k,1,len+1)
		rep(l,k,len+1)
		{
			rep(d,1,l)
				if (l%d==0)
				{
					char was=A[k-1];
					A[k-1]='0';
					bool ok=1;
					rep(i,0,d)
						for (int j=i;j<k;j+=d)
							if (A[i]!=A[j])
								ok=0;
					A[k-1]=was;
					if (ok)
					{
						if (d<k)
							P[k][l]+=1-isPeriodik(A,d);
						else
							P[k][l]+=N[min(d,k)][d];
					}
				}
			N[k][l]=(1LL<<(l-k))-P[k][l];
		}
}

ll getCnt(ll x)
{
	if (x==0) return 0;
	memset(P,0,sizeof(P));
	memset(N,0,sizeof(N));
	init(x);
	int len=getLen(x);
	ll res=0;
	rep(i,1,len)
		res+=P[1][i];
	for (int i=len-2,j=2;i>=0;i--,j++)
		if (((x>>i)&1))
			res+=P[j][len];
	res+=all;
	return res;
}

void brutForce(int to)
{
	int res=0;
	char A[100];
	rep(i,1,to+1)
	{
		int len=getLen(i);
		rep(j,0,len)
			A[j]=((i>>j)&1)+'0';
		res+=isPeriodik(A,len);
		ll ans=getCnt(i);
		if (ans!=res)
		{
			printf("i=%d res=%d calculated=%lld\n",i,res,ans);
			A[len]=0;
			reverse(A,A+len);
			printf("%s\n",A);
		}
	}
}

void run()
{
	/*int n;
	cin>>n;
	ll cnt=getCnt(n);
	brutForce(n);
	return;*/
	ll a,b;
	cin>>a>>b;
	ll ra=getCnt(a-1);
	ll rb=getCnt(b);
	ll r=rb-ra;
	cout<<r<<endl;
}

int main()
{
#ifdef _MONYURA_
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    time_t beg=clock();
#endif
    run();
#ifdef _MONYURA_
    printf("================\n");
    printf("Time: %.3lf s.\n",(clock()-beg)/double(CLOCKS_PER_SEC));
#endif
    return 0;
}

/*
188
*/