#pragma comment(linker,"/STACK:32000000")
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
typedef pair<ll,ll> pll;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(x) (x).begin(),(x).end()
#define movmax(A,B) {if(A<(B)) A=(B);}
#define movmin(A,B) {if(A>(B)) A=(B);}
#define x first
#define ind second

const double PI=acos(-1.0);
template<class T> T SQR(const T &a){return a*a;}


int main()
{
	int n,m;
	int T[100100];
	pii X[100100];
	cin>>n>>m;
	rep(i,0,n)
	{
		scanf("%d%d",T+i,&X[i].x);
		X[i].ind=i;
	}
	int A[100100];
	ll t=0,d=0;
	for (int i=0;i<n;)
	{
		if (n-i<m) m=n-i;
		t+=max(d,T[i+m-1]-t);
		sort(X+i,X+i+m);
		d=0;
		rep(j,0,m)
		{
			int k=1;
			while (j<m-1 && X[i+j].x==X[i+j+1].x) j++,k++;
			t+=X[i+j].x-d;
			rep(l,0,k)
				A[X[i+j-l].ind]=t;
			t+=1+k/2;
			d=X[i+j].x;
		}
		i+=m;
	}
	rep(i,0,n)
		printf("%d ",A[i]);
	puts("");
	return 0;
}

/*
5 1
3 5
4 5
5 5
6 5
7 1
*/