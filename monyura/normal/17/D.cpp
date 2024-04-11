#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>
#include <functional>


using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(x) (x).begin(),(x).end()
//#define x first
//#define y second

int prime[33000];
int cntPr=0;

void init()
{
	rep(i,2,33000)
	{
		bool ok=1;
		for (int j=0;j<cntPr && prime[j]*prime[j]<=i;j++)
			if (i%prime[j]==0)
			{
				ok=0;
				break;
			}
		if (ok) prime[cntPr++]=i;
	}
}

ll strByMod(char *str,ll M)
{
	ll res=0;
	for (int i=0;str[i];i++)
		res=(res*10+str[i]-'0')%M;
	return res;
}

int toPow(ll a,int b,int mod)
{
	if (a==0) return 0;
	int res=1;
	while (b)
	{
		if (b&1)
			res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}

int getFi(int a)
{	
	int res=1;
	for (int j=0;j<cntPr && prime[j]*prime[j]<=a;j++)
	{
		if (a%prime[j]==0)
		{
			int mn=1;
			while (a%prime[j]==0)
			{
				a/=prime[j];
				mn*=prime[j];
			}
			res=res*mn/prime[j]*(prime[j]-1);
		}
	}
	if (a!=1) res*=a-1;
	return res;
}


int c;
char B[1000100],N[1000100];

bool test()
{
	scanf("%s %s%d",B,N,&c);
	int b=strByMod(B,c);
	if (strcmp(N,"1")==0)
	{
		printf("%d\n",(b-1+c)%c);
		return 0;
	}
	ll res=1;
	//Some strange method:
	int fi=getFi(c);
	int n=(strByMod(N,fi)-1+fi)%fi;
	n+=fi;
	res=toPow(b,n,c);
	res=(res*(b-1+c))%c;
	if (res==0) res=c;
	cout<<res<<endl;
	return true;
}

int main()
{
	init();
	test();
	return 0;
}
/*
2 5 805306368
*/