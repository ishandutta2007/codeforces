#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,l,v1,v2,k;
double c;
int main()
{
    scanf("%d%d%d%d%d",&n,&l,&v1,&v2,&k);
    int t=(n+k-1)/k;
    c+=t;
    c+=1.0*(t-1)*(v2-v1)/(v2+v1);
    c+=v2*1.0/v1-1;
    double x=l*1.0/v1/c;
    printf("%.010lf\n",l*1.0/v1-(v2*1.0/v1-1)*x);
    return 0;
}