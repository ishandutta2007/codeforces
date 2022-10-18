#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define MAX (int)1e5+5
#define f(i,n) for(i=1;i<=n;i++)
#define F(i,n) for(i=n;i>=1;i--)
#define ff(i,a,b) for(i=a;i<=b;i++)
typedef long long ll;
using namespace std;
ll n,k,d1,d2;
ll ab(ll a)
{
	if(a>0) return a;
	else return -a;
}
int main(void)
{
	long int p,t;
	scanf("%ld",&t);
	f(p,t) 
	{
		scanf("%I64d%I64d%I64d%I64d",&n,&k,&d1,&d2);
		if(n%3!=0) printf("no\n");
		else
		{
			if((k+2*d1+d2)%3==0&&k+2*d1+d2<=n&&k-d1-2*d2>=0) printf("yes\n");
			else if((k-d1-d2)%3==0&&k+max(d1,d2)+ab(d1-d2)<=n&&k-d1-d2>=0) printf("yes\n");
			else if((k+d1+d2)%3==0&&k+d1+d2<=n&&k-max(d1,d2)-ab(d2-d1)>=0) printf("yes\n");
			else if((k+d1+2*d2)%3==0&&k+d1+2*d2<=n&&k-2*d1-d2>=0) printf("yes\n");
			else printf("no\n");
		}
	}
}