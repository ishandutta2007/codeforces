#ifdef _MONYURA_
#pragma comment(linker,"/STACK:256000000")
#endif

#include <iostream>
#include <iomanip>
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
#include <wchar.h>
#include <wctype.h>
#include <cmath>
#include <queue>
#include <ctime>
#include <numeric>


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

const int SZ = 300300;

int End[SZ],Beg[SZ];

void addFen(int pos,int val,int *Fen)
{
	for (int i=pos;i<SZ;i+=i&-i)
		Fen[i]+=val;
}

int getFen(int pos,int *Fen)
{
	int res = 0;
	for (int i=pos;i>0;i-=i&-i)
		res+=Fen[i];
	return res;
}

int getAB(int a,int b,int *Fen)
{
	int res = getFen(b,Fen);
	if (a>1) res-=getFen(a-1,Fen);
	return res;
}

map<int,int> mp;
int n;
int A[SZ];

//void delBob(int i,int sec)
//{
//	if (getAB(A[i],A[i],End)==1)
//	{
//		addFen(A[i],-1,End);
//		if (A[i]!=1 && mp[A[i]-1]<i && A[i]-1!=sec)
//			addFen(A[i]-1,1,End);
//	}
//	if (getAB(A[i],A[i],Beg)==1)
//	{
//		addFen(A[i],-1,Beg);
//		if (A[i]!=n && mp[A[i]+1]>i && A[i]+1!=sec)
//			addFen(A[i]+1,1,Beg);
//	}
//}
//
//void addBob(int i,int sec)
//{
//	if (A[i]==n || mp[A[i]+1]<i || A[i]+1==sec)
//		addFen(A[i],1,End);
//	if (A[i]!=1 && mp[A[i]-1]<i && A[i]-1!=sec)
//		addFen(A[i]-1,-1,End);
//	if (A[i]==1 || mp[A[i]-1]>i || A[i]-1==sec)
//		addFen(A[i],1,Beg);
//	if (A[i]!=n && mp[A[i]+1]>i && A[i]+1!=sec)
//		addFen(A[i]+1,-1,Beg);
//}

void check(int i)
{
	if (i==n || mp[i+1]<mp[i])
		addFen(i,1,End);
	if (i==1 || mp[i-1]>mp[i])
		addFen(i,1,Beg);
}

void uncheck(int i)
{
	if (getAB(i,i,Beg))
		addFen(i,-1,Beg);
	if (getAB(i,i,End))
		addFen(i,-1,End);
}

void proc(int a,int b)
{
	int valB = A[b];
	int valA = A[a];
	swap(A[a],A[b]);
	mp[valA] = b;
	mp[valB] = a;
	vector<int> v;
	v.push_back(valA);
	v.push_back(valB);
	rep(i,0,2)
		for (int j=-1;j<=1;j+=2)
			if (v[i]+j>=1 && v[i]+j<=n)
				v.push_back(v[i]+j);
	sort(all(v));
	v.resize(unique(all(v))-v.begin());
	rep(i,0,v.size())
		uncheck(v[i]);
	rep(i,0,v.size())
		check(v[i]);
}

void show(int n)
{
	puts("");
	rep(i,1,n+1)
		printf("%d ",getAB(i,i,Beg));
	puts("");
	rep(i,1,n+1)
		printf("%d ",getAB(i,i,End));
}

void run()
{
	cin>>n;
	rep(i,0,n)
	{
		scanf("%d",A+i);
		mp[A[i]] = i;
	}
	rep(i,1,n+1)
	{
		check(i);
	}
	int q;
	cin>>q;
	rep(i,0,q)
	{
		int t,a,b;
		scanf("%d%d%d",&t,&a,&b);
		if (t==1)
		{
			int res = getAB(a,b,End);
			if (a!=n && mp[b+1]>mp[b])
				res++;
			printf("%d\n",res);
		}
		else
		{
			--a;--b;
			proc(a,b);
		}
		//show(n);
	}
}

#define prob "victory"

int main()
{
#ifdef _MONYURA_
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    time_t st=clock();
#else
    //freopen(prob".in","r",stdin);
    //freopen(prob".out","w",stdout);
#endif
    run();
#ifdef _MONYURA_
    printf( "\n=============\n");
    printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif

    return 0;
}