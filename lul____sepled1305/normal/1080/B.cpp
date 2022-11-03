#include<bits/stdc++.h>
using namespace std;
int q,i,a,b;
int main()
{
    scanf("%d",&q);
    for(i=1;i<=q;i++)
    {
        scanf("%d%d",&a,&b);
        if(a%2==0 && b%2==0)
        {
            printf("%d\n",-((b-a)/2)+b);
        }
        else if(a%2==1 && b%2==0)
        {
            printf("%d\n",((b-a+1)/2));
        }
        else if(a%2==0 && b%2==1)
        {
            printf("%d\n",-((b-a+1)/2));
        }
        else if(a%2==1 && b%2==1)
        {
            printf("%d\n",((b-a)/2)-b);
        }
    }
    return 0;
}