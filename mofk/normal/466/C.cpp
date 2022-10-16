#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define MAX (int)1e5+5
#define f(i,n) for(i=1;i<=n;i++)
#define F(i,n) for(i=n;i>=1;i--)
#define FF(i,a,b) for(i=a;i>=b;i--)
#define ff(i,a,b) for(i=a;i<=b;i++)
typedef long long ll;
using namespace std;
int main(void)
{
	ll s=0,sa=0,sc=0,cnt1=0,cnt2=0,c1=0,c2=0;
	long n,i,j,a[500005],p,q,l,l2;
	int flag=0;
	scanf("%ld",&n);
	f(i,n) {
		scanf("%ld",&a[i]);
		s+=(ll)a[i];
	}
	if(s%3!=0) printf("0");
	else if(s==0)
	{
		f(i,n) {
			sa+=(ll)a[i];
			if(sa==0) cnt1++;
		}
		printf("%I64d",(cnt1-1)*(cnt1-2)/2);
	}
	else
	{
		ll ss=s/3;
		f(i,n)
		{
			sa+=(ll)a[i];
			if(sa==ss)
			{
				p=i;flag++;
				break;
			}
		}
		FF(i,n,p)
		{
			sc+=(ll)a[i];
			if(sc==ss)
			{
				q=i;flag++;break;
			}
		}
		if(p>=q||flag!=2) printf("0");
		else{
			ff(i,p+1,q-1)
			{
				c1+=a[i];
				if(c1==0) {
					cnt1++;l=i;}
			}
			FF(i,q-1,l)
			{
				c2+=a[i];
				if(c2==0){
					cnt2++;l2=i;
				}
			}
			if(l2==l&&l2!=0) printf("%I64d",((ll)cnt2+1)*((ll)cnt1+1)-1);
			else printf("%I64d",((ll)cnt2+1)*((ll)cnt1+1));
		}
	}
}