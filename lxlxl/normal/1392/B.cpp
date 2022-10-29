#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#include<cassert>
#define ll long long
#define db double
#define fir first
#define sec second
#define mp make_pair
using namespace std;

const int maxn = 210000;

int n; ll K;
int a[maxn];

int main()
{
	int Tcase; scanf("%d",&Tcase);
	while(Tcase--)
	{
		scanf("%d%lld",&n,&K);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		
		int mx=INT_MIN;
		for(int i=1;i<=n;i++) mx=max(mx,a[i]);
		
		for(int i=1;i<=n;i++) a[i]=mx-a[i];
		mx=INT_MIN;
		for(int i=1;i<=n;i++) mx=max(mx,a[i]);
		K--;
		
		if(K&1ll)
		{
			for(int i=1;i<=n;i++) a[i]=mx-a[i];
		}
		
		for(int i=1;i<=n;i++) printf("%d%c",a[i]," \n"[i==n]);
	}
	
	return 0;
}