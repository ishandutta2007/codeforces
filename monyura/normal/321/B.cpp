#pragma comment(linker,"/STACK:650000000")
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

int killAll(int n,pii *A,int m,int *B)
{
	if (n>m) return 0;
	bool used[101]={0};
	vector<int> a;
	rep(i,0,n)
		if (A[i].second==0)
		{
			bool ok = false;
			rep(j,0,m)
				if (!used[j] && B[j]>A[i].first)
				{
					ok = true;
					used[j]=1;
					break;
				}
			if (!ok)
				return 0;
		}
		else
			a.push_back(A[i].first);
	vector<int> b;
	rep(i,0,m)
		if (!used[i])
			b.push_back(B[i]);
	rep(i,0,b.size()-a.size())
		a.push_back(0);
	sort(all(a));
	sort(all(b));
	//reverse(all(b));
	int res = 0;
	bool killed[101]={0};
	rep(i,0,b.size())
	{
		bool ok=false;
		rep(j,0,a.size())
			if (!killed[j] && a[j]<=b[i])
			{
				ok=true;
				killed[j] = 1;
				res+=b[i]-a[j];
				break;
			}
		if (!ok)
			return 0;
	}
	return res;
}

int killAtck(int n,pii *A,int m,int *B)
{
	vector<int> a;
	rep(i,0,n)
		if (A[i].second==1)
			a.push_back(A[i].first);
	sort(all(a));
	sort(B,B+m);
	reverse(B,B+m);
	int res = 0;
	bool killed[101]={0};
	rep(i,0,m)
	{
		rep(j,0,a.size())
			if (!killed[j] && a[j]<=B[i])
			{
				killed[j] = 1;
				res+=B[i]-a[j];
				break;
			}
	}
	return res;

}

void run()
{
	int n,m;
	cin>>n>>m;
	pii A[101];
	rep(i,0,n)
	{
		char str[100];
		int b;
		scanf("%s%d",str,&b);
		if (str[0]=='D')
			A[i].second = 0;
		else
			A[i].second = 1;
		A[i].first = b;
	}
	sort(A,A+n);
	int B[101];
	rep(i,0,m)
		scanf("%d",B+i);
	sort(B,B+m);
	int r1=killAll(n,A,m,B);
	int r2=killAtck(n,A,m,B);
	int res = max(r1,r2);
	cout<<res<<endl;
}

#define problem "proddiff"


int main()
{
#ifdef _MONYURA_
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	time_t st=clock();
#else
	//freopen(problem".in","r",stdin);
	//freopen(problem".out","w",stdout);
#endif
	run();
#ifdef _MONYURA_
	printf("=============\n");
	printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif

	return 0;
}