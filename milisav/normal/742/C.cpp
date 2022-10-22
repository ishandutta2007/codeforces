#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
int n;
int crush[1002];
int l[1002];
bool b[1002];
vector<int> a;
vector<int> c;
bool imp=false;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&crush[i]);
		crush[i]--;
		l[crush[i]]++;
	}
	for(int i=0;i<n;i++)
	{
		b[i]=false;
		if(l[i]!=1)
		{
			printf("-1");
			return 0;
		}
		else l[i]=0;
	}
	int j;
	int m=0;
	for(int i=0;i<n;i++)
	{
		if(!b[i])
		{
			j=i;
			m=1;
			b[j]=true;
			j=crush[j];
			while(j!=i)
			{
				b[j]=true;
				j=crush[j];
				m++;
			}
			//cout<<m<<endl;
			if(m%2!=0) a.push_back(m);
			else a.push_back(m/2);
			/*if(m%2==0) c.push_back(m/2);
			else 
			{
				if(m!=1) imp=true;
			}*/
		}
		
	}
	int r;
	for(int i=0;i<a.size();i++)
	{
		m=a[i];
		r=m;
		j=2;
		int k=0;
		while(j<m)
		{
			k=0;
			while(r%j==0)
			{
				r=r/j;
				k++;
			}
			if(k>l[j]) l[j]=k;
			j++;
		}
		if(r>1) 
		{
			if(1>l[r]) l[r]=1;
		}
	}
	int k1,k2,res1=1,res2=1;
	for(int j=0;j<500;j++)
	{
		if(l[j]>0)
		{
			k1=j;
			k2=l[j];
			res1=res1*pow(k1,k2);
		}
		l[j]=0;
	}
	cout<<res1<<endl;
	return 0;
}