#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
int n;
char name[110][110];
int p[110],m[110],a[110],b[110],c[110],d[110],e[110];
int score[110],maxnum=-1000000000,maxsub;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%s%d%d%d%d%d%d%d",name[i],&p[i],&m[i],&a[i],&b[i],&c[i],&d[i],&e[i]);
	for(int i=1;i<=n;i++) score[i]=p[i]*100-m[i]*50+a[i]+b[i]+c[i]+d[i]+e[i];
	for(int i=1;i<=n;i++) if(score[i]>maxnum) maxnum=score[i],maxsub=i;
	puts(name[maxsub]);
	return 0;
}