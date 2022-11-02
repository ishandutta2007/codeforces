#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 110
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m;
char s[N];
int main()
{
    n=read(),m=read();
    scanf("%s",s+1);
    while(m--)
    {
        int l=read(),r=read();
        char f,t;
        f=getchar();
        getchar();
        t=getchar();
        for(int i=l;i<=r;i++)
        if(s[i]==f)s[i]=t;
    }
    printf("%s",s+1);
}