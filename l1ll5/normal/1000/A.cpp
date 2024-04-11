#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 1005
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n;
char s[N][10],t[N][10];
int S[5],L[5],M[5];
int ans;
int main()
{
    n=read();
    for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
    for(int i=1;i<=n;i++)scanf("%s",t[i]+1);

    for(int i=1;i<=n;i++)
    {
        if(s[i][strlen(s[i]+1)]=='S')S[strlen(s[i]+1)]++;
        if(s[i][strlen(s[i]+1)]=='M')M[strlen(s[i]+1)]++;
        if(s[i][strlen(s[i]+1)]=='L')L[strlen(s[i]+1)]++;
    }

    for(int i=1;i<=n;i++)
    {
        if(t[i][strlen(t[i]+1)]=='S')S[strlen(t[i]+1)]--;
        if(t[i][strlen(t[i]+1)]=='M')M[strlen(t[i]+1)]--;
        if(t[i][strlen(t[i]+1)]=='L')L[strlen(t[i]+1)]--;
    }
    for(int i=1;i<=4;i++)
    {
        ans+=(abs(S[i])+abs(M[i])+abs(L[i]))/2;
    }
    cout<<ans<<endl;
}