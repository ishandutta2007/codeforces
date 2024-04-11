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
typedef short int si;
typedef unsigned short int usi;
typedef long double ld;
typedef pair<int,int> pii;
#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(x) (x).begin(),(x).end()

const double PI=acos(-1.0);

template<class T> inline T SQR(T a){return a*a;}

vector<int> vec;

void rec(int step,int val)
{
	if (step>=9) return;
	vec.push_back(val);
	rec(step+1,val*10+4);
	rec(step+1,val*10+7);
}

ll fac(int n)
{
	ll res=1;
	for (int i=2;i<=n;i++)
		res*=i;
	return res;
}

int main()
{
	int n,k;
	cin>>n>>k;
	if (n<=15 && fac(n)<k)
	{
		printf("-1\n");
		return 0;
	}
	k--;
	rec(0,4);
	rec(0,7);
	sort(all(vec));
	int fr=max(0,n-14);
	int res=upper_bound(all(vec),fr)-vec.begin();
	int A[14];
	for (int i=fr;i<n;i++)
		A[i-fr]=i+1;
	for (int i=fr;i<n;i++)
	{
		ll ind=0;
		ll f=fac(n-i-1);
		if (f!=0)
			ind=k/f;
		k%=f;
		int curr;
		rep(j,0,14)
			if (A[j]!=0)
			{
				if (!ind)
				{
					curr=A[j];
					A[j]=0;
					
					break;
				}
				ind--;
			}
		if (binary_search(all(vec),i+1) && binary_search(all(vec),curr))
			res++;
	}
	cout<<res<<endl;
	return 0;
}
/*
2 1
5 6
7 8

1 0
5 6

1 1
3 43

1 0
3 4

2 0
1 1000000000000000000
4 4
*/