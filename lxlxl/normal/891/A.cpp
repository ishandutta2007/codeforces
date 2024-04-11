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
#define ll long long
using namespace std;

inline void down(int &x,const int &y){if(x>y)x=y;}
const int maxn = 2100;

int gcd(int a,int b){return a==0?b:gcd(b%a,a);}

int n;
int a[maxn];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	
	int ct=0;
	for(int i=1;i<=n;i++) if(a[i]==1) ct++;
	if(ct) return printf("%d\n",n-ct),0;
	
	int l=n+1;
	for(int i=1;i<=n;i++)
	{
		int d=0;
		for(int j=i;j<=n;j++)
		{
			d=gcd(d,a[j]);
			if(d==1) { down(l,j-i+1);break; }
		}
	}
	if(l==n+1) puts("-1");
	else printf("%d\n",n-1+l-1);
	
	return 0;
}