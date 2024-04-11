#include<bits/stdc++.h>
using namespace std;
int k1,k2,k3;
int main()
{
    cin>>k1>>k2>>k3;
    if(k1==1 || k2==1 || k3==1)
    {
        printf("YES");
        return 0;
    }
    if(k1==3 && k2==3 && k3==3)
    {
        printf("YES");
        return 0;
    }
    if((k1==2 && k2==2) || (k1==2 && k3==2) || (k2==2 && k3==2))
    {
        printf("YES");
        return 0;
    }
    if(k1==2 && k2==4 && k3==4)
    {
        printf("YES");
        return 0;
    }if(k2==2 && k1==4 && k3==4)
    {
        printf("YES");
        return 0;
    }
    if(k3==2 && k2==4 && k1==4)
    {
        printf("YES");
        return 0;
    }
    printf("NO");
    return 0;
}