#include<iostream>
#include<algorithm> 
#include<cstdio>
using namespace std;
int n,pos;
double a[111],p,q;
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	p=0.00;q=1.00;pos=1;
	while(q>p && pos<=n)
	{
		p=p+a[pos]*q-a[pos]*p;
		q=q*(1.00-a[pos]);
		pos++;
	}
	printf("%.12lf\n",p);
	return 0;
 }