#include <bits/stdc++.h>
using namespace std;
int n,m;
int k;
int l,p;
bool s;
vector<int> a;
int main()
{
	scanf("%d %d",&n,&m);
	if(n>4 || m>4)
	{
		printf("YES\n");
		if(m>4)
		{
		if(m%2!=0) k=2;
		else
		{
			if(m%3!=0) k=3;
			else
			{
				if(m%5!=0) k=5;
				else
				{
					if(m%7!=0) k=7;
					else
					{
						if(m%11!=0) k=11;
						else
						{
							if(m%13!=0) k=13;
							else
							{
								if(m%17!=0) k=17;
								else k=19;
							}
						}
					}
				}
			}
		}
			
		l=1;
		if(m==6) k=2;
		for(int i=0;i<n;i++)
		{
			if(m==6) k=2;
			for(int j=0;j<m;j++)
			{
				a.push_back(l);
				l=l+k;
				if(l-i*m>m) l=l-m;
				if(m==6 && l==a[a.size()-3])
				{
					//k++;
					l++;
				}
				//cout<<l<<endl;
			}
			//if(m==6) k=2;
			l=l+m;
			l=l+k;
			if(l-(i+1)*m>m) l=l-m;
			if(m==6 && i%3==0) l++;
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++) printf("%d ",a[i*m+j]);
			printf("\n");
		}
		}
		else
		{
			if(n%2!=0) k=2;
		else
		{
			if(n%3!=0) k=3;
			else
			{
				if(n%5!=0) k=5;
				else
				{
					if(n%7!=0) k=7;
					else
					{
						if(n%11!=0) k=11;
						else
						{
							if(n%13!=0) k=13;
							else
							{
								if(n%17!=0) k=17;
								else k=19;
							}
						}
					}
				}
			}
			
		
		}
		l=1;
		//cout<<k<<" "<<l<<endl;
		for(int j=0;j<m;j++)
		{
			if(n==6) k=2;
			for(int i=0;i<n;i++)
			{
				a.push_back(l);
				l=l+k*m;
				if(l>m*n) l=l-m*n;
				if(n==6 && l==a[a.size()-3])
				{
					//k++;
					l++;
				}
			}
			//if(n==6) k=2;
			l++;
			l=l+k*m;
			if(l>m*n) l=l-m*n;
			if(n==6 && j%3==0) l++;
		}
		for(int i=0;i<n;i++) 
		{
			//cout<<a[i]<<" ";
			for(int j=0;j<m;j++) printf("%d ",a[i+j*n]);
			printf("\n");
		}
		}
	}
	else
	{
		if(n==1)
		{
			if(m==1)
			{
				printf("YES\n1");
				return 0;
			}
			if(m<=3)
			{
				printf("NO");
				return 0;
			}
			else
			{
				printf("YES\n");
				printf("2 4 1 3");
				return 0;
			}
		}
		if(n==2)
		{
			if(m<=3)
			{
				printf("NO");
				return 0;
			}
			if(m==4)
			{
				printf("YES\n");
				printf("5 4 7 2\n");
				printf("3 6 1 8");
				return 0;
			}
		}
		if(n==3)
		{
			if(m<=2)
			{
				printf("NO");
				return 0;
			}
			if(m==3)
			{
				printf("YES\n");
				printf("6 1 8\n");
				printf("7 5 3\n");
				printf("2 9 4");
				return 0;
			}
			if(m==4)
			{
				printf("YES\n");
				printf("1 6 11 2\n");
				printf("7 12 3 8\n");
				printf("9 4 5 10");
				return 0;
			}
		}
		if(n==4)
		{
			if(m==1)
			{
				printf("YES\n");
				printf("2\n4\n1\n3");
				return 0;
			}
			if(m==2)
			{
				printf("YES\n");
				printf("3 6\n");
				printf("7 2\n");
				printf("1 8\n");
				printf("5 4");
				return 0;
			}
			if(m==3)
			{
				printf("YES\n");
				printf("7 5 9\n");
				printf("1 11 3\n");
				printf("10 2 12\n");
				printf("4 8 6");
				return 0;
			}
			if(m==4)
			{
				printf("YES\n");
				printf("2 4 1 3\n");
				printf("7 5 6 8\n");
				printf("10 12 9 11\n");
				printf("15 13 16 14");
				return 0;
			}
		}
	}
	return 0;
}