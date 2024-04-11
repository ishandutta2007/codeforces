#pragma comment(linker,"/STACK:62000000")
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

int pr[5000];

int findSet(int a)
{
	if (pr[a]!=a)
		pr[a]=findSet(pr[a]);
	return pr[a];
}

int main()
{
	int n,m;
	vector<pii> S;
	vector<int> Si;
	vector<pii> M;
	vector<int> Mi;
	cin>>n>>m;
	if (n%2==0)
	{
		printf("-1\n");
		return 0;
	}
	rep(i,0,m)
	{
		int a,b;
		char c;
		scanf("%d%d %c",&a,&b,&c);
		--a;--b;
		if (a==b) continue;
		if(c=='S'){S.push_back(pii(a,b));Si.push_back(i+1);}
		else{ M.push_back(pii(a,b));Mi.push_back(i+1);}
	}
	rep(i,0,n)
		pr[i]=i;
	int cnt=0;
	rep(i,0,M.size())
	{
		int pra=findSet(M[i].first);
		int prb=findSet(M[i].second);
		if (pra!=prb)
			pr[pra]=prb;
	}
	vector<int> res;
	vector<pii> vec;
	rep(i,0,S.size())
	{
		if (cnt==(n-1)/2) break;
		int pa=findSet(S[i].first);
		int pb=findSet(S[i].second);
		if (pa!=pb)
		{
			cnt++;
			pr[pa]=pb;
			vec.push_back(S[i]);
			res.push_back(Si[i]);
		}
	}
	rep(i,0,n)
		pr[i]=i;
	rep(i,0,vec.size())
		pr[findSet(vec[i].first)]=findSet(vec[i].second);
	rep(i,0,S.size())
	{
		if (cnt==(n-1)/2) break;
		int pa=findSet(S[i].first);
		int pb=findSet(S[i].second);
		if (pa!=pb)
		{
			cnt++;
			pr[pa]=pb;
			res.push_back(Si[i]);
		}
	}
	if (cnt!=(n-1)/2)
	{
		printf("-1\n");
		return 0;
	}
	rep(i,0,M.size())
	{
		int pa=findSet(M[i].first);
		int pb=findSet(M[i].second);
		if (pa!=pb)
		{
			cnt++;
			pr[pa]=pb;
			res.push_back(Mi[i]);
		}
	}
	if (cnt!=n-1)
		printf("-1\n");
	else
	{
		printf("%d\n",res.size());
		rep(i,0,res.size())
			printf("%d ",res[i]);
	}
	return 0;
} 

/*
2 0
4 6 1 1
2 2 1 2

2 10
6 4 1 1
2 4 1 2

1 10
1 10 2 2
*/