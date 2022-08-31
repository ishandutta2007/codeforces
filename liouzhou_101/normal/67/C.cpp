#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

const int MaxN=4010;
const int INF=1000000000;

int ti,td,tr,te;
int n,m;
char s[MaxN],t[MaxN];
int F[MaxN][MaxN];
int ps[26],pt[26];

int main()
{
	cin>>ti>>td>>tr>>te;
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1);
	m=strlen(t+1);
	for (int i=0;i<=n;++i)
		for (int j=0;j<=m;++j)
			F[i][j]=INF;
	F[0][0]=0;
	for (int i=1;i<=n;++i)
		F[i][0]=i*td;
	for (int j=1;j<=m;++j)
		F[0][j]=j*ti;
	for (int i=1;i<=n;++i)
	{
		for (int j=0;j<26;++j)
			pt[j]=0;
		for (int j=1;j<=m;++j)
		{
			F[i][j]=min(F[i][j],min(F[i-1][j]+td,F[i][j-1]+ti));
			F[i][j]=min(F[i][j],(s[i]==t[j])?F[i-1][j-1]:F[i-1][j-1]+tr);
			int xs=pt[s[i]-'a'],xt=ps[t[j]-'a'];
			if (xs&&xt)
				F[i][j]=min(F[i][j],F[xt-1][xs-1]+te+(i-xt-1)*td+(j-xs-1)*ti);
			pt[t[j]-'a']=j;
		}
		ps[s[i]-'a']=i;
	}
	cout<<F[n][m]<<endl;
	return 0;
}