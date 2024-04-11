#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;
struct str
{
	long long int d;
	int ind;
};
long long int l=1;
long long int d=1000000000000000,p,q,p1,q1,p2,q2;
long long int m=0;
str sum[200000];
long long int n,k;
int a[200000];
bool operator <(str x,str y)
{
	return x.d<y.d || (x.d==y.d && x.ind<y.ind);
}
int main()
{
	scanf("%lld %lld",&n,&k);
	sum[0].d=0;
	sum[0].ind=0;
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=0;i<n;i++)
	{
		l=a[i];
		sum[i+1].ind=i+1;
		sum[i+1].d=sum[i].d+l;
	}
	sort(sum,sum+n+1);
	l=1;
	while(l<d && l>-d) 
	{
		p=0;
		q=0;
		p1=0;
		q1=0;
		while(q<=n)
		{
			if(sum[q].d-sum[p].d==l)
			{
				while(q+q1<=n && sum[q+q1].d==sum[q].d) q1++;
				while(p+p1<=n && sum[p+p1].d==sum[p].d) p1++;
				p2=p;
				q2=q;
				while(p2<p+p1 && q2<q+q1)
				{
					if(sum[q2].ind<sum[p2].ind) q2++;
					else
					{
						m=m+(q+q1-q2);
						p2++;
					}
				}
				p=p+p1;
				q=q+q1;
				p1=0;
				q1=0;
			}
			else
			{
				p1=0;
				q1=0;
				if(sum[q].d-sum[p].d>l) p++;
				else q++;
			}
		}
		//m=m+p1*q1;
		//cout<<m<<endl;
		l=l*k;
		if(l==1) break;
	}
	printf("%lld",m);
	return 0;
}