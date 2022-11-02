#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int a[3];
        scanf("%d%d%d",&a[0],&a[1],&a[2]);
        sort(a,a+3,greater<int>());
        if(a[0]!=a[1])
            printf("NO\n");
        else
            printf("YES\n %d %d %d\n",a[0],a[2],1);
    }
    return 0;
}