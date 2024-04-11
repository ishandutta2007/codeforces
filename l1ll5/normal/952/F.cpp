#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 100000
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
char s[N];
ll x,ans,f=1;
int main()
{
    scanf("%s",s+1);
    n=strlen(s+1);
    for(int i=1;i<=n;i++)
    {
        char ch=s[i];
        if(ch>='0'&&ch<='9')
        {
            while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=s[++i];}
            ans+=x*f;
            if(ch=='+')f=1;
            else f=-1;
            x=ch-'0';
        }
    }
    cout<<ans<<endl;
}