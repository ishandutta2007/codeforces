#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

const long double ZERO=1e-10;

int n;
int v[110],x[110],y[110];
char s[110][4];

int hL,hR,get,ans;
int used[110];

bool find(char c,long double px)
{
	for (int i=1;i<=n;++i)
		if (!used[i]&&s[i][0]==c)
			if (x[i]<=px+ZERO&&px-ZERO<=y[i])
			{
				used[i]=1;
				get+=v[i];
				return true;
			}
	return false;
}

void check1(int k)
{
	get=0;
	long double tg=(long double)1e5/(hL+hR+200*k);
	memset(used,0,sizeof(used));
	long double px=hL*tg;
	for (int i=1;i<=2*k+1;++i)
	{
		if (i&1)
		{
			if (!find('F',px)) return;
		}
		else
		{
			if (!find('T',px)) return;
		}
		px+=100*tg;
	}
	ans=max(ans,get);
}

void check2(int k)
{
	get=0;
	long double tg=(long double)1e5/(hL-hR+100*(2*k+2));
	memset(used,0,sizeof(used));
	long double px=hL*tg;
	for (int i=1;i<=2*k+2;++i)
	{
		if (i&1)
		{
			if (!find('F',px)) return;
		}
		else
		{
			if (!find('T',px)) return;
		}
		px+=100*tg;
	}
	ans=max(ans,get);
}

int main()
{
	cin>>hL>>hR>>n;
	for (int i=1;i<=n;++i)
		scanf("%d%s%d%d",&v[i],s[i],&x[i],&y[i]);
	for (int i=0;i<=n/2+1;++i)
	{
		check1(i);
		check2(i);
	}
	for (int i=1;i<=n;++i)
		if (s[i][0]=='T') s[i][0]='F';
			else s[i][0]='T';
	hL=100-hL;
	hR=100-hR;
	for (int i=0;i<=n/2+1;++i)
	{
		check1(i);
		check2(i);
	}
	cout<<ans<<endl;
	return 0;
}