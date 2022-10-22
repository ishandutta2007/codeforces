#include <bits/stdc++.h>
using namespace std;
#define N 1000005
#define max(x,y) ((x)>(y)?(x):(y))
int lA,ans,nxt[N];bool vs[N];char a[N];
int main()
{
    scanf("%s",a+1);lA=strlen(a+1);
    for(int i=2,t=0;i<=lA;++i)
    {
        while(t && a[t+1]!=a[i]) t=nxt[t];
        if(a[t+1]==a[i]) ++t;nxt[i]=t;
    }
    for(int i=nxt[lA];i;i=nxt[i]) vs[i]=1;
    for(int i=1;i<lA;++i) if(vs[nxt[i]]) ans=max(ans,nxt[i]);
    if(ans) for(int i=1;i<=ans;++i) printf("%c",a[i]);else puts("Just a legend");
}