#include<bits/stdc++.h>
using namespace std;
#define maxm 5000000
int ck[maxm+1],pe[maxm+1];
inline int Read()
{
    register int Flag;
    register char C;
    register int X=0;
    Flag=1,C=getchar();
    while(!isdigit(C))
    {
        if(C=='-')
        {
            Flag=-1;
        }
        C=getchar();
    }
    while(isdigit(C))
    {
        X=(X<<1)+(X<<3)+C-'0';
        C=getchar();
    }
    return X*Flag;
}
inline void Write(int X)
{
    if(X<0)
    {
        X=-X;
        putchar('-');
    }
    if(X>9)
    {
        Write(X/10);
    }
    putchar(X%10^48);
}
int pre[5000001];
int main()
{
	register int n=5000000;
	ck[1]=-1;
	register int sum=0;
	for(register int x=2;x<=n;x++)
	{
		if(!ck[x])pe[++sum]=x;
		for(register int j=1;j<=sum&&x*pe[j]<=n;j++)
		{
			ck[x*pe[j]]=ck[x]+1;
			if(x%pe[j]==0)break;
		}
	}
    for(int x=1;x<=n;x++)
    pre[x]=pre[x-1]+ck[x]+1;
    /*for(int x=1;x<=100;x++)cout<<ck[x]+1<<' ';cout<<endl;
    for(int x=1;x<=100;x++)cout<<pre[x]<<' ';cout<<endl;*/
    int q=Read();
	for(register int x=1;x<=q;x++)
	{
	    register int l,r;
		r=Read(),l=Read();
		Write(pre[r]-pre[l]);
		puts("");
	}
}