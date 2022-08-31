#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;


int k,x,n,m;

long long arr[100];


void check(int i,int j,int x1,int x2,int y1,int y2)
{
	string s1,s2;
	
	if (n==1)
		goto n1;
	if (i<n/2)
	{
		s1=x1+'A';
		for (int ii=0;ii<i;ii++)
			s1+="AC";
		for (int ii=i*2+1;ii<n-1;ii++)
			s1+="B";
		s1+=x2+'A';
	}
	else
	{
		if (n==2*i)
		{
			if (x2-x1!=2)
				return;
			else
			{
				s1="";
				for (int ii=0;ii<i;ii++)
					s1+="AC";
			}
		}
		else
		{
			s1="";
			if (x1==0)
			{
				for (int ii=0;ii<i;ii++)
					s1+="AC";
				s1+=x2+'A';
			}
			else
			{
				s1=x1+'A';
				if (x2==2)
				{
					for (int ii=0;ii<i;ii++)
						s1+="AC";
				}
				else
					return;
			}
		}
	}
	
	n1:
	if (n==1)
		s1=x1+'A';
	
	
	if (m==1)
		goto m1;
	
	if (j<m/2)
	{
		s2=y1+'A';
		for (int ii=0;ii<j;ii++)
			s2+="AC";
		for (int ii=j*2+1;ii<m-1;ii++)
			s2+="B";
		s2+=y2+'A';
	}
	else
	{
		if (m==2*j)
		{
			if (y2-y1!=2)
				return;
			else
			{
				s2="";
				for (int ii=0;ii<j;ii++)
					s2+="AC";
			}
		}
		else
		{
			s2="";
			if (y1==0)
			{
				for (int ii=0;ii<j;ii++)
					s2+="AC";
				s2+=y2+'A';
			}
			else
			{
				s2=y1+'A';
				if (y2==2)
				{
					for (int ii=0;ii<j;ii++)
						s2+="AC";
				}
				else
					return;
			}
		}
	}
	
	m1:
	if (m==1)
		s2=y1+'A';
			
	cout<<s1<<"\n"<<s2;
	exit(0);
	
}



int main()
{
	cin>>k>>x>>n>>m;
	for (int i=0;i<=n/2;i++)
	{
		for (int j=0;j<=m/2;j++)
		{
			for (int x1=0;x1<3;x1++)
				for (int x2=0;x2<3;x2++)
					for (int y1=0;y1<3;y1++)
						for (int y2=0;y2<3;y2++)
						{
							if (x1!=x2 && n==1)
								continue;
							if (y1!=y2 && m==1)
								continue;
						arr[0]=i;
						arr[1]=j;
						for (int ii=2;ii<k;ii++)
						{
							arr[ii]=arr[ii-1]+arr[ii-2];
							if (ii==2 && y1-x2==2)
							{
								arr[ii]++;
							}
							if (ii>2 && ii%2==1 && x1-y2==2)
							{
								arr[ii]++;
							}
							if (ii>2 && ii%2==0 && y1-y2==2)
							{
								arr[ii]++;
							}
							if (arr[ii]>x)
							{
								arr[k-1]=-1;
								break;
							}
						}
						if (arr[k-1]==x)
						{
							//cout<<x1<<" "<<x2<<" "<<y1<<" "<<y2<<" "<<i<<" "<<j<<"\n";
							check(i,j,x1,x2,y1,y2);
						}
						}
		}
	}
	cout<<"Happy new year!";
}