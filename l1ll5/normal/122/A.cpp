#include <bits/stdc++.h>
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
int lucky[N]={4,7,44,47,74,77,444,447,474,477,744,747,774,777};
int main()
{
    int n=read();
    bool flg=0;
    for(int i=0;i<=13;i++)
    {
        if(n==lucky[i]||n%lucky[i]==0)
        {
            flg=true;
            break;
        }
    }
    if(flg)puts("YES");
    else puts("NO");
}