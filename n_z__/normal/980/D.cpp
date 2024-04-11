#include<bits/stdc++.h>
using namespace std;
#define int long long
int Fa[5001];
inline int Find(int X)
{
    return X==Fa[X]?X:Fa[X]=Find(Fa[X]);
}
inline void Merge(int X,int Y)
{
    Fa[Find(X)]=Find(Y);
}
inline bool Check(int X,int Y)
{
    return Find(X)==Find(Y);
}
inline void Init(int n)
{
	for(int x=1;x<=n;x++)
	Fa[x]=x;
}
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
int a[5001];
bool b[5001];
int ans[5001];
inline void bcj()
{
	int n=Read();
    Init(n);
    for(int x=1;x<=n;x++)
    a[x]=Read();
    for(int x=1;x<=n;x++)
    for(int y=1;y<x;y++)
    if(a[x]*a[y]>0&&a[x]*a[y]==(int)(sqrt(a[x]*a[y]))*(int)(sqrt(a[x]*a[y])))Merge(x,y);
    for(int y=1;y<=n;y++)
    {
        memset(b,0,sizeof(b));
        int sum=0;
        for(int x=y;x<=n;x++)
        if(a[x]){
            if(!b[Fa[x]])b[Fa[x]]=true,sum++;
            ++ans[sum];
        }
        else ++ans[max(sum,1ll)];
    }
    for(int x=1;x<=n;x++)
    cout<<ans[x]<<' ';
}
main()
{
	bcj();
}