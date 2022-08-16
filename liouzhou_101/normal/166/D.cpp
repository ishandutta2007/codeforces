#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

const int MaxN=100010;

int n,m,sum;

long long F[MaxN][2][2];
int from[MaxN][2][2][3],used[MaxN][2][2];

struct node
{
	int c,s,p;
}A[MaxN],B[MaxN];

bool cmp(node A,node B)
{
	return A.s>B.s||(A.s==B.s&&A.c>B.c);
}

void init()
{
	cin>>n;
	for (int i=1;i<=n;++i)
	{
		scanf("%d%d",&A[i].c,&A[i].s);
		A[i].p=i;
	}
	cin>>m;
	for (int i=1;i<=m;++i)
	{
		scanf("%d%d",&B[i].c,&B[i].s);
		B[i].p=i;
	}
	sort(A+1,A+n+1,cmp);
	sort(B+1,B+m+1,cmp);
}

void add(int i,int x,int y,int p1,int p2,int p3)
{
	from[i][x][y][0]=p1;
	from[i][x][y][1]=p2;
	from[i][x][y][2]=p3;
}

void travel(int p1,int p2,int p3,int flag)
{
	if (!p1&&!p2&&!p3) return;
	if (used[p1][p2][p3])
	{
		if (!flag)
			++sum;
		else
			printf("%d %d\n",B[p1].p,A[used[p1][p2][p3]].p);
	}
	travel(from[p1][p2][p3][0],from[p1][p2][p3][1],from[p1][p2][p3][2],flag);
}

void work()
{
	long long ans=0;
	int p1=0,p2=0,p3=0;
	int j=1;
	for (int i=1;i<=m;++i)
	{
		while (A[j].s>B[i].s)
		{
			++j;
			if (j>n) break;
		}
		if (B[i-1].s==B[i].s)
		{
			F[i][0][0]=F[i-1][0][0];add(i,0,0,i-1,0,0);
			F[i][0][1]=F[i-1][0][1];add(i,0,1,i-1,0,1);
			F[i][1][0]=F[i-1][1][0];add(i,1,0,i-1,1,0);
			F[i][1][1]=F[i-1][1][1];add(i,1,1,i-1,1,1);
			if (B[i].c>=A[j-1].c&&A[j-1].s==B[i].s+1)
			{
				if (F[i][0][1]<F[i-1][0][0]+A[j-1].c)
				{
					F[i][0][1]=F[i-1][0][0]+A[j-1].c;
					used[i][0][1]=j-1;
					add(i,0,1,i-1,0,0);
				}
				if (F[i][1][1]<F[i-1][1][0]+A[j-1].c)
				{
					F[i][1][1]=F[i-1][1][0]+A[j-1].c;
					used[i][1][1]=j-1;
					add(i,1,1,i-1,1,0);
				}
			}
			if (B[i].c>=A[j].c&&A[j].s==B[i].s)
			{
				if (F[i][1][0]<F[i-1][0][0]+A[j].c)
				{
					F[i][1][0]=F[i-1][0][0]+A[j].c;
					used[i][1][0]=j;
					add(i,1,0,i-1,0,0);
				}
				if (F[i][1][1]<F[i-1][0][1]+A[j].c)
				{
					F[i][1][1]=F[i-1][0][1]+A[j].c;
					used[i][1][1]=j;
					add(i,1,1,i-1,0,1);
				}
			}
		}
		else if (B[i-1].s==B[i].s+1)
		{
			if (F[i-1][0][0]>F[i-1][0][1])
			{
				F[i][0][0]=F[i-1][0][0];
				add(i,0,0,i-1,0,0);
			}
			else
			{
				F[i][0][0]=F[i-1][0][1];
				add(i,0,0,i-1,0,1);
			}
			if (F[i-1][1][0]>F[i-1][1][1])
			{
				F[i][0][1]=F[i-1][1][0];
				add(i,0,1,i-1,1,0);
			}
			else
			{
				F[i][0][1]=F[i-1][1][1];
				add(i,0,1,i-1,1,1);
			}
			if (B[i].c>=A[j-1].c&&A[j-1].s==B[i].s+1)
			{
				if (F[i][0][1]<max(F[i-1][0][0],F[i-1][0][1])+A[j-1].c)
				{
					if (F[i][0][1]<F[i-1][0][0]+A[j-1].c)
					{
						F[i][0][1]=F[i-1][0][0]+A[j-1].c;
						used[i][0][1]=j-1;
						add(i,0,1,i-1,0,0);
					}
					if (F[i][0][1]<F[i-1][0][1]+A[j-1].c)
					{
						F[i][0][1]=F[i-1][0][1]+A[j-1].c;
						used[i][0][1]=j-1;
						add(i,0,1,i-1,0,1);
					}
				}
			}
			if (B[i].c>=A[j].c&&A[j].s==B[i].s)
			{
				if (F[i][1][0]<max(F[i-1][0][0],F[i-1][0][1])+A[j].c)
				{
					if (F[i][1][0]<F[i-1][0][0]+A[j].c)
					{
						F[i][1][0]=F[i-1][0][0]+A[j].c;
						used[i][1][0]=j;
						add(i,1,0,i-1,0,0);
					}
					if (F[i][1][0]<F[i-1][0][1]+A[j].c)
					{
						F[i][1][0]=F[i-1][0][1]+A[j].c;
						used[i][1][0]=j;
						add(i,1,0,i-1,0,1);
					}
				}
				if (F[i][1][1]<max(F[i-1][1][0],F[i-1][1][1])+A[j].c)
				{
					if (F[i][1][1]<F[i-1][1][0]+A[j].c)
					{
						F[i][1][1]=F[i-1][1][0]+A[j].c;
						used[i][1][1]=j;
						add(i,1,1,i-1,1,0);
					}
					if (F[i][1][1]<F[i-1][1][1]+A[j].c)
					{
						F[i][1][1]=F[i-1][1][1]+A[j].c;
						used[i][1][1]=j;
						add(i,1,1,i-1,1,1);
					}
				}
			}
		}
		else
		{
			for (int x=0;x<2;++x) for (int y=0;y<2;++y)
				if (F[i][0][0]<F[i-1][x][y])
				{
					F[i][0][0]=F[i-1][x][y];
					add(i,0,0,i-1,x,y);
				}
			if (B[i].c>=A[j-1].c&&A[j-1].s==B[i].s+1)
			{
				if (F[i][0][1]<F[i][0][0]+A[j-1].c)
				{
					F[i][0][1]=F[i][0][0]+A[j-1].c;
					used[i][0][1]=j-1;
					add(i,0,1,i,0,0);
				}
			}
			if (B[i].c>=A[j].c&&A[j].s==B[i].s)
			{
				if (F[i][1][0]<F[i][0][0]+A[j].c)
				{
					F[i][1][0]=F[i][0][0]+A[j].c;
					used[i][1][0]=j;
					add(i,1,0,i,0,0);
				}
			}
		}
		for (int x=0;x<2;++x) for (int y=0;y<2;++y)
			if (ans<F[i][x][y])
			{
				ans=F[i][x][y];
				p1=i;
				p2=x;
				p3=y;
			}
	}
	cout<<ans<<endl;
	sum=0;
	travel(p1,p2,p3,0);
	cout<<sum<<endl;
	travel(p1,p2,p3,1);
}

int main()
{
	init();
	work();
	return 0;
}