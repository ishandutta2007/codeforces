#include<iostream>
#include<cstdio>
using namespace std;
int T,n,a[110];
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        bool ok=true;
        for(int i=2;i<=n;i++)
            if((a[i]&1)!=(a[1]&1)) ok=false;
        if(ok) puts("YES");
        else puts("NO");
    }
    return 0;
}