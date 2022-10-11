#include <iostream>
#include <algorithm>
using namespace std;
int d[150000],n1[150000],n2[150000],d1[150000],d2[150000],a,b,res=0,r=0,s=0,q;
bool comp(int a,int b) 
{
	return (d[a]>d[b]);
}
int main() 
{
	int n,v,p1=0,p2=0,i;
	cin >> n >> v;
	for (i=1;i<=n;i++) 
	{
		cin >> a >> b;
		d[i]=b;
		if (a==1)
		{
			p1++;
			n1[p1]=i;
		}
		else
		{
			p2++;
			n2[p2]=i;
		}
	}
	sort(n1+1,n1+p1+1,comp);
	sort(n2+1,n2+p2+1,comp);
	d1[0]=0;
	d2[0]=0;
	for (i=1;i<=p1;i++)
	d1[i]=d1[i-1]+d[n1[i]];
	for (i=1;i<=p2;i++)
	d2[i]=d2[i-1]+d[n2[i]];
	for (i=0; i<=p1 && i<=v;i++) 
	{
		q=(v-i)/2;
		if (q>p2)
		q=p2;
		if (d1[i]+d2[q]>res)
		{
		res=d1[i]+d2[q];
		r=i;
		s=q;
		}
	}
	cout << res << endl;
	for (int i = 1; i <= r; i ++)
	cout << n1[i] << " ";
	for (int i = 1; i <= s; i ++)
	cout << n2[i] << " ";
}