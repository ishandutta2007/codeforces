#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,k,f[5010][5010];
char str[5010];
int getf(int l,int r)
{
	if(f[l][r]!=-1) return f[l][r];
	if(r-l<=3)
	{
		if(str[l]==str[r]) return f[l][r]=1;
		else return f[l][r]=0;
	}
	if(str[l]!=str[r]) return f[l][r]=0;
	f[l][r]=getf(l+2,r-2);
	return f[l][r];
}
struct Trie
{
	int ch[2];
	int size,dat;
}T[5010*5010];
int root=1,tot=1;
void Insert(int st)
{
	int x=root;
	for(int i=st;i<=n;i++)
	{
		int o=str[i]-'a';
		if(!T[x].ch[o]) T[x].ch[o]=++tot;
		x=T[x].ch[o];
		if(getf(st,i)) T[x].dat++;
	}
}
int Len;
char ans[5010];
int main()
{
	scanf("%s%d",str+1,&k);
	n=strlen(str+1);
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			f[i][j]=-1;
	for(int i=1;i<=n;i++) Insert(i);
	for(int i=tot;i>=1;i--)
	{
		T[i].size=T[i].dat;
		if(T[i].ch[0]) T[i].size+=T[T[i].ch[0]].size;
		if(T[i].ch[1]) T[i].size+=T[T[i].ch[1]].size;
	}
	int x=root;
	while(true)
	{
		if(k<=T[x].dat) break;
		k-=T[x].dat;
		if(k<=T[T[x].ch[0]].size) ans[Len++]='a',x=T[x].ch[0];
		else k-=T[T[x].ch[0]].size,ans[Len++]='b',x=T[x].ch[1];
	}
	puts(ans);
	return 0;
}