#include <iostream>
using namespace std;

int q[150];

void main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int n,k;
    scanf("%d%d",&n,&k);
    for (int i=0;i<n;i++)
    {
        scanf("%d",&q[i]);
    }
    int res=0;
    for (int i=0;i<n;i++)
        if (q[i]>=q[k-1] && q[i]>0)
            res++;
    printf("%d",res);
}