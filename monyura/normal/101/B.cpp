#pragma comment(linker,"/STACK:65000000")
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
typedef short int si;
typedef long double ld;
typedef pair<int,int> pii;
#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)

const double PI=acos(-1.0);

template<class T> inline T sqr(T a){return a*a;}


int M=1e9+7;
struct elem
{
	int x;
	ll sum;
	elem* open;
};

bool cmp(const elem *a,const elem *b)
{
	if (a->x!=b->x)
		return a->x<b->x;
	return a->open!=0 && b->open==0;
}

int main()
{
	int n,m;
	cin>>n>>m;
	elem **A=new elem*[200100];
	elem *tmp=new elem[200100];
	rep(i,0,m)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		tmp[2*i+1].x=b;
		tmp[2*i+1].open=tmp+2*i;
		tmp[2*i].x=a;
		tmp[2*i].open=0;
		A[2*i+1]=tmp+2*i+1;
		A[2*i]=tmp+2*i;
	}
	sort(A,A+2*m,cmp);
	int curr=0;
	int tut=1;
	int last=0;
	rep(i,0,2*m)
	{
		if (A[i]->x!=last) tut=0;
		if (A[i]->open)
		{
			int tmp=(curr-A[i]->open->sum-tut+M)%M;
			curr=(curr+tmp)%M;
			last=A[i]->x;
			tut=(tut+tmp)%M;
		}
		else
			A[i]->sum=(curr-tut+M)%M;
	}
	if (last!=n) tut=0;
	printf("%d\n",tut);
	return 0;      
}

/*

5 4
0 1
2 5
3 4
2 4
*/