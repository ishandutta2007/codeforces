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
int t;
int n;
int a[N];
int f[N],g[N];
int stk[N],top;
int main()
{
    t=read();
    while(t--)
    {
        n=read();
        for(int i=1;i<=n;i++) a[i]=read();
        top=0;
        f[1]=a[1];
        stk[++top]=a[1];
        for(int i=2;i<=n;i++)
        {
            while(top && a[i]>stk[top]) top--;
            if(top==0) top++;
            else stk[++top]=a[i];

            if(top==1) f[i]=stk[top];
            else f[i]=n+1;
        }
        top=0;
        stk[++top]=a[n];
        g[n]=a[n];
        for(int i=n-1;i>=1;i--)
        {
            while(top && a[i]<stk[top]) top--;
            if(top==0) top++;
            else stk[++top]=a[i];

            if(top==1) g[i]=stk[top];
            else g[i]=0;
        }

        /*for(int i=1;i<=n;i++) {
            cout<<f[i]<<' '<<g[i]<<endl;
        }
*/
        int ok=0;
        for(int i=1;i<=n-1;i++)
        {
            if(f[i]<g[i+1])
            {
                ok=1;
            }
        }
        if(ok) puts("YES");
        else puts("NO");
    }
}