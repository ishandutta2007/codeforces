#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

const int MaxN=1010;

int n,m;
char s[MaxN][MaxN],t[MaxN][MaxN];
vector<int> X,Y;

void deal(vector<int> &v)
{
	vector<int> w=v;
	v.clear();
	v.push_back(w[0]);
	v.push_back(w[1]);
	v.push_back(w[w.size()-1]);
	v.push_back(w[w.size()-2]);
}

void init()
{
	cin>>n>>m;
	for (int i=1;i<=n;++i)
		scanf("%s",s[i]+1);
	for (int i=1;i<=n;++i)
	{
		int p=0;
		for (int j=3;j<=m;++j)
			if (s[i][j-2]=='#'&&s[i][j-1]=='#'&&s[i][j]=='#') p=1;
		if (p) X.push_back(i);
	}
	if (X.size()>4) deal(X);
	for (int j=1;j<=m;++j)
	{
		int p=0;
		for (int i=3;i<=n;++i)
			if (s[i-2][j]=='#'&&s[i-1][j]=='#'&&s[i][j]=='#') p=1;
		if (p) Y.push_back(j);
	}
	if (Y.size()>4) deal(Y);
}

#define travel(X,x1,x2) \
	for (int x1=0;x1<X.size();++x1) \
		for (int x2=x1+1;x2<X.size();++x2) if (X[x2]-X[x1]>1)

void add(int x1,int x2,int y1,int y2)
{
	for (int i=x1;i<=x2;++i)
		t[i][y1]=t[i][y2]='#';
	for (int j=y1;j<=y2;++j)
		t[x1][j]=t[x2][j]='#';
}

void work()
{
	travel(X,x1,x2)travel(Y,y1,y2)
	travel(X,x3,x4)travel(Y,y3,y4)
	{
		for (int i=1;i<=n;++i)
			for (int j=1;j<=m;++j)
				t[i][j]='.';
		add(X[x1],X[x2],Y[y1],Y[y2]);
		add(X[x3],X[x4],Y[y3],Y[y4]);
		int flag=0;
		for (int i=1;i<=n;++i)
			for (int j=1;j<=m;++j)
				if (s[i][j]!=t[i][j]) flag=1;
		if (!flag)
		{
			puts("YES");
			printf("%d %d %d %d\n%d %d %d %d\n",X[x1],Y[y1],X[x2],Y[y2],X[x3],Y[y3],X[x4],Y[y4]);
			return;
		}
	}
	puts("NO");
}

int main()
{
	init();
	work();
	return 0;
}