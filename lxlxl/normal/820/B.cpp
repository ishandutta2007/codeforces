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

const int maxn = 110000;
const int maxm = 1100;

int n,a;
double k,v[maxn],ct,hi;

int main()
{
	//freopen("tmp.in","r",stdin);
	//freopen("tmp.out","w",stdout);
	
	scanf("%d%d",&n,&a); hi=a;
	k=(n-2)*180.0/(double)n;
	ct=0.0;
	for(int i=1;i<=n-2;i++)
	{
		v[i]=(i*180.0-k*i)/2-ct;
		ct+=v[i];
	}
	//printf("%lf\n",k);
	//for(int i=1;i<=n-2;i++) printf("%lf\n",v[i]);
	
	k=v[1]; ct=k;
	double mn=1e9; int mk=0;
	for(int i=1;i<=n-2;i++,ct+=k) 
	{
		if(fabs(ct-hi)<mn) mn=fabs(ct-hi),mk=i;
	}
	printf("%d %d %d\n",1,n,mk+1);
	
	return 0;
}