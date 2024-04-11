#include<iostream>
#define long long long
using namespace std;
long n,m,k,x,y;
long count;
long c[100][100];
main()
{
	cin>>n>>m>>k>>x>>y;
	if(n!=1){
		count=k/((n-1)*m);
		for(int i=0;i<m;i++)c[0][i]=c[n-1][i]=count/2;
		if(count%2)for(int i=0;i<m;i++)c[0][i]++;
		for(int i=0;i<m;i++)for(int j=1;j<n-1;j++)c[j][i]=count;
		if(count%2==0)
		{
			k-=count*((n-1)*m);
			long a=k/m;
			for(int i=0;i<a;i++)for(int j=0;j<m;j++)c[i][j]++;
			k-=a*m;
			for(int i=0;i<k;i++)c[a][i]++;
		}
		else
		{
			k-=count*((n-1)*m);
			long a=k/m;
			for(int i=0;i<a;i++)for(int j=0;j<m;j++)c[n-1-i][j]++;
			k-=a*m;
			for(int i=0;i<k;i++)c[n-1-a][i]++;
		}
		long minc=1LL<<60,maxc=0;
		for(int i=0;i<n;i++)for(int j=0;j<m;j++)minc=min(minc,c[i][j]),maxc=max(maxc,c[i][j]);
		cout<<maxc<<" "<<minc<<" "<<c[x-1][y-1]<<endl;
	}
	else
	{
		cout<<(k-1)/m+1<<" "<<k/m<<" ";
		if(y<=k%m)cout<<(k-1)/m+1;
		else cout<<k/m;
		cout<<endl;
	}
		
}