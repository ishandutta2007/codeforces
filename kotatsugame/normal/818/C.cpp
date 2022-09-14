#include<iostream>
#include<algorithm>
using namespace std;
int N,H,W;
int a[1<<17],b[1<<17],c[1<<17],d[1<<17];
int L[1<<17],R[1<<17],D[1<<17],U[1<<17];
main()
{
	cin>>N>>H>>W;
	for(int i=0;i<N;i++)
	{
		cin>>a[i]>>b[i]>>c[i]>>d[i];
		if(a[i]==c[i])
		{
			if(b[i]>d[i])swap(b[i],d[i]);
			L[a[i]+1]++;
			R[a[i]-1]++;
			U[d[i]]++;
			D[b[i]]++;
		}
		else
		{
			if(a[i]>c[i])swap(a[i],c[i]);
			L[c[i]]++;
			R[a[i]]++;
			U[b[i]+1]++;
			D[b[i]-1]++;
		}
	}
	for(int i=0;i<=H;i++)L[i+1]+=L[i];
	for(int i=H;i>=0;i--)R[i]+=R[i+1];
	for(int i=0;i<=W;i++)U[i+1]+=U[i];
	for(int i=W;i>=0;i--)D[i]+=D[i+1];
	int l,r,u,dd;cin>>l>>r>>u>>dd;
	for(int i=0;i<N;i++)
	{
		if(a[i]==c[i])
		{
			if(l==L[a[i]]&&r==R[a[i]]&&u==U[d[i]]-1&&dd==D[b[i]]-1)
			{
				cout<<i+1<<endl;
				return 0;
			}
		}
		else
		{
			if(l==L[c[i]]-1&&r==R[a[i]]-1&&u==U[b[i]]&&dd==D[b[i]])
			{
				cout<<i+1<<endl;
				return 0;
			}
		}
	}
	cout<<-1<<endl;
}