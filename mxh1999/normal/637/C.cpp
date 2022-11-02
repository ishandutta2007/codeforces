//I hate you
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

void read(int &digit)
{
	digit=0;
	char c;
	for (c=getchar();(c<'0' || c>'9') && c!='-';c=getchar());
	bool type=false;
	if (c=='-')
		type=true,c=getchar();
	for (;c>='0' && c<='9';digit=digit*10+c-'0',c=getchar());
	if (type==true)
		digit=-digit;
}

#define maxn 1010
char s[maxn][10];
int n;
int ans=0;

int main()
{
	read(n);
	for (int i=1;i<=n;i++)	scanf("%s",s[i]);
	if (n==1)
	{
		printf("6\n");
		return 0;
	}
	ans=6;
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
		{
			int q=0;
			for (int k=0;k<=5;k++)
			if (s[i][k]!=s[j][k])	q++;
			ans=min(ans,(q-1)/2);
		}
	printf("%d\n",ans);
	return 0;
}