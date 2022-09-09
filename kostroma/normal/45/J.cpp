#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <string>
#include <math.h>
#include <memory.h>
#include <utility>
using namespace std;
int a[150][150];
int t=1,n,m,i,j;
int main()
{
	scanf ("%d%d", &n,&m);
	if (n>=5)
			for(i=0;i<m;i++)
			{
				for(j=0;j<(n+1)/2;j++)
					{
					a[j][i]=t;
					a[(n+1)/2+j][i]=t+1;
					t=t+2;
					}
			if (n%2==1)
				t--;
			}
	else
		if(m>=5)
		for(i=0;i<n;i++)
		{
			for(j=0;j<(m+1)/2;j++)
				{
				a[i][j]=t;
				a[i][(m+1)/2+j]=t+1;
				t=t+2;
				}
			if (m%2==1)
				t--;
		}
		else
			if(m==1 && n==1)
			{
				printf("1");
				return 0;
			}
			else
				if(m==3 && n==2)
				{
					printf("3 6 2\n5 1 4");
					return 0;
				}
				else
					if(m==2 && n==3)
					{
						printf("3 5\n6 1\n2 4");
						return 0;
					}
					else
						if(m==3 &&n==3)
						{
							printf("2 5 7\n4 1 3\n8 6 9");
							return 0;
						}
						else
							if(m==4&&n==1)
							{
								printf("3 1 4 2");
								return 0;
							}
							else
								if(m==1&&n==4)
								{
									printf("3\n1\n4\n2");
									return 0;
								}
								else
									if ((n==1 && m==2) || (n==1 && m==3) || (n==3 && m==1) || (n==2 && m==1) || (n==2 && m==2))
									{
										printf("-1");
										return 0;
									}
									else
										if(n==2&&m==4)
										{
											printf("1 5 2 7\n3 8 6 4");
										return 0;
										}
										else
											if(n==4&&m==2)
											{
											printf("1 3\n5 8\n2 6\n7 4");
											return 0;
											}
											else 
												if(n==3 && m==4)
												{
													printf("3 1 4 2\n7 5 8 6\n11 9 12 10");
													return 0;
												}
												else
													if(n==4 && m==3)
													{
														printf("3 7 11\n1 5 9\n4 8 12\n2 6 10");
														return 0;
													}
													else
														if(n==4 && m==4)
														{
														printf("3 1 4 2\n7 5 8 6\n11 9 12 10\n15 13 16 14");
														return 0;
														}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}


	return 0;
}