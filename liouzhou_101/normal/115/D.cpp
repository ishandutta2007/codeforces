#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

const int MaxN=2010;
const int MOD=1000003;

int n;
char s[MaxN];
int F[MaxN][MaxN];

int main()
{
	cin>>s+1;
	n=strlen(s+1);
	F[0][0]=1;
	for (int i=1;i<=n;++i)
		if ('0'<=s[i]&&s[i]<='9')
		{
			if (s[i-1]=='+'||s[i-1]=='-'||s[i-1]=='*'||s[i-1]=='/')
			{
				for (int j=n;j>=0;--j)
					F[i][j]=(F[i-1][j]+F[i][j+1])%MOD;
			}
			else
			{
				for (int j=0;j<=n;++j)
					F[i][j]=F[i-1][j];
			}
		}
		else
		{
			if ((s[i]=='*'||s[i]=='/')&&!('0'<=s[i-1]&&s[i-1]<='9'))
			{
				puts("0");
				return 0;
			}
			for (int j=n;j>=0;--j)
				F[i][j+1]=F[i-1][j];
			F[i][0]=0;
		}
	cout<<F[n][0]<<endl;
	return 0;
}