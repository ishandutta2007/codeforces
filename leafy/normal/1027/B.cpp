#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
ll n;int q;
int main()
{
    scanf("%I64d%d",&n,&q);
    while(q--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if((x+y)&1) 
        {
            if(n&1)
            {
                if(x&1) printf("%I64d\n",n*n/2+1+n*(x-1)/2+(y+1)/2);
                else printf("%I64d\n",n*n/2+n*(x-2)/2+(n+1)/2+(y+1)/2);
            }
            else printf("%I64d\n",n*n/2+(n/2)*(x-1)+(y+1)/2);
        }
        else 
        {
            if(n&1)
            {
                if(x&1) printf("%I64d\n",n*(x-1)/2+(y+1)/2);
                else printf("%I64d\n",n*(x-2)/2+(n+1)/2+(y+1)/2);
            }
            else printf("%I64d\n",(n/2)*(x-1)+(y+1)/2);
        }
    }
    return 0;
}