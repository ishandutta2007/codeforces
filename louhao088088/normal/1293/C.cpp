#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0;char ch=getchar();bool f=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
int n,q,num=0,a,b;
bool flag[300005][3];
int main()
{
	memset(flag,0,sizeof flag);
	n=read();q=read();
	for(int i=1;i<=q;i++)
	{
		a=read(),b=read();a=a-1;
		flag[b][a]=abs(flag[b][a]-1);
		if(flag[b][a]==0&&flag[b][abs(a-1)]==1)num--;
		if(flag[b][a]==0&&flag[b-1][abs(a-1)]==1)num--;
		if(flag[b][a]==0&&flag[b+1][abs(a-1)]==1)num--;
		if(flag[b][a]==1&&flag[b][abs(a-1)]==1)num++;
		if(flag[b][a]==1&&flag[b-1][abs(a-1)]==1)num++;
		if(flag[b][a]==1&&flag[b+1][abs(a-1)]==1)num++;
		if(num>0)puts("No");
		else puts("Yes");
	}	
	return 0;
}