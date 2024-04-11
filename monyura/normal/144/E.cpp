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

struct otr
{
	int a,b,ind;
	otr(int a0,int b0,int i0)
	{
		a=a0;
		b=b0;
		ind=i0;
	}
	otr(){}
};

bool operator<(const otr &a,const otr &b)
{
	if (a.a!=b.a)
		return a.a<b.a;
	return a.b<b.b;
}


int main()
{
	int n,m;
	cin>>n>>m;
	otr A[100001];
	rep(i,0,m)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		A[i]=otr(a,b,i);
	}
	sort(A,A+m);
	vector<int> res;
	set<int > S;
	set<int>::iterator it;

	int st=0;
	rep(i,1,n+1)
	{
		S.insert(i);
		while (st<m && A[st].a<=i)
		{
			it=S.lower_bound(n-A[st].b+1);
			if (it!=S.end())
			{
				res.push_back(A[st].ind);
				S.erase(it);
			}
			st++;
		}
	}
	printf("%d\n",res.size());
	rep(i,0,res.size())
		printf("%d ",res[i]+1);
	if (res.size())
		printf("\n");
	return 0;
} 

/*
5 6 3
3 1 1
3 2 1
3 4 1
3 5 1
1 2 7
4 5 8
4

3 3 1
1 2 1
1 3 4
2 3 2
3

5 5
3 3
4 4
5 5
2 4
1 5

4 10
1 4
2 4 2 3
3 4 3 3 3 2
4 4 4 3 4 2 4 1
*/