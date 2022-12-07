#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
#define inf 99999999
#define pi acos(-1.0)
long double cal(long double a,long double n)
{
    long double R,alpha,h;
    alpha=pi/n;
    R=a/(sin(alpha)*2);
    h=sqrt(a*a-R*R);
    return h*n*a*a/(12*tan(alpha));
}


int main()
{
    int i,j;
    long double l[6];
    while(cin>>l[3]>>l[4]>>l[5])
    {
        long double sum=0;
        for(i=3;i<=5;i++){
            sum+=cal(l[i],i);
        }
        printf("%.15f\n",(double)sum);
    }
    return 0;
}