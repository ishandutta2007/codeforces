#ifdef _MONYURA_
#pragma comment(linker,"/STACK:256000000")
#endif

#include <iostream>
#include <cstdio>
#include <bitset>
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
#define SQ(x) ((x)*(x))
#define all(c) (c).begin(), (c).end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;

const double PI=acos(-1.0);


const int mod = 1000000007;
int Fen[200200]={0};

ll toPow(ll a,int b,ll mod)
{
	if (b==0)
		return 1;
	if (a==0)
		return 0;
	a%=mod;
	if (a<0) a+=mod;
	ll res=1;
	while (b)
	{
		if (b&1)
			res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}

void addToFen(int pos)
{
	for (int j=pos;j<=100500;j+=j&-j)
		Fen[j]++;
}

int getFen(int pos)
{
	if (pos<=0)
		return 0;
	int res=0;
	for (int j=pos;j>0;j-=j&-j)
		res+=Fen[j];
	return res;
}

void run()
{	
	int n;
	cin>>n;
	int A[100100];
	rep(i,0,n)
	{
		scanf("%d",A+i);
		addToFen(A[i]);
	}
	ll res=0;
	int to=*max_element(A,A+n)+1;
	rep(i,1,to)
	{
		vector<int> v;
		int j;
		for (j=1;j*j<i;j++)
			if (i%j==0)
			{
				v.push_back(j);
				v.push_back(i/j);
			}
		if (j*j==i)
			v.push_back(j);
		v.push_back(100100);
		sort(all(v));
		ll curr=1;
		rep(j,0,v.size()-1)
		{
			int cnt=getFen(v[j+1]-1)-getFen(v[j]-1);
			ll mul=toPow(j+1,cnt,mod);
			if (j==v.size()-2)
			{
				mul=(mul - toPow(j,cnt,mod))%mod;
			}
			curr=(curr*mul)%mod;
		}
		res=(res+curr)%mod;
	}
	res%=mod;
	if (res<0)
		res+=mod;
	cout<<res<<endl;
}



int main()
{
#ifdef _MONYURA_
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	time_t st=clock();
#else
	//freopen("barns.in","r",stdin);
	//freopen("barns.out","w",stdout);
#endif
	run();
#ifdef _MONYURA_
	printf("=============\n");
	printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif

	return 0;
}

/*
10 10 92
11 10 92
*/