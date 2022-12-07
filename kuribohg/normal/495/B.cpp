#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
int a,b,k,ans;
int main()
{
    scanf("%d%d",&a,&b);
    k=a-b;
    if(k==0) puts("infinity");
    else if(k<0) puts("0");
    else
    {
        for(int i=1;i*i<=k;i++)
            if(k%i==0)
            {
                if(i>b) ans++;
                if(i*i!=k&&k/i>b) ans++;
            }
        printf("%d\n",ans);
    }
    return 0;
}