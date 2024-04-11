#include<bits/stdc++.h>
using namespace std;
int Fa[2][10001];
inline int Find(int op,int X)
{
    return X==Fa[op][X]?X:Fa[op][X]=Find(op,Fa[op][X]);
}
inline void Merge(int op,int X,int Y)
{
    Fa[op][Find(op,X)]=Find(op,Y);
}
inline bool Check(int op,int X,int Y)
{
    return Find(op,X)==Find(op,Y);
}
inline void Init(int n)
{
	for(int x=1;x<=n;x++)
	Fa[0][x]=Fa[1][x]=x;
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
pair<int,int>aans[100001];
inline void bcj()
{
	int n=Read(),m1=Read(),m2=Read();
    Init(n);
    for(int x=1;x<=m1;++x)
	{
		int b=Read(),c=Read();
        Merge(0,b,c);
    }
    for(int x=1;x<=m2;++x)
	{
		int b=Read(),c=Read();
        Merge(1,b,c);
    }
    int ans=0;
    for(int x=1;x<=n;x++)
    for(int y=x+1;y<=n;y++)
    if(Check(0,x,y)==false&&Check(1,x,y)==false)ans++,aans[ans]=make_pair(x,y),Merge(0,x,y),Merge(1,x,y);
    cout<<ans<<endl;
    for(int x=1;x<=ans;x++)
    cout<<aans[x].first<<' '<<aans[x].second<<endl;
}
int main()
{
	bcj();
}