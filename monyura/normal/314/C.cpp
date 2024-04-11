#pragma comment(linker,"/STACK:65000000")
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
#include <wchar.h>
#include <wctype.h>
#include <cmath>
#include <queue>
#include <ctime>
#include <numeric>
#include <assert.h>


using namespace std;

template<typename T> T mabs(const T &a){ return a<0?-a:a;}
#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define SQR(x) ((x)*(x))
#define all(c) (c).begin(), (c).end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

const double PI = acos(-1.0);

int mod = 1e9+7;

const int SZ=1e6+10;
int Fen[SZ];
int Sum1[SZ],Sum2[SZ];

void addFen(int pos,int val)
{
	++pos;
	for (int i=pos;i<SZ;i+=i&-i)
		Fen[i]=(Fen[i]+val)%mod;
}

int getFen(int pos)
{
	++pos;
	int res = 0;
	for (int i=pos;i>0;i-=i&-i)
		res=(res+Fen[i])%mod;
	return res;
}

void run()
{
	int n;
	int A[100100];
	cin>>n;
	rep(i,0,n)
		scanf("%d",A+i);
	addFen(0,1);
	Sum1[0]=1;
	ll res = 0;
	rep(i,0,n)
	{
		ll val = getFen(A[i]);
		val = (val*A[i])%mod;
		ll toAdd = (val-Sum1[A[i]])%mod;
		if (toAdd<0) toAdd+=mod;
		addFen(A[i],toAdd);
		Sum1[A[i]]=val;
	}
	rep(i,1,SZ)
		res = (res+Sum1[i])%mod;
	cout<<res<<endl;
}


int main()
{
#ifdef _MONYURA_
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	time_t st=clock();
#else
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	run();
#ifdef _MONYURA_
	printf("=============\n");
	printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif

	return 0;
}

/*
24 54 96 108
*/