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
#define x first
#define y second

const double PI=acos(-1.0);

int main()
{
	ll k;
	int n;
	cin>>n>>k;
	int A[100001];
	map<int,int> mp;
	rep(i,0,n)
	{
		scanf("%d",A+i);
		mp[A[i]]++;
	}
	sort(A,A+n);
	for (map<int,int>::iterator it=mp.begin();it!=mp.end();it++)
		if (k<=it->second*ll(n))
		{
			int add=it->second;
			rep(j,0,n)
				if (k<=add)
				{
					printf("%d %d\n",it->first,A[j]);
					return 0;
				}
				else
					k-=add;
		}
		else
			k-=it->second*ll(n);

	return 0;
}