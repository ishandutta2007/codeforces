#include <bits/stdc++.h>
using namespace std;
#define N 100005
int lA,nxt[N],ans[N];bool vs[N];char a[N];
int main()
{
    scanf("%s",a+1),lA=strlen(a+1);
    for(int i=2,t=0;i<=lA;++i)
    {
        while(t && a[i]!=a[t+1]) t=nxt[t];
        if(a[i]==a[t+1]) ++t;nxt[i]=t;
    }
    for(int i=lA;i;i=nxt[i]) vs[i]=1,++ans[0];printf("%d\n",ans[0]);
    for(int i=1;i<=lA;++i) ++ans[i];for(int i=lA;i>=1;--i) ans[nxt[i]]+=ans[i];
    for(int i=1;i<=lA;++i) if(vs[i]) printf("%d %d\n",i,ans[i]);
}