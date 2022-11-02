#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 100010
#define ll long long
using namespace std;
inline ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
ll bin[N];
int n;
char saa[100]="What are you doing while sending \"";
char sbb[100]="\"? Are you busy? Will you send \"";
char scc[100]="\"?";
char sss[100]="What are you doing at the end of the world? Are you busy? Will you save us?";
char dot='.';
char get(ll x,ll y)
{

	if(x==0)
    {
		if(y>bin[0])return dot;
		return sss[y-1];
	}

    if(x>53)
    {
        if(y<=34)return saa[y-1];
        return get(x-1,y-34);
    }

	if(y>bin[x])return dot;

    int opt=(y<=34)+(y<=34+bin[x-1])+(y<=34+bin[x-1]+32)+(y<=34+bin[x-1]+32+bin[x-1])+1;

    switch(opt)
    {
        case 5:return saa[y-1];
        case 4:return get(x-1,y-34);
        case 3:return sbb[y-34-bin[x-1]-1];
        case 2:return get(x-1,y-34-bin[x-1]-32);
        case 1:return scc[y-34-bin[x-1]-32-bin[x-1]-1];
    }
}
ll x,y,m;
int main()
{
	bin[0]=75;
	for(int i=1;i<=53;i++)bin[i]=(bin[i-1]<<1)+68;

	m=read();
	while(m--)
    {
		x=read(),y=read();
		putchar(get(x,y));
	}
	return 0;
}
//aaaaaaaaaaaaaaaaaaaaaaaooooooooooooooooooooooooooooaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaao