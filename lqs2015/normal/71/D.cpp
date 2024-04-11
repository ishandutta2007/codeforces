#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
#include<cstring>
using namespace std;
int n,m,x,y,cnt,ct[22];
bool is[15][11],joker[5],f1,f2;
pair<int,int> a[55][55],pos[5],xp,yp;
string s;
char aa[55],bb[55];
bool can(int i,int j)
{
	bool f=0;
	for (int k=i;k<=i+2;k++)
	{
		for (int h=j;h<=j+2;h++)
		{
			if (a[k][h].second!=a[i][j].second)
			{
				f=1;
				break;
			}
		}
		if (f) break;
	}
	if (!f) return 1;
	memset(ct,0,sizeof(ct));
	for (int k=i;k<=i+2;k++)
	{
		for (int h=j;h<=j+2;h++)
		{
			ct[a[k][h].first]++;
		}
	}
	f=0;
	for (int i=2;i<=14;i++)
	{
		if (ct[i]>1)
		{
			f=1;
			break;
		}
	}
	if (!f) return 1;
	return 0;
}
int main()
{
	aa[2]='2';aa[3]='3';aa[4]='4';aa[5]='5';aa[6]='6';aa[7]='7';aa[8]='8';
	aa[9]='9';aa[10]='T';aa[11]='J';aa[12]='Q';aa[13]='K';aa[14]='A';
	bb[1]='C';bb[2]='D';bb[3]='H';bb[4]='S';
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			cin>>s;
			if (s[0]>='0' && s[0]<='9') x=s[0]-'0';
			else if (s[0]=='T') x=10;
			else if (s[0]=='J') x=11;
			else if (s[0]=='Q') x=12;
			else if (s[0]=='K') x=13;
			else x=14;
			if (s[1]>='1' && s[1]<='2') 
			{
				joker[s[1]-'0']=1;
				pos[s[1]-'0']=make_pair(i,j);
				y=4+s[1]-'0';
				cnt++;
			}
			else if (s[1]=='C') y=1;
			else if (s[1]=='D') y=2;
			else if (s[1]=='H') y=3;
			else y=4;
			is[x][y]=1;
			a[i][j]=make_pair(x,y);
		}
	}
	if (!cnt)
	{
		for (int i=1;i<=n-2;i++)
		{
			for (int j=1;j<=m-2;j++)
			{
				for (int k=i;k<=n-2;k++)
				{
					for (int h=1;h<=m-2;h++)
					{
						if (k-i<3 && h-j<3) continue;
						if (can(i,j) && can(k,h))
						{
							printf("Solution exists.\n");
							printf("There are no jokers.\n");
							printf("Put the first square to (%d, %d).\n",i,j);
							printf("Put the second square to (%d, %d).\n",k,h);
							return 0;
						}
					}
				}
			}
		}
	}
	else if (cnt==1)
	{
		for (int s=2;s<=14;s++)
		{
			for (int t=1;t<=4;t++)
			{
				if (is[s][t]) continue;
				for (int i=1;i<=n;i++)
				{
					for (int j=1;j<=m;j++)
					{
						if (a[i][j].second>4)
						{
							xp=a[i][j];
							a[i][j]=make_pair(s,t);
						}
					}
				}
				for (int i=1;i<=n-2;i++)
				{
					for (int j=1;j<=m-2;j++)
					{
						for (int k=i;k<=n-2;k++)
						{
							for (int h=1;h<=m-2;h++)
							{
								if (k-i<3 && h-j<3) continue;
								if (can(i,j) && can(k,h))
								{
									printf("Solution exists.\n");
									printf("Replace J%d with %c%c.\n",pos[1].first ? 1 : 2,aa[s],bb[t]);
									printf("Put the first square to (%d, %d).\n",i,j);
									printf("Put the second square to (%d, %d).\n",k,h);
									return 0;
								}
							}
						}
					}
				}
				for (int i=1;i<=n;i++)
				{
					for (int j=1;j<=m;j++)
					{
						if (a[i][j]==make_pair(s,t))
						{
							a[i][j]=xp;
						}
					}
				}
			}
		}
	}
	else
	{
		for (int s=2;s<=14;s++)
		{
			for (int t=1;t<=4;t++)
			{
				for (int ss=2;ss<=14;ss++)
				{
					for (int tt=1;tt<=4;tt++)
					{
						if (is[s][t] || is[ss][tt] || (s==ss && t==tt)) continue;
						for (int i=1;i<=n;i++)
						{
							for (int j=1;j<=m;j++)
							{
								if (a[i][j].second==5) 
								{
									a[i][j]=make_pair(s,t);
								}
								if (a[i][j].second==6)
								{
									a[i][j]=make_pair(ss,tt);
								}
							}
						}
						for (int i=1;i<=n-2;i++)
						{
							for (int j=1;j<=m-2;j++)
							{
								for (int k=i;k<=n-2;k++)
								{
									for (int h=1;h<=m-2;h++)
									{
										if (k-i<3 && h-j<3) continue;
										if (can(i,j) && can(k,h))
										{
											printf("Solution exists.\n");
											printf("Replace J1 with %c%c and J2 with %c%c.\n",aa[s],bb[t],aa[ss],bb[tt]);
											printf("Put the first square to (%d, %d).\n",i,j);
											printf("Put the second square to (%d, %d).\n",k,h);
											return 0;
										}
									}
								}
							}
						}
						for (int i=1;i<=n;i++)
						{
							for (int j=1;j<=m;j++)
							{
								if (a[i][j]==make_pair(s,t)) 
								{
									a[i][j]=make_pair(11,5);
								}
								if (a[i][j]==make_pair(ss,tt))
								{
									a[i][j]=make_pair(11,6);
								}
							}
						}
					}
				}
			}
		}
	}
	printf("No solution.\n");
	return 0;
}