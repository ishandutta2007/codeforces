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

int n;
int a[maxn];

int main()
{
//	freopen("tmp.in","r",stdin);
	
	int Tcase; scanf("%d",&Tcase);
	while(Tcase--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		
		int ok=1;
		for(int i=2;i<=n;i++) if(a[i]!=a[1]) ok=0;
		
		if(ok) printf("%d\n",n);
		else printf("%d\n",1);
	}
	
	return 0;
}