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
#define pb push_back
#define SZ(X) ((int)X.size())
using namespace std;

const int maxn = 110000;
const int maxc = 30;

int n;
int a[maxn];

int main()
{
	int Tcase; scanf("%d",&Tcase);
	while(Tcase--)
	{
		scanf("%d",&n);
		int k=0;
		for(int i=1;i<=n;i++) scanf("%d",&a[i]),k^=a[i];
		
		if(!k) { puts("DRAW"); continue; }
		int mxi=0;
		for(int i=0;i<31;i++) if(k>>i&1)
			mxi=i;
		
		int s0=0,s1=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]>>mxi&1) s1++;
			else s0++;
		}
		
		if(s0&1)
		{
			puts("WIN");
		}
		else
		{
			if(s1%4==1)
			{
				puts("WIN");
			}
			else
			{
				puts("LOSE");
			}
		}
	}
	
	return 0;
}