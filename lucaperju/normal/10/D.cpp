#include <iostream>

using namespace std;
int v[510],v1[510],d[510],m,poz[510],pred;
int verif (int val, int poz)
{
	for(int i=poz;i<=m;i++)
		if(v1[i]==val)
			return i;
	return -1;
}
int main()
{
    int n,i,j,k,mx,p,mxx=0,a;
    cin>>n;
    for(i=1;i<=n;i++)
		cin>>v[i];
	cin>>m;
	for(i=1;i<=m;i++)
		cin>>v1[i];
	for(i=1;i<=n;i++)
	{
		mx=1;
		p=1;
		for(j=i-1;j>=1;j--)
		{
			if(v[j]<v[i] && d[j]>mx-1 ||  v[j]<v[i] && d[j]==i-1)
			{
				a=verif(v[i],poz[j]);
				if(a!=-1 && d[j]>mx-1 || a!=-1 && a<p && d[j]==mx-1)
				{
					mx=d[j]+1;
					p=a;
				}
			}
		}
		a=verif(v[i],p);
		if(a!=-1)
			d[i]=mx,poz[i]=a;
		else
			d[i]=0,poz[i]=m+1;
		if(d[i]>mxx)
			mxx=d[i];
	}
	pred=m+1;
	mx=mxx;
	cout<<mxx<<'\n';
	for(i=n;i>=1,mxx!=0;i--)
	{
		if(d[i]==mxx && poz[i]<pred)
            v1[mxx]=v[i],mxx--,pred=poz[i];
	}
	for(i=1;i<=mx;i++)
		cout<<v1[i]<<' ';
    return 0;
}