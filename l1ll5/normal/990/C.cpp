#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 300005
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
int a[N],b[N],c[N],zer;
int stk[N],top;
ll ans;
int main()
{
    n=read();
    for(int i=1;i<=n;i++)
    {
        scanf("%s",s+1);m=strlen(s+1);
        for(int j=1;j<=m;j++)
        c[j]=(s[j]-'(');
        top=0;
        for(int j=1;j<=m;j++)
        {
            stk[++top]=c[j];
            if(top>1&&stk[top]==1&&stk[top-1]==0)top-=2;
        }
        int le=0,ri=0;
        for(int j=1;j<=top;j++)
        if(stk[j]==0)le++;
        else ri++;
        if(le&&ri)continue ;
        if(le)a[le]++;
        else if(ri)b[ri]++;
        if(!le&&!ri)zer++;

    }
    for(int i=1;i<=N-5;i++)ans+=1ll*a[i]*b[i];
    ans+=1ll*zer*zer;
    cout<<ans<<endl;
}