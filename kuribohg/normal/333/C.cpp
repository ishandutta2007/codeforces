#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
using namespace std;
int k,m,last[100010],now;
void DFS(int n,int res,int num)
{
	if(n>4) return;
	if(n==4)
	{
		int o=abs(res-k);
		if(o<10000&&last[o]!=now)
		{
			last[o]=now;
			printf("%04d%04d\n",now,o);
			m--;
			if(m==0) exit(0);
		}
		return;
	}
	DFS(n+1,res+(num%10),num/10);
	DFS(n+1,res-(num%10),num/10);
	DFS(n+1,res*(num%10),num/10);
	DFS(n+2,res+(num%100),num/100);
	DFS(n+2,res-(num%100),num/100);
	DFS(n+2,res*(num%100),num/100);
}
int main()
{
	scanf("%d%d",&k,&m);
	memset(last,-1,sizeof(last));
	for(int i=0;i<10000;i++)
	{
		now=i;
		DFS(1,i%10,i/10);
		DFS(2,i%100,i/100);
		DFS(3,i%1000,i/1000);
	}
	return 0;
}