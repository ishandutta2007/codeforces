#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,x,y;
scanf("%i",&n);
long long x_sum=0,x_sum_squared=0;
long long y_sum=0,y_sum_squared=0;
for(int i=1;i<=n;i++)
{
    scanf("%i%i",&x,&y);
    x_sum+=x;
    x_sum_squared+=x*x;

    y_sum+=y;
    y_sum_squared+=y*y;
}
long long answer=2*n*x_sum_squared-2*x_sum*x_sum+2*n*y_sum_squared-2*y_sum*y_sum;
printf("%lld\n",answer/2);
return 0;
}