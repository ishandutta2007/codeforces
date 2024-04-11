#include<bits/stdc++.h>
using namespace std;
int n,a[55][55],test,cur,match[111],pos[111];
pair<int,int> fuck[55][55];
bool f;
char opt[11];
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
		printf("B\n");
		fflush(stdout);
		scanf("%s %d",opt,&cur);
		if ((opt[0]=='D' && cur<=n) || (opt[0]=='I' && cur>n))
		{
			for (int i=1;i<=n;i++)
			{
				for (int j=1;j<=n;j++)
				fuck[i][j]=make_pair(a[i][j],j);
				sort(fuck[i]+1,fuck[i]+n+1);
				reverse(fuck[i]+1,fuck[i]+n+1);
			}
			for (int i=1;i<=n;i++) pos[i]=1;
			memset(match,-1,sizeof(match));
			while(1)
			{
				f=0;
				for (int i=1;i<=n;i++)
				{
					if (!~match[i])
					{
						f=1;
						while(pos[i]<=n)
						{
							int female=fuck[i][pos[i]].second;
							if (~match[female+n])
							{
								if (-a[match[female+n]][female]<-a[i][female]) 
								{
									match[match[female+n]]=-1;
									match[female+n]=i;match[i]=female+n;
									pos[i]++;break;
								}
							}
							else
							{
								match[female+n]=i;match[i]=female+n;
								pos[i]++;break;
							}
							pos[i]++;
						}
					}
				}
				if (!f) break;
			}
		}
		else
		{
			for (int i=1;i<=n;i++)
			{
				for (int j=1;j<=n;j++)
				a[i][j]=-a[i][j];
			}
			for (int i=1;i<=n;i++)
			{
				for (int j=1;j<=n;j++)
				fuck[i][j]=make_pair(a[i][j],j);
				sort(fuck[i]+1,fuck[i]+n+1);
				reverse(fuck[i]+1,fuck[i]+n+1);
			}
			for (int i=1;i<=n;i++) pos[i]=1;
			memset(match,-1,sizeof(match));
			while(1)
			{
				f=0;
				for (int i=1;i<=n;i++)
				{
					if (!~match[i])
					{
						f=1;
						while(pos[i]<=n)
						{
							int female=fuck[i][pos[i]].second;
							if (~match[female+n])
							{
								if (-a[match[female+n]][female]<-a[i][female]) 
								{
									match[match[female+n]]=-1;
									match[female+n]=i;match[i]=female+n;
									pos[i]++;break;
								}
							}
							else
							{
								match[female+n]=i;match[i]=female+n;
								pos[i]++;break;
							}
							pos[i]++;
						}
					}
				}
				if (!f) break;
			}
		}
	//	for (int i=1;i<=2*n;i++) cout<<match[i]<<" ";
	//	cout<<endl;
		while(1)
		{
			printf("%d\n",match[cur]);
			fflush(stdout);
			scanf("%d",&cur);
			if (cur<0) break;
		}
	}
	return 0;
}