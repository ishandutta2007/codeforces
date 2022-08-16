#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<string>
#include<bitset>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<iomanip>

using namespace std;

typedef long long int64;
typedef long double real;
typedef pair<int,int> pii;

#define X first
#define Y second

const int MaxN=100010;

int F[40][20][3000];

int n;
char s[MaxN];
int v[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

bool p(char x)
{
	return '0'<=x&&x<='9';
}

int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for (int i=1;i+9<=n;++i)
	{
		if (p(s[i])&&p(s[i+1])&&p(s[i+3])&&p(s[i+4])&&p(s[i+6])&&p(s[i+7])&&p(s[i+8])&&p(s[i+9]))
			if (s[i+2]=='-'&&s[i+5]=='-')
			{
				int dd=(s[i]-'0')*10+s[i+1]-'0';
				int mm=(s[i+3]-'0')*10+s[i+4]-'0';
				int yy=0;
				for (int k=6;k<=9;++k)
					yy=yy*10+s[i+k]-'0';
				if (dd<=33&&mm<=12&&yy<=2100) ++F[dd][mm][yy];
			}
	}
	int T=0;
	int dd,mm,yy;
	for (int y=2013;y<=2015;++y)
		for (int m=1;m<=12;++m)
			for (int d=1;d<=v[m];++d)
			{
				if (F[d][m][y]>T)
				{
					dd=d;
					mm=m;
					yy=y;
					T=F[d][m][y];
				}
			}
	printf("%02d-%02d-%04d\n",dd,mm,yy);
	return 0;
}