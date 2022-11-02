#pragma comment(linker,"/STACK:64000000")
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
typedef pair<int,int> pii;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(x) (x).begin(),(x).end()

const double PI=acos(-1.0);

template<class T> inline T SQR(T a){return a*a;}

struct tree
{
	int a,h;
	int  pl,pr;
};


int main()
{
	int n,m;
	tree A[100001];
	cin>>n>>m;
	pii M[10001];
	map<int,int> mp;
	vector<int> vec;
	rep(i,0,n)
	{
		int l,r;
		scanf("%d%d%d%d",&A[i].a,&A[i].h,&l,&r);
		vec.push_back(A[i].a+1);
		vec.push_back(A[i].a);
		vec.push_back(A[i].a-A[i].h);
		vec.push_back(A[i].a+A[i].h+1);
		A[i].pl=l;
		A[i].pr=r;
	}
	rep(i,0,m)
	{
		scanf("%d%d",&M[i].first,&M[i].second);
		vec.push_back(M[i].first);
	}
	sort(M,M+m);
	sort(all(vec));
	vec.resize(unique(all(vec))-vec.begin());
	rep(i,0,vec.size())
		mp[vec[i]]=i;
	double P[500000];
	int z[500000]={0};
	rep(i,0,500000)
		P[i]=0;
	rep(i,0,n)
	{
		if (A[i].pl==100)
		{
			z[mp[A[i].a-A[i].h]]++;
			z[mp[A[i].a]]--;
		}
		else
		{
			P[mp[A[i].a-A[i].h]]+=log(1-A[i].pl/100.0);
			P[mp[A[i].a]]-=log(1-A[i].pl/100.0);
		}
		if (A[i].pr==100)
		{
			z[mp[A[i].a+1]]++;
			z[mp[A[i].a+A[i].h+1]]--;
		}
		else
		{
			P[mp[A[i].a+1]]+=log(1-A[i].pr/100.0);
			P[mp[A[i].a+A[i].h+1]]-=log(1-A[i].pr/100.0);
		}
	}
	double res=0;
	int d=0;
	int pos=0;
	double pr=0;
	rep(i,0,500000)
	{
		d+=z[i];
		pr+=P[i];
		while (pos<m && mp[M[pos].first]==i)
		{
			if (d==0)
				res+=M[pos].second*exp(pr);
			pos++;
		}
	}
	printf("%.9lf\n",res);
	return 0;
} 
/*
1 1
2 1 100 0
3 123
*/