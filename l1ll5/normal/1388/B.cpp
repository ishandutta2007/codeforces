#include <bits/stdc++.h>
#define N 200005
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int T;
int n;



int main()
{
    T=read();
    while(T--)
    {
        n=read();
        int ei=(n-1)/4+1;
        int ni=n-ei;

        for(int i=1;i<=ni;i++) putchar('9');
        for(int i=1;i<=ei;i++) putchar('8');
        puts("");
    }
}