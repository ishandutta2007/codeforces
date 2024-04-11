#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

#define rep(x,y,z) for (int x=(y),e##x = (z);x<e##x; x++)

typedef long long ll;
typedef pair<int,int> pii;

int get4Root(ll a)
{
	ll rt = pow(double(a),1/4.0);
	for (ll i=max(0LL,rt-3);i<=rt+3;i++)
		if (i*i*i*i>=a)
			return i;
}

int get2Root(ll a)
{
	ll rt = pow(double(a),1/2.0);
	for (ll i=rt+3;i>=max(0LL,rt-3);i--)
		if (i*i<=a)
			return i;
}

int A[400200];

void calcVal()
{
	A[0]=0;
	rep(i,1,400200)
	{
		int fr = get4Root(i);
		int to = get2Root(i);
		if (to>=i)
			to=i-1;
		bool mex[5]={0};
		rep(j,fr,to+1)
			mex[A[j]]=1;
		rep(j,0,5)
			if (!mex[j])
			{
				A[i]=j;
				break;
			}
		if (i%50000==0)
			puts("I am here");
	}
	rep(i,0,400200)
		if (i==0 || A[i]!=A[i-1])
			printf("A[%d] = %d\n",i,A[i]);
}

int getSG(ll a)
{
	int bnd[7]={0,4,16,82,6724,50626,4000000};
	int val[7]={0,1,2,0,3,1};
	if (a<4000000)
	{
		for (int i=5;i>=0;i--)
			if (a>=bnd[i])
				return val[i];
	}
	else
	{
		int fr = get4Root(a);
		int to = get2Root(a);
		bool mex[5]={0};
		rep(i,0,6)
			if (min(to,bnd[i+1])>=max(fr,bnd[i]))
				mex[val[i]]=1;
		rep(i,0,5)
			if (!mex[i])
				return i;
	}
}

int main()
{
	int n;
	cin>>n;
	int X=0;
	rep(i,0,n)
	{
		ll a;
		cin>>a;
		X^=getSG(a);
	}
	if (X)
		puts("Furlo");
	else
		puts("Rublo");
	return 0;
}