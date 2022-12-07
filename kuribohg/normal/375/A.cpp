#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a[10],l,con,p[5],M[10],ok;
char str[2000010],ans[2000010];
int main()
{
	scanf("%s",str);
	int len=strlen(str);
	for(int i=0;i<len;i++) a[str[i]-'0']++;
	a[1]--,a[6]--,a[8]--,a[9]--;
	if(a[0])
	{
		for(int i=1;i<=9;i++)
			if(a[i]) ok=true;
	}
	else ok=true;
	if(!ok)
	{
		printf("%d",1869);
		for(int i=1;i<=a[0];i++) putchar('0');
		puts("");
		return 0;
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=a[i];j++)
			ans[l++]=i+'0',con=(con*10+i)%7;
	}
	con=con*10000%7;
	p[1]=1,p[2]=6,p[3]=8,p[4]=9;
	do
	{
		int res=0;
		for(int i=1;i<=4;i++)
			res=res*10+p[i];
		M[res%7]=res;
	}while(next_permutation(p+1,p+5));
	for(int i=0;i<l;i++) putchar(ans[i]);
	M[7]=M[0];
	printf("%d\n",M[7-con]);
	return 0;
}