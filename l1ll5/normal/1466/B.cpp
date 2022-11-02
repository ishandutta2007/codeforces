#include <bits/stdc++.h>
#define N 400005
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
int x[N];
int bin[N];
int f[N],g[N];
int main()
{
    T=read();
    while(T--){
        n=read();
        for(int i=1;i<=n;i++) x[i]=read();
        for(int i=1;i<=n;i++) bin[x[i]]++;
        for(int i=1;i<=2*n;i++) bin[i] = min(bin[i],2);
        int ans=0;
        for(int i=1;i<=2*n+5;i++)
        {
            bin[i]=min(bin[i],2);
            if(bin[i]==1) {
                ans++;
            } else if(bin[i]==2) {
                ans++;
                bin[i+1]++;
            }
        }
        for(int i=1;i<=2*n+5;i++) bin[i]=0;
        printf("%d\n",ans);
    }
}