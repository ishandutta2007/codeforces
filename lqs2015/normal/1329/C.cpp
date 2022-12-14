#include<bits/stdc++.h>
using namespace std;
const int maxn=1000,mod=998244353;
char buffer[maxn],*S,*T;
inline char Get_Char()
{
    if(S==T)
    {
        T=(S=buffer)+fread(buffer,1,maxn,stdin);
        if(S==T) return EOF;
    }
    return *S++;
}
int read()
{
    char c;
    int re=0,f=0;
    for(c=Get_Char();c<'0'||c>'9';c=Get_Char())
    {
    	if (c=='-') f=1;
	}
    while(c>='0'&&c<='9')
           re=re*10+(c&15),c=Get_Char();
    if (f) return -re;
    return re;
}
int test,h,g,n,m,val[4444444],dep[4444444],pos,lst,ans[4444444];
long long res;
bool check(int pos)
{
	while(val[pos<<1] || val[(pos<<1)|1])
	{
		if (val[pos<<1]>val[(pos<<1)|1])
		{
			pos<<=1;
		}
		else 
		{
			pos=(pos<<1)|1;
		}
	}
	return (dep[pos]>g);
}
void era(int pos,int id)
{
	ans[id]=pos;res-=val[pos];
	while(val[pos<<1] || val[(pos<<1)|1])
	{
		if (val[pos<<1]>val[(pos<<1)|1])
		{
			val[pos]=val[pos<<1];
			pos<<=1;
		}
		else 
		{
			val[pos]=val[(pos<<1)|1];
			pos=(pos<<1)|1;
		}
	}
	val[pos]=0;
}
int main()
{
	test=read();
	while(test--)
	{
		h=read();g=read();
		n=(1<<h)-1;m=(1<<g)-1;
		for (int i=1;i<=2*n+1;i++) val[i]=0;
		for (int i=1;i<=n;i++) val[i]=read();
		res=0;
		dep[1]=1;
		for (int i=2;i<=n;i++) dep[i]=dep[i>>1]+1;
		for (int i=1;i<=n;i++) 
		{
			res+=val[i];
		}
		pos=1;
		for (int i=1;i<=n-m;i++)
		{
			while(pos<=n && !check(pos)) pos++;
			era(pos,i);
		}
		printf("%lld\n",res);
		for (int i=1;i<=n-m;i++) printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}