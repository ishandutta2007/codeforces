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
int a[N];
char s[N];
int main()
{

    T=read();
    while(T--){
        n=read();
        for(int i=1;i<=n;i++) a[i]=i;
        for(int i=1;i<=n;i++) printf("%d ",a[i]);
        puts("");
    }
}