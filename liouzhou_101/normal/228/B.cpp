#include<cstdio>
#include<iostream>

using namespace std;

struct
{
	int n,m;
	int a[110][110];
	void init()
	{
		cin>>n>>m;
		char s[110];
		for (int i=1;i<=n;++i)
		{
			cin>>s+1;
			for (int j=1;j<=m;++j)
				a[i][j]=s[j]-'0';
		}
	}
}T[2];

int calc(int x,int y)
{
	int get=0;
	for (int i=1;i<=T[0].n;++i)
		for (int j=1;j<=T[0].m;++j)
		{
			int tx=i+x,ty=j+y;
			if (tx>=1&&tx<=T[1].n&&ty>=1&&ty<=T[1].m)
				get+=T[0].a[i][j]*T[1].a[tx][ty];
		}
	return get;
}

void init()
{
	for (int k=0;k<2;++k)
		T[k].init();
	int ax=0,ay=0,most=0;
	for (int i=-50;i<=50;++i)
		for (int j=-50;j<=50;++j)
		{
			int get=calc(i,j);
			if (get>most)
			{
				most=get;
				ax=i;
				ay=j;
			}
		}
	cout<<ax<<" "<<ay<<endl;
}

int main()
{
	init();
	return 0;
}