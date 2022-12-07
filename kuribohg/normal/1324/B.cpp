#include<iostream>
#include<cstdio>
using namespace std;
int T,n,a[100010];
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        bool ok=false;
        for(int i=1;i<=n;i++)
            for(int j=i+2;j<=n;j++)
                if(a[i]==a[j]) ok=true;
        if(ok) puts("YES");
        else puts("NO");
    }
    return 0;
}