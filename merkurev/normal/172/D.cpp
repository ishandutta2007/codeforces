#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int q[10050000];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    
    int a,n;
    scanf("%d%d",&n,&a);

    for (int i=1;i*i<=n+a;i++)
    {
        register int cur=i*i;
        register int x=cur;
        while (cur<=n+a)
        {
            q[cur]=x;
            cur+=x;
        }
    }
    long long ans=0;
    for (int i=n;i<n+a;i++)
        ans+=i/q[i];
    printf("%I64d",ans);

    
    return 0;
}