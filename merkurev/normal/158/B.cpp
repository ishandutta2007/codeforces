#include <iostream>
using namespace std;

int q[5];

void main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        q[x]++;
    }
    int res=q[4];
    res+=(q[2]>>1);
    q[2]&=1;
    res+=q[3];
    q[1]-=q[3];
    if (q[2])
    {
        res++;
        q[1]-=2;
    }
    if (q[1]<0)
        q[1]=0;
    res+=(q[1]+3)/4;
    printf("%d",res);

}