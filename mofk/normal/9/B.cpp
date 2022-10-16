#include<stdio.h>
#include<math.h>
int main(void)
{
    int n,vb,vs,i,ans=2;
    long int x[105],xu,yu;
    double min,dmin;
    scanf("%d%d%d",&n,&vb,&vs);
    for(i=1;i<=n;i++) scanf("%ld",&x[i]);
    scanf("%ld%ld",&xu,&yu);
    min=(double)x[2]/vb+sqrt(pow((xu-x[2]),2)+pow(yu,2))/vs;
    dmin=sqrt(pow((xu-x[2]),2)+pow(yu,2));
    for(i=3;i<=n;i++)
    {
        if((double)x[i]/vb+sqrt(pow((xu-x[i]),2)+pow(yu,2))/vs<min||((double)x[i]/vb+sqrt(pow((xu-x[i]),2)+pow(yu,2))/vs==min&&sqrt(pow((xu-x[i]),2)+pow(yu,2))<dmin))
        {
            min=(double)x[i]/vb+sqrt(pow((xu-x[i]),2)+pow(yu,2))/vs;
            ans=i;
            dmin=sqrt(pow((xu-x[i]),2)+pow(yu,2));
        }
    }
    printf("%d",ans);
}