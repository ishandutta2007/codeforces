#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

const int INF=1000000000;

int n;
int a[200010];

int m;
char s[30];

int F[21][1<<20];

void init()
{
	cin>>n;
	for (int i=1;i<=n;++i)
	{
		scanf("%s",s);
		m=strlen(s);
		for (int j=0;j<m;++j)
			a[i]=(a[i]<<1)+s[j]-'0';
	}
	for (int i=0;i<=m;++i)
		for (int j=0;j<(1<<m);++j)
			F[i][j]=INF;
	F[0][0]=0;
}

void work()
{
	int ans=m;
	for (int i=2;i<=n;++i)
	{
		int len;
		for (len=m;;--len)
			if ((a[i-1]&((1<<len)-1))==a[i]>>(m-len)) break;
		len=m-len;
		ans+=len;
		int get=INF;
		for (int j=0;j<=m;++j)
			get=min(get,F[j][a[i]>>(m-j)]+m-j);
		for (int j=0;j<=m;++j)
			F[j][a[i-1]&((1<<j)-1)]=min(F[j][a[i-1]&((1<<j)-1)],get-len);
	}
	int get=0;
	for (int i=0;i<=m;++i)
		for (int j=0;j<(1<<m);++j)
			get=min(get,F[i][j]);
	cout<<ans+get<<endl;
}

int main()
{
	init();
	work();
	return 0;
}