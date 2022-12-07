#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
char a[100010],tmp;
int n,k,p;
char add(int x)
{
	for(char i=a[x]+1;i<k+'a';i++)
		if(i!=a[x-1]&&i!=a[x-2]) return i;
	return 0;
}
int main()
{
	scanf("%d%d%s",&n,&k,a);
	for(p=n-1;p>=0;p--)
	{
		tmp=add(p);
		if(tmp) {a[p]=tmp;break;}
	}
	if(p==-1) {puts("NO");return 0;}
	for(int i=p+1;i<n;i++)
	{
		a[i]='a'-1;
		tmp=add(i);
		if(tmp) a[i]=tmp;
	}
	printf("%s\n",a);
	return 0;
}